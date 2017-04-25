//Brandon Feng yf2km postfixCalculator.cpp 2/7/2017

#include "postfixCalculator.h"
#include "stack.h"
#include <cstdlib>
using namespace std;

postfixCalculator::postfixCalculator()
{
  stack = new ::stack();
}


postfixCalculator::~postfixCalculator()
{
  delete stack;
}

bool postfixCalculator::isEmpty()
{
  return stack->empty();
}

void postfixCalculator::pushNum(int x)
{
  stack->push(x);
}

void postfixCalculator::add()
{
  if(isEmpty())
    {
      exit(-1);
    }
  int a = stack->top();
  stack->pop();
  if(isEmpty())
    {
      exit(-1);
    }
  int b = stack->top();
  stack->pop();
  stack->push(b+a);
}

void postfixCalculator::minus()
{
  if(isEmpty())
    {
      exit(-1);
    }
  int a = stack->top();
  stack->pop();
  if(isEmpty())
    {
      exit(-1);
    }
  int b = stack->top();
  stack->pop();
  stack->push(b-a);
}

void postfixCalculator::multiply()
{
  if(isEmpty())
    {
      exit(-1);
    }
  int a = stack->top();
  stack->pop();
  if(isEmpty())
    {
      exit(-1);
    }
  int b = stack->top();
  stack->pop();
  stack->push(b*a);
}

void postfixCalculator::divide()
{
  if(isEmpty())
    {
      exit(-1);
    }
  int a = stack->top();
  stack->pop();
  if(isEmpty())
    {
      exit(-1);
    }
  int b = stack->top();
  stack->pop();
  stack->push(b/a);
}

void postfixCalculator::uNegate()
{
  if(isEmpty())
    {
      exit(-1);
    }
  int a = stack->top();
  stack->pop();
  stack->push(a*(-1));
}

int postfixCalculator::getTopValue()
{
  if(isEmpty())
    {
      exit(-1);
    }
  return stack->top();
}
