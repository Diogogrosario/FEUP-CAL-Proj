//
// Created by diogo on 08/05/20.
//

#ifndef FICHAJUNG_NODE_H
#define FICHAJUNG_NODE_H
#include <vector>
using namespace std;


class Node {
    int id{};
    vector<int> coords;

    public:
        Node();
        Node(int id, int x,int y);
        int getX() const ;
        int getY() const ;
        int getID() const ;
        bool operator==(const Node& n2)const;
};


#endif //FICHAJUNG_NODE_H
