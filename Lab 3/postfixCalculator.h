//Brandon Feng yf2km postfixCalculator.h 2/7/2017
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include "stack.h"
#include <iostream>

using namespace std;

class postfixCalculator {
 public:
  postfixCalculator();
  postfixCalculator(const postfixCalculator& source);
  ~postfixCalculator();
  postfixCalculator& operator=(const postfixCalculator& source);
  void pushNum(int x);
  void add();
  bool isEmpty();
  void minus();
  void multiply();
  void divide();
  void uNegate();
  int getTopValue();

 private:
  stack *stack;
  
};

#endif
