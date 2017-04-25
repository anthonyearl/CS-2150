// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "huffmanNode.h"
using namespace std;

void createTree(huffmanNode *n, string c, string s) {
  if (s.length()==0) {
    n->character=c[0];
  }

  if (s[0]=='0') {
    if (n->left == NULL) {
      n->left = new huffmanNode('\0', 0);
    }
    createTree(n->left, c, s.substr(1, s.length()-1));
  }
  else if (s[0]=='1') {
    if (n->right == NULL) {
      n->right = new huffmanNode('\0', 0);
    }
    createTree(n->right, c, s.substr(1, s.length()-1));
  }
}

void decode(huffmanNode *n, string bits) {
  huffmanNode* root = n;
  while (bits.length() > 0) {
    while (root->left != NULL || root->right != NULL) {
      if (bits[0] == '0') {
	root = root->left;
	bits = bits.substr(1, bits.length()-1);
      }
      else if (bits[0] == '1') {
	root = root->right;
	bits = bits.substr(1, bits.length()-1);
      }
    }
    cout << root->character;
    root = n;
  }
  cout << endl;
}
    

// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    huffmanNode* root1 = new huffmanNode('\0', 0);
    // read in the first section of the file: the prefix codes
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code

	createTree(root1, character, prefix);
    }
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    decode(root1, allbits);
    // close the file before exiting
    file.close();
}
