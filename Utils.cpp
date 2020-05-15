//
// Created by cesarnogueira on 5/13/20.
//

#include "Utils.h"
#include <iostream>

using  namespace std;

void assignClients(vector<Vehicle>& vehicles, vector<Client>& clients) {
    double minCost = INT64_MAX;

    int index = 0;
    int counter = 0;
    vector<Vehicle>::iterator v;
    for(Client c: clients){
        for(v = vehicles.begin();v != vehicles.end();v++){
            double currentCost = v->testAddClient(c);
            cout << "vehicle at " << v->getID() << " costs aditional " << currentCost << endl << endl;
            if(currentCost < minCost) {
                minCost = currentCost;
                index = counter;
            }
            if(currentCost == minCost){
                if(v->getClients().size() < vehicles.at(index).getClients().size()){
                    index = counter;
                }
            }
            counter++;
        }
        vehicles.at(index).addClient(c);
        index = 0;
        counter = 0;
        minCost = INT64_MAX;
    }
}

