//
// Created by diogo on 12/05/20.
//

#include <iostream>
#include "Algorithms.h"
#include <algorithm>
#include <graphviewer.h>
#include "readFile.h"


extern Graph<Node> graph;

extern GraphViewer * gv;

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
                int dist = graph.getDist().at(n1.getID()).at(n2.getID());
                if(dist != INT64_MAX)
                    aux.addEdge(n1,n2,dist);
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
            if(aux.getDist().at(k).at(salesman.at(i)) != INT64_MAX){
                path_cost += aux.getDist().at(k).at(salesman.at(i));
                auxiliaryRes.push_back(aux.getPred().at(k).at(salesman.at(i))->getInfo());
            }
            k= salesman.at(i);
        }
        if(aux.getDist().at(k).at(index) != INT64_MAX) {
            path_cost += aux.getDist().at(index).at(k);
            auxiliaryRes.push_back(aux.getPred().at(k).at(index)->getInfo());
        }

        if(path_cost < cost){
            cost = path_cost;
            res.clear();
            res = auxiliaryRes;
        }

    }while(next_permutation(salesman.begin(),salesman.end()));

    cout << "traveler cost: " << cost << endl;
    cout << "traveler path: ";
    for(int i = 0; i< res.size();i++){
        cout << res.at(i).getID() << " ->";
    }
    cout << res.at(0).getID()<< endl << endl;
    return res;
}



vector<Node> bestPath(vector<Client>clients){
    vector<Node>res;
    vector<Node> orderToVisit;
    vector<Node> aux;
    orderToVisit = salesmanPath(clients);
    for(int i = 0;i<orderToVisit.size()-1;i++){
        aux.clear();
        Node n1(orderToVisit.at(i).getID(),orderToVisit.at(i).getX(),orderToVisit.at(i).getY());
        Node n2(orderToVisit.at(i+1).getID(),orderToVisit.at(i+1).getX(),orderToVisit.at(i+1).getY());
        graph.dijkstraShortestPath(n1);
        aux = graph.getPathTo(n2);
        res.insert(res.end(),aux.begin(),aux.end()-1);
    }
    graph.dijkstraShortestPath(orderToVisit.at(orderToVisit.size()-1));
    aux.clear();
    aux = graph.getPathTo(orderToVisit.at(0));
    res.insert(res.end(),aux.begin(),aux.end());
    return res;
}


double pathCost(vector<Node> best){
    double cost;
    for(int i = 0;i<best.size()-1;i++){
        cost += graph.getDist().at(best.at(i).getID()).at(best.at(i+1).getID());
    }
    return cost;
}