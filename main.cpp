#include <cstdio>
#include <graphviewer.h>
#include "readFile.h"
#include "Node.h"
#include "Graph.h"
#include "Client.h"
#include "Algorithms.h"


extern GraphViewer * gv;
extern Graph<Node> graph;

int main() {
    initGraph();
	readNodeFile("../nodes.txt");
	readEdgeFile("../edges.txt");

	vector<Client> clients;
	Client c1("José",123456789,250,Time(15,30));
	Client c2("Alberto",123456789,125,Time(15,30));
    Client c3("Diogo",123456789,100,Time(15,30));
    Client c4("Davide",123456789,280,Time(15,30));
    Client c5("Eduardo",123456789,5,Time(15,30));
    Client c6("Henrique",123456789,60,Time(15,30));
    clients.push_back(c1);
    clients.push_back(c2);
    clients.push_back(c3);
    clients.push_back(c4);
    clients.push_back(c5);
    clients.push_back(c6);

    salesmanPath(clients);



	getchar();
	return 0;
}
