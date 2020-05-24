//
// Created by diogo on 08/05/20.
//

#include "Node.h"

Node::Node(int id, int x,int y){
        this->id = id;
        this->coords.push_back(x);
        this->coords.push_back(y);
}

int Node::getX() const{
    return coords.at(0);
}

int Node::getY() const{
    return coords.at(1);
}

int Node::getID() const{
    return id;
}

Node::Node() = default;

bool Node::operator==(const Node& n2) const {
    return (this->id == n2.getID());
}
