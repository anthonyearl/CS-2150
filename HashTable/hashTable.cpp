//Brandon Feng yf2km 5PM 3/16/17 hashTable.cpp
#include "hashTable.h"

hashTable::hashTable(int size)
{
  buckets = new vector< list <string> >;

  if (!checkprime(size))
    {
      size = getNextPrime(size);
    }
  buckets->resize(size);
  for (int i = 0; i < size; i++)
    {
      list<string> l;
      buckets->push_back(l);
    }
}

hashTable::~hashTable()
{
  delete buckets;
}

bool hashTable::contains(const string & str)
{
  list<string> & curList = buckets->at(hash(str));
  return (find(curList.begin(), curList.end(), str) != (curList.end()));
}

bool hashTable::insert(const string & str)
{
  if (!(this->contains(str)))
    {
      list<string>& curList = buckets->at(hash(str));
      curList.push_back(str);
      return true;
    }
  return false;
}

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}


int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

int hashTable::hash(const string & str)
{
    int res = 0;
    int len = str.length();
    for (int i = 0; i < len; i++)
     {
      res *= 23;
      res += (str[i]);
     }
    return res%(buckets->size());
}
