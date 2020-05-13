//
// Created by cesarnogueira on 5/13/20.
//

#ifndef FICHAJUNG_VEHICLE_H
#define FICHAJUNG_VEHICLE_H


#include "Node.h"
#include "Client.h"

class Vehicle {
    int id;
    vector<Node> path;
    vector<Client> clients;

    public:
        Vehicle(int id, Node n);
        int getID();
        vector<Node> getPath();
        vector<Client> getClients();
        void addToPath(Node node, int index);
        void addClient(Client client);
        double testAddClient(Client client, int& bestNodeOrigin, int& bestNodeDestination);
};


#endif //FICHAJUNG_VEHICLE_H
