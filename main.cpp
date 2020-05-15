#include <cstdio>
#include <graphviewer.h>
#include "readFile.h"
#include "Node.h"
#include "Graph.h"
#include "Client.h"
#include "Algorithms.h"
#include "Vehicle.h"
#include "Utils.h"


extern GraphViewer * gv;
extern Graph<Node> graph;

int main() {
    initGraph();
	readNodeFile("../nodes.txt");
	readEdgeFile("../edges.txt");


    graph.floydWarshallShortestPath();
	vector<Client> clients;
    Client c1("José",123456789,16,Time(15,30));
	Client c2("Alberto",123456789,120,Time(15,30));
    Client c3("Diogo",123456789,0,Time(15,30));
    Client c4("Davide",123456789,280,Time(15,30));
    Client c5("Eduardo",123456789,5,Time(15,30));
    Client c6("Henrique",123456789,60,Time(15,30));
    Client c7("Bastos", 123456789,273,Time(15,30));
    clients.push_back(c1);
    clients.push_back(c2);
    clients.push_back(c3);
    clients.push_back(c4);
    clients.push_back(c5);
    clients.push_back(c6);
    clients.push_back(c7);


    Client admin("Admin",123456789,900,Time(15,30));
    vector<Vehicle> vehicles;
    Vehicle v1(1, admin,YELLOW);
    Vehicle v2(2, admin,RED);
    vehicles.push_back(v1),
    vehicles.push_back(v2);

    assignClients(vehicles, clients);


    cout << "finished assignment" << endl;
    for(Vehicle v:vehicles){
        paintPath(v.getPath(),v.getColor());
    }

	getchar();
	return 0;
}
