#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int number;
  struct node *next
} node;

int main(void) {
  // create an empty linked list
  node *list = NULL;
  // create first node but nothing else is pointing to it
  node *n = malloc(sizeof(node));
  if (n == NULL) {
    free(list);
    return 1;
  }
  
  n->number = 1; // equivalent to (*n).number = 1
  n->next = NULL;
  list = n;

  // create second node but nothing else is pointing to it
  node *n = malloc(sizeof(node));
  if (n == NULL) {
    free(list);
    return 1;
  }
  
  n->number = 2; // equivalent to (*n).number = 1
  n->next = NULL;
  list->next = n;

  n = malloc(sizeof(node));
  if (n == NULL) {
    free(list->next);
    free(list);
    return 1;
  }
  
  n->number = 3; // equivalent to (*n).number = 1
  n->next = NULL;
  list->next->next = n;
  
  // print the contents of the linked list
  for (node *tmp = list; tmp != NULL; tmp = tmp->next) {
    printf("%i\n", tmp->number);
  }
  
  while (list != NULL) {
    node *tmp = list->next;
    free(list);
    list = tmp;
  }

  return 0;
}
