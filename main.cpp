#include <cstdio>
#include <graphviewer.h>
#include "readFile.h"

int main() {
    initGraph();
	readNodeFile("../nos.txt");
	readEdgeFile("../arestas.txt");

	getchar();
	return 0;
}
