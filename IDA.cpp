/* 
 * File:   IDA.cpp
 * Author: psalas
 *
 * Created on February 23, 2015, 4:33 PM
 */

#include <set>
#include <stack>
#include <iostream>
#include "Maze.h"
#include <omp.h>
#include <stdexcept>

using namespace std;
/*
 * 
 */
typedef stack<Node*> pila;
typedef vector<pila> pilas;

pilas s;
set<int> idle;
int n;


void Push(int i,Node* r){
    s[i-1].push(r);
}

vector<Node*> parallelIDA(Node* r,Maze* m,int k,int U,int Up){
    Push(1,r);
    for(int i = 2; i<=n;i++){
       idle.insert(i); 
    }
    bool goalFound = false;
    while(!goalFound){
        for(int i:idle){
            cout<<i;
        }
        goalFound = true;
    }
    return vector<Node*>();
}

int main(int argc, char** argv) {
    Maze* m = new Maze(3,3);
    Node* u = m->getStart();
    u->h = m->heuristic(u);
    n=4;
    for(int i=0; i<n;i++){
        pila st;
        s.push_back(st);
    }
    parallelIDA(u,m,2,10,5);
    return 0;
}



