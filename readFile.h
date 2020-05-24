//
// Created by diogo on 08/05/20.
//

#ifndef FICHAJUNG_READFILE_H
#define FICHAJUNG_READFILE_H

#include <vector>
#include "Node.h"
#include "Vehicle.h"

void readEdgeFile(const string& name);

void readNodeFile(const string& name);

void initGraph();

void paintPath(Vehicle v);

#endif //FICHAJUNG_READFILE_H
