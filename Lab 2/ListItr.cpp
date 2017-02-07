// Brandon Feng yf2km 1/30/2017 ListItr.cpp
#include "ListItr.h"

ListItr::ListItr()
{
  current = NULL;
}

ListItr::ListItr(ListNode* theNode)
{
  current = theNode;
}

bool ListItr::isPastEnd() const
{
  return current->next == NULL;
}

bool ListItr::isPastBeginning() const
{
  return current->previous == NULL;
}

void ListItr::moveForward()
{
  if(!isPastEnd())
    {
      current = current->next;
    }
}

void ListItr::moveBackward()
{
  if(!isPastBeginning())
    {
      current = current->previous;
    }
}

int ListItr::retrieve() const
{
  return current->value;
}
