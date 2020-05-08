//
// Created by diogo on 08/05/20.
//

#include "Node.h"

Node::Node(int id, int x,int y){
        this->id = id;
        this->coords.push_back(x);
        this->coords.push_back(y);
}

int Node::getX() {
    return coords.at(0);
}

int Node::getY() {
    return coords.at(1);
}

int Node::getID() {
    return id;
}

Node::Node() {

}

bool Node::operator==(Node n2) const {
    return (this->id == n2.getID());
}
