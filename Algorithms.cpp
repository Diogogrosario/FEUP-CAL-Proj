//
// Created by diogo on 12/05/20.
//

#include <iostream>
#include "Algorithms.h"
#include <algorithm>
#include "readFile.h"


extern Graph<Node> graph;

vector<Node> salesmanPath(vector<Client>clients){
    vector<Node> res;
    vector<Node> auxiliaryRes;
    Graph<Node> aux;
    Vertex<Node> *n;
    vector<int>salesman;


    for(Client c:clients){
        n = graph.findVertex(Node(c.nodeDestino,0,0));
        aux.addVertex(Node(n->getInfo().getID(),n->getInfo().getX(),n->getInfo().getY()));
    }
    for(auto ver:aux.getVertexSet()){
        for(auto ver2:aux.getVertexSet()){
            if(ver != ver2) {

                Node n1(ver->getInfo().getID(),ver->getInfo().getX(),ver->getInfo().getY());
                Node n2(ver2->getInfo().getID(),ver2->getInfo().getX(),ver2->getInfo().getY());
                graph.dijkstraShortestPath(n1);
                aux.addEdge(n1,n2,graph.findVertex(n2)->getDist());
            }
        }
    }

    //FINISHED BUILDING AUX GRAPH
    aux.floydWarshallShortestPath();

    for(int i = 0;i<aux.getDist().at(0).size();i++){
        if(i != 0){
            salesman.push_back(i);
        }
    }
    int index = 0;
    int cost = INT32_MAX;
    do{
        int path_cost = 0;
        auxiliaryRes.clear();
        int k = index;
        for(int i = 0;i<salesman.size();i++){
            path_cost += aux.getDist().at(k).at(salesman.at(i));
            auxiliaryRes.push_back(aux.getPred().at(k).at(salesman.at(i))->getInfo());
            k= salesman.at(i);
        }
        path_cost += aux.getDist().at(k).at(index);
        auxiliaryRes.push_back(aux.getPred().at(k).at(index)->getInfo());

        if(path_cost < cost){
            cost = path_cost;
            res.clear();
            res = auxiliaryRes;
        }

    }while(next_permutation(salesman.begin(),salesman.end()));

    cout << "cost" <<cost << endl;
    for(int i = 0; i< res.size();i++){
        cout << res.at(i).getID() << " ->";
    }

    return res;
}