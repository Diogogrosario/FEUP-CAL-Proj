//
// Created by cesarnogueira on 5/13/20.
//

#include "Utils.h"

void assignClients(vector<Vehicle> vehicles, vector<Client>& clients) {

    for (int i = 0; i < clients.size(); i++) {
        if (assignClientToVehicle(vehicles, clients.at(i))) {
            clients.erase(clients.begin() + i);
            i--;
        }
    }
}

bool assignClientToVehicle(vector<Vehicle>& vehicles, Client client) {
    // TODO
    for (auto v : vehicles) {

    }

    return true;
}
