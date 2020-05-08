//
// Created by diogo on 08/05/20.
//

#include <edgetype.h>
#include <graphviewer.h>
#include <fstream>
#include <string>

void exercicio3()
{
    ifstream edgeFile;
    ifstream nodeFile;

    GraphViewer * gv = new GraphViewer(600, 600, false);
    gv->createWindow(600, 600);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");


    edgeFile.open("../resources/mapa1/arestas.txt");
    nodeFile.open("../resources/mapa1/nos.txt");

    while (!nodeFile.eof()) {
        string line;
        int id, x, y;

        getline(nodeFile, line, ';');
        id = stoi(line);
        getline(nodeFile, line, ';');
        x = stoi(line);
        getline(nodeFile, line, '\n');
        y = stoi(line);
        gv->addNode(id, x, y);
    }

    while (!edgeFile.eof()) {
        string line;
        int id, n1, n2;

        getline(edgeFile, line, ';');
        id = stoi(line);
        getline(edgeFile, line, ';');
        n1 = stoi(line);
        getline(edgeFile, line, '\n');
        n2 = stoi(line);

        gv->addEdge(id, n1, n2, EdgeType::UNDIRECTED);
    }
    gv->rearrange();
    edgeFile.close();
    nodeFile.close();
    return;

}