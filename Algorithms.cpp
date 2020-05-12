//
// Created by diogo on 12/05/20.
//

#include "Algorithms.h"
#include "readFile.h"


extern Graph<Node> graph;

vector<Node> salesmanPath(vector<Client>clients){
    vector<Node> res;
    Graph<Node> aux;
    Vertex<Node> *n;


    for(Client c:clients){
        n = graph.findVertex(Node(c.nodeDestino,0,0));
        aux.addVertex(Node(n->getInfo().getID(),n->getInfo().getX(),n->getInfo().getY()));
    }
    for(auto ver:aux.getVertexSet()){
        for(auto ver2:aux.getVertexSet()){
            if(ver != ver2) {

                aux.addEdge(Node(ver->getInfo().getID(),ver->getInfo().getX(),ver->getInfo().getY()),Node(ver2->getInfo().getID(),ver2->getInfo().getX(),ver2->getInfo().getY()), dist(Node(ver->getInfo().getID(),ver->getInfo().getY(),ver->getInfo().getY()), Node(ver2->getInfo().getID(),ver2->getInfo().getY(),ver2->getInfo().getY())));
            }
        }
    }

    //FINISHED BUILDING AUX GRAPH



}