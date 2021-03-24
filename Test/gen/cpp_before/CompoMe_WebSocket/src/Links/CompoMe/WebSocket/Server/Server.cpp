#include "Links/CompoMe/WebSocket/Server/Server.hpp"

#include "Interfaces/Interface.hpp"

namespace CompoMe {

namespace WebSocket {

Server::Server() : CompoMe::Link() {}

Server::~Server() {}

void Server::step() { Link::step(); }

void Server::connect() { Link::connect(); }

void Server::disconnect() { Link::disconnect(); }
void Server::connect(CompoMe::Require_helper &p_i) {}

void Server::disconnect(CompoMe::Require_helper &p_i) {}

} // namespace WebSocket

} // namespace CompoMe
