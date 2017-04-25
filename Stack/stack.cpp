// Brandon Feng yf2km 2/7/2017 stack.cpp

#include "stack.h"

stack::stack()
{
  stack_list = new List;
  count = 0;
}

stack::~stack()
{
  stack_list->makeEmpty();
  delete stack_list;
}

bool stack::empty() const
{
  return stack_list->isEmpty();
}

void stack::push(int x)
{
  stack_list->insertAtTail(x);
}

int stack::top() const
{
  return stack_list->last().retrieve();
}

void stack::pop()
{
  ListItr itr = stack_list->last();
  stack_list->remove(itr.retrieve());
}

