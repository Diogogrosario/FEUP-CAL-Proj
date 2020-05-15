//
// Created by cesarnogueira on 5/13/20.
//

#include "Utils.h"

void assignClients(vector<Vehicle>& vehicles, vector<Client>& clients) {
    double minCost = INT64_MAX;

    int index = 0;
    int counter = 0;
    for(Client c: clients){
        for(Vehicle v: vehicles){
            double currentCost = v.testAddClient(c);
            if(currentCost < minCost) {
                minCost = currentCost;
                index = counter;
            }
            counter++;
        }
        vehicles.at(index).addClient(c);
        index = 0;
        counter = 0;
        minCost = INT64_MAX;
    }
}

