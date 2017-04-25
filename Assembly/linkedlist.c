//Brandon Feng yf2km 5PM linkedlist.c 4/13/2017
#include <stdio.h>
#include <stdlib.h>

struct list_item {
  struct list_item *prev, *next;
  int value;
};

struct list {
  struct list_item *head, *tail;
  unsigned length;
};

int main() {
  int num;
  printf("Enter how many values to input: ");
  scanf("%d", &num);

  struct list *li = (struct list *) malloc(sizeof(struct list));
  li->length = num;
  struct list_item *lh = (struct list_item *) malloc(sizeof(struct list_item));
  lh->prev = NULL;
  li->head = lh;
  struct list_item *dummy = (struct list_item *) malloc(sizeof(struct list_item));
  lh->next = dummy;

  for(int i = 1; i <= num; i++) {
    int temp;
    printf("Enter value %d: ", i);
    scanf("%d", &temp);
    dummy->value = temp;
    dummy->next = (struct list_item *) malloc(sizeof(struct list_item));
    dummy = dummy->next;
  }

  struct list_item *iter = li->head->next;
  
  for(int i = 0; i < num; i++) {
    printf("%d\n", iter->value);
    iter = iter->next;
  }

  free(li);

  return 0;
}
