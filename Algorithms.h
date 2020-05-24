//
// Created by diogo on 12/05/20.
//

#ifndef FICHAJUNG_ALGORITHMS_H
#define FICHAJUNG_ALGORITHMS_H
#include "Graph.h"
#include "Node.h"
#include "Client.h"

vector<Node> salesmanPath(vector<Client>&clients);

vector<Node> bestPath(vector<Client>&clients);

double pathCost(vector<Node> best);

#endif //FICHAJUNG_ALGORITHMS_H
