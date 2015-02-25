/* 
 * File:   IDA.cpp
 * Author: psalas
 *
 * Created on February 23, 2015, 4:33 PM
 */

#include <set>
#include <stack>
#include <list>
#include <iostream>
#include "Maze.h"
#include <omp.h>
#include <stdexcept>
#include <algorithm>

using namespace std;
/*
 * 
 */
typedef stack<Node*> pila;
typedef vector<pila> pilas;

pilas s;
int n;
vector<int> idle;


void Push(int i, Node* r) {
    s[i].push(r);
}

void StackSplit(int i, int j) {
    pila po = s[i];
    pila pi,pj;
    int counter = 0;
    while(!po.empty()){
        if(counter%2==0){
            pi.emplace(po.top());
        }
        else{
            pj.emplace(po.top());
        }
        po.pop();
        counter++;
    }
    s[i]=pi;
    s[j]=pj;
}

Node* Pop(int i) {
    Node* u = s[i].top();
    s[i].pop();
    return u;
}

vector<Node*> parallelIDA(Node* r, Maze* m, int k, int U, int Up) {
    Push(0, r);
    for (int l = 1; l <=n; l++) {
        idle.push_back(l);
    }
    bool goalFound = false;
    while (!goalFound) {
        //#pragma omp parallel for
        for (int i = 0; i < n; i++) {
            if (s[i].size() == 0) {
                if(find(idle.begin(),idle.end(),i)==idle.end()){
                    idle.push_back(i);
                }
            } else {
                if (s[i].size() > k && !idle.empty()) {
                    int j = *(idle.begin());
                    idle.erase(idle.begin());
                    StackSplit(i, j);
                }
                Node* u = Pop(i);
                if (m->isGoal(u)) {
                    goalFound = true;
                    break;
                }
                vector<Node*> succ = m->succ(u);
                for (Node* v : succ) {
                    Push(i,v);
                }
            }
        }        
    }
    return vector<Node*>();
}

int main(int argc, char** argv) {
    //setting openmp
   omp_set_dynamic(0);   
    
    Maze* m = new Maze(5, 5);
    Node* u = m->getStart();
    u->SetH(m->heuristic(u));
    n = omp_get_num_procs();
    for (int i = 0; i < n; i++) {
        pila st;
        s.push_back(st);
    }
    cout<<m;
    parallelIDA(u, m, 2, 10, 5);
    return 0;
}



