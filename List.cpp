// Brandon Feng yf2km 1/30/2017 List.cpp
#include "List.h"
using namespace std;

List::List()
{
  head = new ListNode;
  tail = new ListNode;
  (*head).previous = NULL;
  (*head).next = tail;
  (*tail).previous = head;
  (*tail).next = NULL;

  count = 0;
}

List::List(const List& source)
{
  head = new ListNode;
  tail = new ListNode;
  (*head).previous = NULL;
  (*head).next = tail;
  (*tail).previous = head;
  (*tail).next = NULL;

  count = 0;

  ListItr iter(source.head -> next);
  while (!iter.isPastEnd())
    {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
}

List::~List()
{
  makeEmpty();
  delete head;
  delete tail;
}

List& List::operator=(const List& source)
{
  if (this != &source)
    {
      makeEmpty();
      
      ListItr iter(source.head->next);
      while (!iter.isPastEnd())
	{
	  insertAtTail(iter.retrieve());
	  iter.moveForward();
	}

    }
  return *this;
}

bool List::isEmpty() const
{
  return count == 0;
}

void List::makeEmpty()
{
  while(!(isEmpty()))
    {
      remove(first().retrieve());
    }
}

ListItr List::first()
{
  ListItr *f = new ListItr((*head).next);
  if ((*f).isPastEnd())
    {
      (*f).moveBackward();
      return *f;
    }
  return *f;
}

ListItr List::last()
{
  ListItr *l = new ListItr((*tail).previous);
  if ((*l).isPastBeginning())
    {
      (*l).moveForward();
      return *l;
    }
  return *l;
}

void List::insertAfter(int x, ListItr position)
{
  ListNode *l = new ListNode;
  (*l).value = x;
  (*l).previous = position.current;
  (*l).next = position.current->next;

  position.current->next->previous = l;
  position.current->next = l;

  count++;
}

void List::insertBefore(int x, ListItr position)
{
  ListNode *l = new ListNode;
  (*l).value = x;
  (*l).next = position.current;
  (*l).previous = position.current->previous;

  position.current->previous->next = l;
  position.current->previous = l;

  count++;
}

void List::insertAtTail(int x)
{
  ListNode *l = new ListNode;
  (*l).value = x;
  (*l).next = tail;
  (*l).previous = tail->previous;

  tail->previous->next = l;
  tail->previous = l;

  count++;
}

void List::remove(int x)
{
  ListItr *l = new ListItr(find(x));

  if(!l->isPastEnd())
    {
      l->current->previous->next = l->current->next;
      l->current->next->previous = l->current->previous;

      count--;
      delete l;
    }
}

ListItr List::find(int x)
{
  ListItr *l = new ListItr(first());

  while(!l->isPastEnd())
    {
      if(l->current->value == x)
	{
	  return *l;
	}
      l-> moveForward();
    }
  return *l;
}

int List::size() const
{
  return count;
}

void printList(List& source, bool direction)
{
  if(direction)
    {
      ListItr *l = new ListItr(source.first());
      while (!l->isPastEnd())
	{
	  cout << l->retrieve() << " ";
	  l->moveForward();
	}
    }
  else
    {
      ListItr *l = new ListItr(source.last());
      while (!l->isPastBeginning())
	{
	  cout << l->retrieve() << " ";
	  l->moveBackward();
	}
    }
}
