//Brandon Feng yf2km 5PM huffmanTree.cpp
#include "huffmanNode.h"
#include "huffmanTree.h"
#include "heap.h"
#include <string>

huffmanTree::huffmanTree(heap h){
  while(h.size >=2) {
    huffmanNode* n1 = h.findMin();
    h.deleteMin();
    huffmanNode* n2 = h.findMin();
    h.deleteMin();
    int totalFreq = n1->frequency + n2->frequency;
    huffmanNode* n3 = new huffmanNode('v', totalFreq);
    n3->left = n1;
    n3->right = n2;
    h.insert(n3);
  }
  huffHeap = h;
  root = h.findMin();
}

void huffmanTree::encode(huffmanNode *root, string temp){
  if (root->left==NULL && root->right==NULL){
    root->code = temp;
    if (root->character == ' ') {
      cout << "space" << " " << root->code << endl;
    } else {
      cout << root->character << " " << root->code << endl;
    }
  }
  if (root->left != NULL){
    encode(root->left, temp+"0");
  }
  if (root->right != NULL){
    encode(root->right, temp+"1");
  }
}
