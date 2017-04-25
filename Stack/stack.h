// Brandon Feng yf2km 2/7/2017 stack.h

#ifndef STACK_H
#define STACK_H

#include "List.h"
#include "ListNode.h"
#include "ListItr.h"

using namespace std;

class stack {
 public:
  stack();
  ~stack();
  bool empty() const;
  void push(int x);
  int top() const;
  void pop();
  
 private:
  List* stack_list;
  int count;
};

#endif
