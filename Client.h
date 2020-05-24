//
// Created by diogo on 12/05/20.
//

#ifndef FICHAJUNG_CLIENT_H
#define FICHAJUNG_CLIENT_H
#include <string>
#include "Time.h"

using namespace std;

class Client {
public:
    Client();
    Client(string name, int NIF, int nodeDestino, Time arrival);
    string name;
    int NIF{};
    int nodeDestino{};
    Time arrival;
    bool delivered = false;
    bool needsDelivery = false;
};


#endif //FICHAJUNG_CLIENT_H
