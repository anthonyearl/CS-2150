//Brandon Feng yf2km 5PM huffmanNode.h
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>
using namespace std;

class huffmanNode {
 public:
  huffmanNode(char chara, int freq);
  char character;
  string code;
  huffmanNode *left;
  huffmanNode *right;
  int frequency;
  bool operator<(const huffmanNode& node) const;
};

#endif
