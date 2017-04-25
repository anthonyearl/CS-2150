//Brandon Feng yf2km 5PM heap.cpp
#include "huffmanNode.h"
#include "heap.h"
#include <iostream>

using namespace std;

heap::heap():list(100),size(0) {
}

heap::~heap() {
  list.clear();
  size = 0;
}

bool heap::isEmpty() {
  return (size == 0);
}

void heap::insert(huffmanNode *n) {
  if (size + 1 == list.size()) {
    list.resize(list.size()*2);
  }

  size = size + 1;
  int hole = size;
  for (; (hole>1) && ((*n)<(*list[hole/2])); hole /= 2) {
    list[hole] = list[hole/2];
  }
  list[hole] = n;
}

void heap::deleteMin() {
  if (!isEmpty()) {
    huffmanNode *ret = list[1];
    list[1] = list[size--];
    list.resize(list.size()-1);

    int hole = 1;
    huffmanNode *x = list[hole];
    while(hole*2 <= size) {
      int child = hole*2;
      if (child!=size && *list[child+1]<*list[child]) {
	child++;
      }
      if (*list[child] < *x) {
	list[hole] = list[child];
	hole = child;
      } else {
	break;      }
    }
    list[hole] = x;
  }
}

huffmanNode* heap::findMin() {
  return list[1];
}

vector<huffmanNode*> heap::getList() {
  return list;
}

