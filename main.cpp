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

	
	getchar();
	return 0;
}
