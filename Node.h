/* 
 * File:   Node.h
 * Author: psalas
 *
 * Created on February 23, 2015, 4:33 PM
 */

#ifndef NODE_H
#define	NODE_H

#include<ostream>

class Node {
public:
    int x;
    int y;
    int h;
    Node(int a, int b);
    std::ostream& operator<<(std::ostream& os) const{
        os<<"Node \n";
        os<<"["<<this->x<<","<<this->y<<"]";
        return os;
    }
    bool operator==(const Node& other) const{
        return (this->x==other.x && this->y==other.y);
    }
};

#endif	/* NODE_H */

