/* 
 * File:   Maze.cpp
 * Author: psalas
 * 
 * Created on February 23, 2015, 4:33 PM
 */

#include "Maze.h"
#include <cmath>
#include <ctime>
#include <cstdlib>

Maze::Maze(int n, int m) {
    srand(time(0));
    this->rows = m;
    this->columns = n;
    this->maze = new int*[columns];

    for (int i = 0; i < columns; i++) {
        this->maze[i] = new int[rows];
        for (int j = 0; j < rows; j++) {
            int r = rand() % 100;
            if (r <= 30) this->maze[i][j] = WALL;
            else this->maze[i][j] = FREE;
        }
    }
    //randomly select start and end positions
    this->start = CreateNode();
    this->goal = CreateNode();
}

std::ostream& operator <<(std::ostream& os, const Maze* obj){
    os<<"Maze\n";
    for (int i = 0; i < obj->columns; i++) {
        for (int j = 0; j < obj->rows; j++) {
            os<<obj->maze[i][j];
        }
        os<<std::endl;
    }
    os<<std::endl;
    return os;
}

Node* Maze::CreateNode() {
    int x, y;
    do {
        x = rand() % (rows - 1);
        y = rand() % (columns - 1);
    } while (maze[x][y] == 0);
    return new Node(x, y);
}

Node* Maze::getStart() {
    return this->start;
}

int Maze::heuristic(Node* n) {
    return abs(n->GetX() - goal->GetX()) + abs(n->GetY() - goal->GetY());
}

bool Maze::isGoal(Node* n) {
    return n == goal;
}

std::vector<Node*> Maze::succ(Node* n) {
    std::vector<Node*> succ;
    int x = n->GetX(), y = n->GetY();
    if (x - 1 >= 0 && maze[x - 1][y] != WALL) {
        succ.push_back(new Node(x - 1, y));
    }
    if (y + 1 < columns && maze[x][y + 1] != WALL) {
        succ.push_back(new Node(x, y + 1));
    }
    if (x + 1 < rows && maze[x + 1][y] != WALL) {
        succ.push_back(new Node(x + 1, y));
    }
    if (y - 1 >= 0 && maze[x][y - 1] != WALL) {
        succ.push_back(new Node(x, y - 1));
    }
    return succ;
}

int Maze::weight(Node*, Node*) {
    return 1;
}







