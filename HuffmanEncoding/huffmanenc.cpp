//Brandon Feng yf2km 5PM huffmanenc.cpp
#include "huffmanNode.h"
#include "heap.h"
#include "huffmanTree.h"
// included so we can use cout
#include <iostream>
// stdlib.h is where exit() lives
#include <stdlib.h>

using namespace std;

// include the standard I/O library
#include <stdio.h>

// we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file.  FILE is a type desgined to
    // hold file pointers.  The first parameter to fopen() is the
    // filename.  The second parameter is the mode -- "r" means it
    // will read from the file.
    FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }
    // read in each character, one by one.  Note that the fgetc() will
    // read in a single character from a file, and returns EOF when it
    // reaches the end of a file.

    int freq[128] = {0};
    int characters = 0;
    char g;
    while ( (g = fgetc(fp)) != EOF ){
      int asciiV = (int) g;
      if (asciiV >31) {
	freq[asciiV]++;
	characters++;
      }
    }

    int count = 0;
    heap minHeap;
    for(int i = 0; i < 128;i++){
      if (freq[i] > 0) {
	huffmanNode* temp = new huffmanNode((char) i, freq[i]);
	minHeap.insert(temp);
	count++;
      }
    }

    huffmanTree* ht = new huffmanTree(minHeap);

    ht->encode(ht->root,"");
    // a nice pretty separator
    cout << "----------------------------------------" << endl;
    // rewinds the file pointer, so that it starts reading the file
    // again from the begnning
    rewind(fp);

    int cBit = 0;
    int oBit = characters*8;
    vector<huffmanNode*> huffHeap = minHeap.getList();
    
    while ( (g = fgetc(fp)) != EOF ){ 
      for(int i = 1; i <= count; i++){
	if(huffHeap[i]->character == g){
	    cout << huffHeap[i]->code <<" ";
	    cBit += huffHeap[i]->code.size();
	    break;
	  }
      }
    }

    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "There are a total of " << characters << " symbols that are encoded." << endl;
    cout << "There are " << count << " distinct symbols used." << endl;
    cout << "There were " << oBit << " bits in the original file." << endl;
    cout << "There were " << cBit << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << (double)oBit/cBit << "." << endl;
    cout << "The cost of the Huffman Tree is " << (double)cBit/characters << " bits per character." << endl; 
    // close the file
    fclose(fp);
}
