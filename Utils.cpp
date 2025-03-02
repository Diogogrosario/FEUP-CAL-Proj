//
// Created by cesarnogueira on 5/13/20.
//

#include "Utils.h"
#include "readFile.h"
#include <iostream>
#include <graphviewer.h>
#include <sstream>


extern GraphViewer * gv;
extern Graph<Node> graph;

using  namespace std;

void assignClients(vector<Vehicle>& vehicles, vector<Client>& clients) {
    double minCost = INT64_MAX;
    int minTime = INT16_MAX;

    //GROUPING ALL CLIENTS WITH 1 HOUR DIFFERENCE
    for(Client &c:clients){
        if(!c.delivered) {
            if (c.arrival.hours * 60 + c.arrival.minutes < minTime) {
                minTime = c.arrival.hours * 60 + c.arrival.minutes;
            }
        }
    }

    for(Client &c:clients){
        if(c.arrival.hours*60+c.arrival.minutes <= minTime+60 && !c.delivered){
            c.needsDelivery = true;
        }
    }

    int index = 0;
    int counter = 0;
    vector<Vehicle>::iterator v;
    for(Client &c: clients){
        if(!c.delivered && c.needsDelivery) {
            for (v = vehicles.begin(); v != vehicles.end(); v++) {
                if (v->getClients().size() < v->getCapacity()) {
                    double currentCost = v->testAddClient(c); //TESTS ADDING CLIENT TO THE VEHICLE, TO SEE WHICH ONE IS THE MINIMUM COST
                    if (currentCost < minCost) {
                        minCost = currentCost;
                        index = counter;
                    }
                    if (currentCost == minCost) {
                        if (v->getClients().size() < vehicles.at(index).getClients().size()) {
                            index = counter;
                        }
                    }
                }
                counter++;
            }

            vehicles.at(index).addClient(c);
            c.delivered = true;
            c.needsDelivery = false;
        }
        index = 0;
        counter = 0;
        minCost = INT64_MAX;
    }

}

void showClientes(const vector <Vehicle>& v){
    for(Vehicle v2: v){
        for(const Client& c: v2.getClients()){
            if(c.name != "Admin")
                cout << "Client " << c.name  << " with NIF " << c.NIF << " travelling to node " << c.nodeDestino << endl;
        }
    }
    cout << endl;
}

void showPath(const vector<Vehicle>& v){
    for(auto vertex:graph.getVertexSet()){
        gv->setVertexColor(vertex->getInfo().getID(),BLUE);
    }
    for(Vehicle v2:v){
            paintPath(v2);
            cout << "Total cost of trip for vehicle " << v2.getID() << ": "<< v2.getCustoPath() << endl;
    }
    cout << endl;

}

void createClient(Client *add){
    string name;
    int NIF;
    int dest;
    string line;
    int hora, min;
    char trash;
    cout << "Enter name" << endl;
    cin.ignore(100,'\n');
    getline(cin,name);
    add->name = name;
    cout << "Enter NIF" << endl;
    cin >> NIF;
    add->NIF = NIF;
    cout << "Enter destination node (Between 0 and 931 and != 230)" << endl;
    cin >> dest;
    add->nodeDestino = dest;
    cout << "Enter arrival time (Ex: 15:30)" << endl;
    cin.ignore(100,'\n');
    getline(cin,line);
    istringstream linestream(line);
    linestream >> hora;
    linestream >> trash;
    linestream >> min;
    add->arrival = Time(hora,min);
}