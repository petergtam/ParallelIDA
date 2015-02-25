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
    Node(int a, int b);
    friend std::ostream& operator<<(std::ostream&, const Node*);
    bool operator==(const Node& other) const;
    int GetH() const;
    void SetH(int h);
    int GetX() const;
    void SetX(int x);
    int GetY() const;
    void SetY(int y);
private:
    int x;
    int y;
    int h;
};

#endif	/* NODE_H */

