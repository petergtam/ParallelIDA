/* 
 * File:   Node.cpp
 * Author: psalas
 * 
 * Created on February 23, 2015, 4:33 PM
 */

#include "Node.h"
#include <ostream>

Node::Node(int a, int b) {
    this->SetX(a);
    this->SetY(b);
}

int Node::GetH() const {
    return h;
}

void Node::SetH(int h) {
    this->h = h;
}

int Node::GetX() const {
    return x;
}

void Node::SetX(int x) {
    this->x = x;
}

int Node::GetY() const {
    return y;
}

void Node::SetY(int y) {
    this->y = y;
}

std::ostream& operator<<(std::ostream& os, const Node* obj) {
    os << "Node \n";
    os << "[" << obj->GetX() << "," << obj->GetY() << "]";
    return os;
}

bool Node::operator==(const Node& other) const {
    return (this->x == other.x && this->y == other.y);
}



