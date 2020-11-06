#include "Links/CompoMe/Posix/Https_server_map_in/Https_server_map_in.hpp"
#include "CompoMe/Log.hpp"
#include "Interfaces/Interface.hpp"

namespace CompoMe {

namespace Posix {

namespace  {
#if defined(COMPOME_LOG) && COMPOME_LOG
const char* mbedtls_error_wrp(int ret, char *buf=nullptr, size_t buflen=0) {
      static char l_buff[100];
      if (buf == nullptr) {
        buf = l_buff;
        buflen = 100;
      }
      mbedtls_strerror(ret, buf, buflen);
      return buf;
  }
#endif
  }

Https_server_map_in::Https_server_map_in() : CompoMe::Link() {
  mbedtls_net_init(&this->listen_fd);
  mbedtls_net_init(&this->client_fd);
  mbedtls_ssl_init(&this->ssl);
  mbedtls_ssl_config_init(&this->conf);
  mbedtls_x509_crt_init(&this->srvcert);
  mbedtls_pk_init(&this->pkey);
  mbedtls_entropy_init(&this->entropy);
  mbedtls_ctr_drbg_init(&this->ctr_drbg);
}

Https_server_map_in::~Https_server_map_in() {
  mbedtls_net_free(&this->client_fd);
  mbedtls_net_free(&this->listen_fd);
  mbedtls_x509_crt_free(&this->srvcert);
  mbedtls_pk_free(&this->pkey);
  mbedtls_ssl_free(&this->ssl);
  mbedtls_ssl_config_free(&this->conf);
  mbedtls_ctr_drbg_free(&this->ctr_drbg);
  mbedtls_entropy_free(&this->entropy);
}

void Https_server_map_in::step() {
  Link::step();
  int ret;
  unsigned char buf[1024];
  int len;

  ret = mbedtls_net_accept(&listen_fd, &client_fd, NULL, 0, NULL);
  if (ret != 0) {
    C_ERROR_TAG("https,accept", "accept on fd=",client_fd," ", mbedtls_error_wrp(ret));
  }

  mbedtls_ssl_set_bio(&ssl, &client_fd, mbedtls_net_send, mbedtls_net_recv,
                      NULL);

  while ((ret = mbedtls_ssl_handshake(&ssl)) != 0) {
    if (ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE) {
      C_ERROR_TAG("https,accept", " on fd=",client_fd," ", mbedtls_error_wrp(ret));
      return;
    }
  }

  do {
  len = sizeof(buf) - 1;
  memset(buf, 0, sizeof(buf));
    ret = mbedtls_ssl_read(&ssl, buf, len);

    if (ret == MBEDTLS_ERR_SSL_WANT_READ || ret == MBEDTLS_ERR_SSL_WANT_WRITE) {
      continue;
    }

    if (ret <= 0) {
      switch (ret) {
      case MBEDTLS_ERR_SSL_PEER_CLOSE_NOTIFY:
        break;

      case MBEDTLS_ERR_NET_CONN_RESET:
        break;

      default:
        break;
      }

      break;
    }

    len = ret;

    if (ret > 0)
      break;
  } while (1);


  len = sprintf((char *)buf, "lapin", mbedtls_ssl_get_ciphersuite(&ssl));
  while ((ret = mbedtls_ssl_write(&ssl, buf, len)) <= 0) {
    if (ret == MBEDTLS_ERR_NET_CONN_RESET) {
      //goto reset;
    }

    if (ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE) {
      //      goto exit;
    }
  }

  len = ret;

  while ((ret = mbedtls_ssl_close_notify(&ssl)) < 0) {
    if (ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE) {
      //goto reset;
    }
  }
}

void Https_server_map_in::connect() {
  Link::connect();
  int ret;

   // 1. Load the certificates and private RSA key
  ret = mbedtls_x509_crt_parse_file(&srvcert, this->get_cert_file().str.c_str());
  if (ret != 0) {
    C_ERROR_TAG("https,cert,file", "Cert file is not valid - ", mbedtls_error_wrp(ret));
    return;
  }

  ret = mbedtls_pk_parse_keyfile(&pkey, this->get_key_file().str.c_str(), NULL);
  if (ret != 0) {
    C_ERROR_TAG("https,key,file", "Key file is not valid - ", mbedtls_error_wrp(ret));
    return;
  }
  /*************************************************************************************/

  // 2. Setup the listening TCP socket
  ret = mbedtls_net_bind(&listen_fd, NULL, NULL,
                         MBEDTLS_NET_PROTO_TCP);
  if (ret != 0) {
    C_ERROR_TAG("https,bind", "bind failed - ", mbedtls_error_wrp(ret));
    return;
  }
  /*************************************************************************************/

  // 3. Seed the RNG
  const char *pers = "ssl_server";
  ret = mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy,
                              (const unsigned char *)pers,
                              strlen(pers));
  if (ret != 0) {
    C_ERROR_TAG("https,seed", "init seed - ", mbedtls_error_wrp(ret));
    return;
  }
  /*************************************************************************************/

