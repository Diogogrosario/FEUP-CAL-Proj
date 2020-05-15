//
// Created by cesarnogueira on 5/13/20.
//

#include <iostream>
#include "Vehicle.h"
#include "readFile.h"

Vehicle::Vehicle(int id, Client c,string color) {
    this->id = id;
    this->clients.push_back(c);
    this->path.push_back(Node(c.nodeDestino,0,0));
    this->CustoPath = 0;
    this->color = color;
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
    cout << endl<<"inside add client " << endl;
    path = bestPath(clients);
    cout << endl;
    CustoPath = pathCost(path);
}

double Vehicle::testAddClient(Client client) {
    vector<Client> aux = this->clients;
    if(client.nodeDestino == clients.at(0).nodeDestino)
        return INT64_MAX;
    aux.push_back(client);
    cout << "testind adding client " << client.name << " to vehicle " << this->id << endl;

    vector<Node> best;
    best = bestPath(aux);
    double cost = pathCost(best);

    return cost - CustoPath;
}

double Vehicle::getCustoPath(){
    return this->CustoPath;
}

string Vehicle::getColor() {
    return this->color;
}
