/* 
 * File:   Maze.h
 * Author: psalas
 *
 * Created on February 23, 2015, 4:33 PM
 */

#ifndef MAZE_H
#define	MAZE_H

#include <vector>
#include "Node.h"

#define WALL 0
#define FREE 1

class Maze {
public:
    Maze(int, int);
    bool isGoal(Node*);
    std::vector<Node*> succ(Node*);
    Node* getStart();
    int heuristic(Node*);
    int weight(Node*, Node*);
private:
    int rows;
    int columns;
    int **maze;
    Node *start;
    Node *goal;
    Node* CreateNode();
};

#endif	/* MAZE_H */

