//Brandon Feng yf2km 5PM heap.h
#ifndef HEAP_H
#define HEAP_H

#include "huffmanNode.h"
#include <iostream>
#include <vector>

using namespace std;

class heap {
 public:
  heap();
  ~heap();
  bool isEmpty();
  void insert(huffmanNode *n);
  void deleteMin();
  huffmanNode* findMin();
  int size;
  vector<huffmanNode*> getList();

 private:
  vector<huffmanNode*> list;
};

#endif
