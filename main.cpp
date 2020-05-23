#include <cstdio>
#include <graphviewer.h>
#include <chrono>
#include <fstream>
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
    std::fstream myfile;
    myfile.open("../vehicles.csv",std::ios_base::app);

    initGraph();
	readNodeFile("../nodes.txt");
	readEdgeFile("../edges.txt");
	string ret = "not strongly connected";
	if(graph.isStronglyConnected())
	    ret = "strongly connected";
	cout << "Graph is " << ret << endl;

	vector<Client> clients;
    Client c1("José",123456789,215,Time(17,30));
	Client c2("Alberto",123456789,390,Time(17,30));
    Client c3("Diogo",123456789,354,Time(17,30));
    Client c4("Davide",123456789,284,Time(17,30));
    Client c5("Eduardo",123456789,504,Time(17,30));
    Client c6("Henrique",123456789,781,Time(17,30));
    Client c7("Bastos", 123456789,508,Time(17,30));
    Client c8("Carlos",123456789,421,Time(17,30));
    Client c9("Bastos", 123456789,101,Time(17,30));
    Client c10("Carlos",123456789,12,Time(17,30));
    clients.push_back(c1);
    clients.push_back(c2);
    clients.push_back(c7);
    clients.push_back(c3);
    clients.push_back(c4);
    clients.push_back(c5);
    clients.push_back(c6);
    clients.push_back(c8);
    clients.push_back(c9);
    clients.push_back(c10);


    Client admin("Admin",123456789,230,Time(15,30));
    vector<Vehicle> vehicles;
    Vehicle v1(1, admin,YELLOW,PINK);
    Vehicle v2(2, admin,RED,ORANGE);
    vehicles.push_back(v1),
    vehicles.push_back(v2);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    assignClients(vehicles, clients); //main algorithm

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    myfile << vehicles.size() << "," << chrono::duration_cast<chrono::milliseconds>(end-begin).count() << "\n";
    myfile.close();

    int choice = -1;

    cout << "Welcome to PortoCityTransfers" << endl << endl;

    Client add;

    while(choice != 0) {
        cout << "1) Show all clientes scheduled for trip at the moment" << endl;
        cout << "2) Show path for all clients for next trip" << endl;
        cout << "3) Add client" << endl;
        cout << "4) Simulate trip" << endl;
        cout << "0) Quit" << endl;

        cin >> choice;

        switch(choice){
            case 2:
                showPath(vehicles);
                break;
            case 1:
                showClientes(vehicles);
                break;
            case 3:
                createClient(&add);
                clients.push_back(add);
                break;
            case 4:
                for(Vehicle &v: vehicles){
                    v.clients.clear();
                    v.CustoPath = 0;
                    v.path.clear();
                    v.capacity = 6;
                    v.clients.push_back(admin);
                    v.path.push_back(Node(admin.nodeDestino,0,0));
                    v.best.clear();
                }
                assignClients(vehicles,clients);
                break;
        }


    }

	return 0;
}
