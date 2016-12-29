#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

tree_t* btree_new(size_t len, int* data);
tree_t* insert(tree_t* tree, int new);

tree_t* insert(tree_t* tree, int new){
  if (!tree) { 
    // We have stepped beyond our tree and need
    // to allocate a fresh tree to return
    tree_t* fresh = malloc(sizeof(tree_t));
    fresh->data = new;
    return fresh;
  }
  // Build the subtrees, going left if less than pivot
  // right if greater than
  int pivot = tree->data;
  if (new < pivot) tree->left = insert(tree->left, new);
  if (new > pivot) tree->right= insert(tree->right, new);
  return tree;
}

int tree_query(tree_t* tree, int query){
  int pivot;
  // Continue the search until we run out
  // of tree to look at
  while(tree){
    pivot = (*tree).data;
    // Or we come across what we are looking for
    if (query == pivot) return pivot;
    if (query < pivot) tree = tree->left;
    if (query > pivot) tree = tree->right;
  }
  return pivot;
}

tree_t* btree_new(size_t len, int* data){
  tree_t* tree = NULL;
  // naive insertion (ie the tree wont be balanced)
  for (size_t i = 0; i < len; ++i){
    tree = insert(tree, data[i]);
  }

  return tree;
}

int main(int argc, char* argv[]){
  
  int _data[13] = {1, 3, 2, 4, 6, 23, 43, 5, 2, 12, 75, 2, 5};
  int* data = _data;
  tree_t* tree = btree_new(13, data);

  printf("query 12 found %i\n", tree_query(tree, 12));
  printf("query 72 found %i\n", tree_query(tree, 72));
  return 0;
}
