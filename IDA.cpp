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


void Push(pila s,Node* n){
    s.push(n);
}

vector<Node*> parallelIDA(Node* n,Maze* m,int k,int U,int Up){
    int N = omp_get_thread_num();
    Push(S[1],n);
    for(int i = 2; i<=N;i++){
       idle.insert(i); 
    }
    bool goalFound = false;
    while(!goalFound){
        
    }
}

int main(int argc, char** argv) {
    Maze* m = new Maze(3,3);
    return 0;
}



