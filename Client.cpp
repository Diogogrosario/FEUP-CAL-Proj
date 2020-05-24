//
// Created by diogo on 12/05/20.
//

#include "Client.h"

#include <utility>

Client::Client() = default;

Client::Client(string name, int NIF, int nodeDestino, Time arrival) {
    this->name = std::move(name);
    this->NIF = NIF;
    this->nodeDestino = nodeDestino;
    this->arrival = arrival;
    this->delivered = false;
    this->needsDelivery = false;
}

