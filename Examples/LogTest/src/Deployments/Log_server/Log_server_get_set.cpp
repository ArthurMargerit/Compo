#include "Deployments/Log_server/Log_server.hpp"

// GET ////////////////////////////////////////////////////////////////////////
// COMPONENT

CompoMe::Log::Filter &Log_server::get_log_filer() { return this->log_filer; }

CompoMe::Log::To_File &Log_server::get_file_saver() { return this->file_saver; }

CompoMe::Log::To_CircularFile &Log_server::get_cir_file() {
  return this->cir_file;
}

// CONNECTOR

CompoMe::Log::Distri_log &Log_server::get_distri() { return this->distri; }

// LINK

CompoMe::Posix::Udp_server_in &Log_server::get_s1() { return this->s1; }
