//Brandon Feng yf2km 5PM huffmanTree.h
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "huffmanNode.h"
#include "heap.h"

using namespace std;

class huffmanTree{
 public:
  huffmanTree(heap h);
  huffmanNode *root;
  void encode(huffmanNode* root, string code);
  heap huffHeap;
};
#endif
