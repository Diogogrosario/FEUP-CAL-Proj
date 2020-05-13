//
// Created by cesarnogueira on 5/13/20.
//

#include <iostream>
#include "Vehicle.h"

Vehicle::Vehicle(int id, Node n) {
    this->id = id;
    this->path.push_back(n);
    this->path.push_back(n);
}

int Vehicle::getID() {
    return id;
}

vector<Node> Vehicle::getPath() {
    return path;
}

vector<Client> Vehicle::getClients() {
    return clients;
}

void Vehicle::addToPath(Node node, int index) {

    if (index >= path.size()) {
        cout << "Invalid index!" << endl;
        return;
    }

    path.insert(path.begin() + index, node);
}

void Vehicle::addClient(Client client) {
    clients.push_back(client);
}

double Vehicle::testAddClient(Client client, int& bestNodeOrigin, int& bestNodeDestination) {
    // TODO
    return 0;
}
