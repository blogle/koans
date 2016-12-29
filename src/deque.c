#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "deque.h"

deque* deque_new(){
  struct _ddlist* list = malloc(sizeof(struct _ddlist));
  deque* queue = malloc(sizeof(deque));

  queue->front = list;
  queue->back  = list;
  
  return queue;
}

deque* deque_push(deque* queue, tree_t* tree){
  // If this is the first element then just place the item
  if (!queue->front->tree){
    queue->front->tree = tree;
    return queue;
  }
     
  // Allocate a new list node for the back of the queue
  struct _ddlist* list = malloc(sizeof(struct _ddlist));

  list->tree = tree;
  list->prev = queue->back;
  queue->back->next = list;
  queue->back = list;

  return queue;
}

tree_t* deque_pop(deque* queue){
  // Pop an element off the front of the queue
  struct _ddlist* list_node = queue->front;

  queue->front = queue->front->next;
  tree_t* tree = list_node->tree;

  free(list_node->prev);
  return tree;
}
