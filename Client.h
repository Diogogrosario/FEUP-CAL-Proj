//
// Created by diogo on 12/05/20.
//

#ifndef FICHAJUNG_CLIENT_H
#define FICHAJUNG_CLIENT_H
#include <string>
#include "Time.h"
#include "Address.h"

using namespace std;

class Client {
    string name;
    int NIF;
    Address destino;
    Time arrival;
};


#endif //FICHAJUNG_CLIENT_H
