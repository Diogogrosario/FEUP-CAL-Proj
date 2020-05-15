//
// Created by diogo on 08/05/20.
//

#ifndef FICHAJUNG_READFILE_H
#define FICHAJUNG_READFILE_H

#include <vector>
#include "Node.h"
#include "Vehicle.h"

void readEdgeFile(string name);

void readNodeFile(string name);

void initGraph();

void paintPath(Vehicle v);

double dist(Node n1, Node n2);

#endif //FICHAJUNG_READFILE_H
