//
// Created by diogo on 08/05/20.
//

#include <edgetype.h>
#include <graphviewer.h>
#include "Graph.h"
#include <fstream>
#include "Node.h"
#include <string>


GraphViewer * gv;
Graph<Node> graph;

double dist(Node n1,Node n2);

void readEdgeFile(string name)
{
    ifstream edgeFile;
    static int id = 0;

    edgeFile.open(name.c_str());

    while (!edgeFile.eof()) {
        string line;
        int id, n1, n2;

        getline(edgeFile, line, '(');

        getline(edgeFile, line, ',');
        n1 = stoi(line);
        getline(edgeFile, line, ')');
        n2 = stoi(line);


        getline(edgeFile, line, '\n');

        gv->addEdge(id, n1, n2, EdgeType::UNDIRECTED);
        Node source;
        Node dest;
        for(int i = 0;i<graph.getVertexSet().size();i++){
            if(n1 == graph.getVertexSet().at(i)->getInfo().getID())
                source = graph.getVertexSet().at(i)->getInfo();
            if(n2 == graph.getVertexSet().at(i)->getInfo().getID())
                dest = graph.getVertexSet().at(i)->getInfo();
        }

        graph.addEdge(source,dest,dist(source,dest));
        id++;
    }
    gv->rearrange();
    edgeFile.close();
    return;
}


void readNodeFile(string name){

    ifstream nodeFile;

    nodeFile.open(name.c_str());

    while (!nodeFile.eof()) {
        string line;
        int id, x, y;

        getline(nodeFile, line, '(');

        getline(nodeFile, line, ',');
        id = stoi(line);
        getline(nodeFile, line, ',');
        x = stoi(line);
        getline(nodeFile, line, ')');
        y = stoi(line);

        getline(nodeFile, line, '\n');

        gv->addNode(id, x, y);
        graph.addVertex(Node(id,x,y));
    }

    gv->rearrange();
    nodeFile.close();
    return;

}

void initGraph(){
    gv = new GraphViewer(1000, 1000, false);
    gv->createWindow(1000, 1000);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

}



double dist(Node n1, Node n2){
    double distX = 0;
    double distY = 0;
    distX = pow(n1.getX()-n2.getX(),2);
    distY = pow(n1.getY()-n2.getY(),2);
    return sqrt(distX+distY);
}