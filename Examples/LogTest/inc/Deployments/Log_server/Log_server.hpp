#pragma once

#include "Deployments/Deployment.hpp"

#include "Components/CompoMe/Log/Filter.hpp"

#include "Components/CompoMe/Log/To_File.hpp"

#include "Components/CompoMe/Log/To_CircularFile.hpp"

#include "connectors/CompoMe/Log/Distri_log.hpp"

#include "Links/CompoMe/Posix/Udp_server_in/Udp_server_in.hpp"

class Log_server : public CompoMe::Deployment {
private:
  // COMPONENT

  CompoMe::Log::Filter log_filer;

  CompoMe::Log::To_File file_saver;

  CompoMe::Log::To_CircularFile cir_file;

  // CONNECTOR

  CompoMe::Log::Distri_log distri;

  // DATA

  // LINK

  CompoMe::Posix::Udp_server_in s1;

public:
  Log_server();
  virtual ~Log_server();

  void init() override;
  void configuration() override;
  void link() override;
  void start() override;
  void stop() override;
  void quit() override;

  // GET //////////////////////////////////////////////////////////////////////
  // COMPONENT

  CompoMe::Log::Filter &get_log_filer();

  CompoMe::Log::To_File &get_file_saver();

  CompoMe::Log::To_CircularFile &get_cir_file();

  // CONNECTOR

  CompoMe::Log::Distri_log &get_distri();

  // LINK

  CompoMe::Posix::Udp_server_in &get_s1();
};
