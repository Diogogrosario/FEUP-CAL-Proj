//
// Created by diogo on 08/05/20.
//

#include <edgetype.h>
#include <graphviewer.h>
#include <fstream>
#include <string>


GraphViewer * gv;

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