  // 4. Setup stuff
  ret = mbedtls_ssl_config_defaults(&conf, MBEDTLS_SSL_IS_SERVER,
                                    MBEDTLS_SSL_TRANSPORT_STREAM,
                                    MBEDTLS_SSL_PRESET_DEFAULT);
  if (ret != 0) {
    C_ERROR_TAG("https,stuff", "ssl config default - ", mbedtls_error_wrp(ret));
    return;
  }

  mbedtls_ssl_conf_rng(&conf, mbedtls_ctr_drbg_random, &ctr_drbg);
  mbedtls_ssl_conf_ca_chain(&conf, srvcert.next, NULL);
  ret = mbedtls_ssl_conf_own_cert(&conf, &srvcert, &pkey);
  if (ret != 0) {
    C_ERROR_TAG("https,stuff", "ssl config cert - ", mbedtls_error_wrp(ret));
    return;
  }

  ret = mbedtls_ssl_setup(&ssl, &conf);
  if (ret != 0) {
    C_ERROR_TAG("https,stuff", "ssl setup - ", mbedtls_error_wrp(ret));
    return;
  }

}

void Https_server_map_in::disconnect() {
  Link::disconnect();

}

// Get and set /////////////////////////////////////////////////////////////

CompoMe::String Https_server_map_in::get_addr() const { return this->addr; }

void Https_server_map_in::set_addr(const CompoMe::String p_addr) {
  this->addr = p_addr;
}

CompoMe::String &Https_server_map_in::a_addr() { return this->addr; }
i32 Https_server_map_in::get_port() const { return this->port; }

void Https_server_map_in::set_port(const i32 p_port) { this->port = p_port; }

i32 &Https_server_map_in::a_port() { return this->port; }
ui32 Https_server_map_in::get_max_client() const { return this->max_client; }

void Https_server_map_in::set_max_client(const ui32 p_max_client) {
  this->max_client = p_max_client;
}

ui32 &Https_server_map_in::a_max_client() { return this->max_client; }
ui32 Https_server_map_in::get_max_request_size() const {
  return this->max_request_size;
}

void Https_server_map_in::set_max_request_size(const ui32 p_max_request_size) {
  this->max_request_size = p_max_request_size;
}

ui32 &Https_server_map_in::a_max_request_size() {
  return this->max_request_size;
}
CompoMe::String Https_server_map_in::get_cert_file() const {
  return this->cert_file;
}

void Https_server_map_in::set_cert_file(const CompoMe::String p_cert_file) {
  this->cert_file = p_cert_file;
}

CompoMe::String &Https_server_map_in::a_cert_file() { return this->cert_file; }
CompoMe::String Https_server_map_in::get_key_file() const {
  return this->key_file;
}

void Https_server_map_in::set_key_file(const CompoMe::String p_key_file) {
  this->key_file = p_key_file;
}

CompoMe::String &Https_server_map_in::a_key_file() { return this->key_file; }

} // namespace Posix

} // namespace CompoMe
