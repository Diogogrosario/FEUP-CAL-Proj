//
// Created by cesarnogueira on 5/13/20.
//

#ifndef FICHAJUNG_UTILS_H
#define FICHAJUNG_UTILS_H

#include "Vehicle.h"

void assignClients(vector<Vehicle>& vehicles, vector<Client>& clients);

void showClientes(const vector <Vehicle>& v);

void showPath(const vector<Vehicle>& v);

void createClient(Client *add);

#endif //FICHAJUNG_UTILS_H
