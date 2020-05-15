//
// Created by cesarnogueira on 5/13/20.
//

#ifndef FICHAJUNG_VEHICLE_H
#define FICHAJUNG_VEHICLE_H


#include "Node.h"
#include "Client.h"
#include "Algorithms.h"
class Vehicle {
    int id;
    vector<Node> path;
    vector<Client> clients;
    double CustoPath;
    string color;
    string colorVertex;
    vector<Node> best;
    int capacity;
    public:
        double getCustoPath();
        int getCapacity();
        string getColorVertex();
        Vehicle(int id, Client c,string color,string colorVertex);
        int getID();
        vector<Node> getPath();
        vector<Client> getClients();
        void addToPath(Node node, int index);
        void addClient(Client client);
        double testAddClient(Client client);
        string getColor();
};


#endif //FICHAJUNG_VEHICLE_H
