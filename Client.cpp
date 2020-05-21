//
// Created by diogo on 12/05/20.
//

#include "Client.h"

Client::Client() {

}

Client::Client(string name, int NIF, int nodeDestino, Time arrival) {
    this->name = name;
    this->NIF = NIF;
    this->nodeDestino = nodeDestino;
    this->arrival = arrival;
    this->delivered = false;
    this->needsDelivery = false;
}

