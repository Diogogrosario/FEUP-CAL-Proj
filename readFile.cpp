//
// Created by diogo on 08/05/20.
//

#include <edgetype.h>
#include <graphviewer.h>
#include "Graph.h"
#include <fstream>
#include "Node.h"
#include "Vehicle.h"
#include <string>


GraphViewer * gv;
Graph<Node> graph;

void readEdgeFile(const string& name)
{
    ifstream edgeFile;
    static int id = 0;

    edgeFile.open(name.c_str());

    while (!edgeFile.eof()) {
        string line;
        int n1, n2;
        double weight;

        getline(edgeFile, line, '(');

        getline(edgeFile, line, ',');
        n1 = stoi(line);
        getline(edgeFile, line, ',');
        n2 = stoi(line);
        getline(edgeFile, line, ')');
        weight = stoi(line);


        getline(edgeFile, line, '\n');

        gv->addEdge(id, n1, n2, EdgeType::UNDIRECTED);
        id++;

        graph.addEdge(Node(n1,0,0),Node(n2,0,0),weight);

        id++;
    }
    edgeFile.close();
}


void readNodeFile(const string &name){

    bool hasOffset = false;
    ifstream nodeFile;

    nodeFile.open(name.c_str());

    int offsetX = 0,offsetY = 0;

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


        if(!hasOffset){
            offsetX = x;
            offsetY = y;
            hasOffset = true;
        }
        getline(nodeFile, line, '\n');

        gv->addNode(id, x-offsetX, y-offsetY);
        gv->setVertexLabel(id,to_string(id));
        graph.addVertex(Node(id,x-offsetX,y-offsetY));
    }

    gv->rearrange();
    nodeFile.close();

}

void initGraph(){
    gv = new GraphViewer(1000, 1000, false);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");
    gv->createWindow(1000, 1000);
}


void paintPath(Vehicle v){

    for (const Node& n:v.getPath()) {
        gv->setVertexColor(n.getID(), v.getColor());
    }
    for(const Client& c:v.getClients()){
        gv->setVertexColor(c.nodeDestino,v.getColorVertex());
    }
    gv->rearrange();
}