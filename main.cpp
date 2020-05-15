#include <cstdio>
#include <graphviewer.h>
#include <chrono>
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


    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    graph.floydWarshallShortestPath();
	vector<Client> clients;
    Client c1("José",123456789,215,Time(15,30));
	Client c2("Alberto",123456789,390,Time(15,30));
    Client c3("Diogo",123456789,354,Time(15,30));
    Client c4("Davide",123456789,284,Time(15,30));
    Client c5("Eduardo",123456789,504,Time(15,30));
    Client c6("Henrique",123456789,781,Time(15,30));
    Client c7("Bastos", 123456789,508,Time(15,30));
    clients.push_back(c1);
    clients.push_back(c2);
    clients.push_back(c7);
    clients.push_back(c3);
    clients.push_back(c4);
    clients.push_back(c5);
    clients.push_back(c6);


    Client admin("Admin",123456789,230,Time(15,30));
    vector<Vehicle> vehicles;
    Vehicle v1(1, admin,YELLOW,PINK);
    Vehicle v2(2, admin,RED,ORANGE);
    vehicles.push_back(v1),
    vehicles.push_back(v2);

    assignClients(vehicles, clients);


    cout << "finished assignment" << endl;
    for(Vehicle v:vehicles){
        paintPath(v);
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    cout << "time difference: " << chrono::duration_cast<chrono::seconds>(end-begin).count() << endl;

	getchar();
	return 0;
}
