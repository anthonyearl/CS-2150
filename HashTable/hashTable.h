//Brandon Feng yf2km 5PM 3/16/17 hashTable.h
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <list>

using namespace std;

class hashTable {
    public:
        hashTable(int size);
        ~hashTable();
        bool contains (const string & str);
        bool insert (const string & str);
	bool checkprime(unsigned int p);
	int getNextPrime (unsigned int n);

    private:
        int hash(const string & str);
	vector< list<string> > *buckets;
};

#endif

