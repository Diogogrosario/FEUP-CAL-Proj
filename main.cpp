#include <cstdio>
#include <graphviewer.h>
#include "readFile.h"



int main() {
    initGraph();
	readNodeFile("../nodes.txt");
	readEdgeFile("../edges.txt");

	getchar();
	return 0;
}
