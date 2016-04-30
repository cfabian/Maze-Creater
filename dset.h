//Caleb Fabian
//CS 302 - Lab 6 Disjoint Set Header (From Handout)
//April 4, 2016

#ifndef DSET_H
#define DSET_H

#include <iostream>
#include <vector>
using namespace std;

class dset {
  struct node {
    node() { rank=0, parent=-1; }
    int rank;
    int parent;
  };
  public:
    dset(int N);
    int size() { return Nsets; }
    int newset();
    int merge(int, int);
    int find(int);
  private:
    int Nsets;
    vector<node> S;
};

#endif