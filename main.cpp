#include <cstdio>
#include <graphviewer.h>
#include "readFile.h"
#include "Node.h"
#include "Graph.h"



extern GraphViewer * gv;
extern Graph<Node> graph;

int main() {
    initGraph();
	readNodeFile("../nodes.txt");
	readEdgeFile("../edges.txt");

	Node n(0,0,0);
	Node d(288,0,0);
    Node d2(30,0,0);

	vector<Node> path;
	graph.dijkstraShortestPath(n);
	path = graph.getPathTo(d);
	paintPath(path,YELLOW);
    path = graph.getPathTo(d2);
    paintPath(path,RED);

	getchar();
	return 0;
}
