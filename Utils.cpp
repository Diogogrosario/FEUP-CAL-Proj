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

    int index = 0;
    int counter = 0;
    vector<Vehicle>::iterator v;
    for(Client c: clients){
        for(v = vehicles.begin();v != vehicles.end();v++){
            if(v->getClients().size() < v->getCapacity()) {
                double currentCost = v->testAddClient(c);
                //cout << "vehicle at " << v->getID() << " costs aditional " << currentCost << endl << endl;
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
        index = 0;
        counter = 0;
        minCost = INT64_MAX;
    }

}

void showClientes(vector <Vehicle> v){
    for(Vehicle v2: v){
        for(Client c: v2.getClients()){
            if(c.name != "Admin")
                cout << "Client " << c.name << " travelling to node " << c.nodeDestino << endl;
        }
    }
}

void showPath(vector<Vehicle> v){
    for(auto v:graph.getVertexSet()){
        gv->setVertexColor(v->getInfo().getID(),BLUE);
    }
    for(Vehicle v2:v){
            paintPath(v2);
    }

}

void createClient(Client *add){
    string name;
    int NIF;
    int dest;
    string line;
    int hora, min;
    char trash;
    cout << "Enter name" << endl;
    cin >> name;
    add->name = name;
    cout << "Enter NIF" << endl;
    cin >> NIF;
    add->NIF = NIF;
    cout << "Enter destination node (Between 0 and 931 and != 230)" << endl;
    cin >> dest;
    add->nodeDestino = dest;
    cout << "Enter arrival time (Ex: 15:30)" << endl;
    getline(cin,line);
    istringstream linestream(line);
    linestream >> hora;
    linestream >> trash;
    linestream >> min;
    add->arrival = Time(hora,min);
    return;
}