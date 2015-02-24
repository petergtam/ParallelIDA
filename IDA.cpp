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

using namespace std;
/*
 * 
 */
typedef stack<Node*> pila;
typedef vector<pila> pilas;

pilas S;
set<int> idle;


void Push(int i,Node* n){
    if(!S.at(i-1).empty()){
        S[i-1].push(n);
    }
    else{
        pila s;
        s.push(n);
        S.push_back(s);
    }
}

vector<Node*> parallelIDA(Node* n,Maze* m,int k,int U,int Up){
    int N = omp_get_thread_num();
    Push(1,n);
    for(int i = 2; i<=N;i++){
       idle.insert(i); 
    }
    bool goalFound = false;
    while(!goalFound){
        for(int i:idle){
            cout<<i;
        }
    }
}

int main(int argc, char** argv) {
    Maze* m = new Maze(3,3);
    Node* n = m->getStart();
    n->h = m->heuristic(n);
    parallelIDA(n,m,2,10,5);
    return 0;
}



