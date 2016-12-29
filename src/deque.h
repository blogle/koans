struct _ddlist {
  tree_t* tree;
  struct _ddlist* next;
  struct _ddlist* prev;
};

typedef struct _deque {
  struct _ddlist* front;
  struct _ddlist* back;
} deque;

deque* deque_new();
deque* deque_push(deque* queue, tree_t* tree);
tree_t* deque_pop(deque* queue);
