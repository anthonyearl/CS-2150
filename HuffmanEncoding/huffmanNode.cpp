//Brandon Feng yf2km 5PM huffmanNode.cpp
#include "huffmanNode.h"
#include <iostream>

using namespace std;

huffmanNode::huffmanNode(char chara, int freq) {
  frequency = freq;
  character = chara;
  code = "";
  left = NULL;
  right = NULL;
}

bool huffmanNode::operator<(const huffmanNode& n) const {
  return(this->frequency<n.frequency);
}
