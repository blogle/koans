#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "deque.h"

tree_t* random_tree(unsigned int items){
  // Create a fresh tree
  tree_t* tree = malloc(sizeof(tree_t));
  int value = rand() % 400;
  tree->data = value;

  if (items / 2 > 0){
    tree->left  = random_tree(items / 2);
    tree->right = random_tree(items / 2);
  }

  return tree;
}

int dfs(tree_t* tree, int query){
  if (!tree) return -1;
  int result;

  // Is this what we are looking for?
  if (tree->data == query) return tree->data;

  // Otherwise check all the left branches
  result = dfs(tree->left, query);
  if (result != -1) return result;
 
  // Bummer we havent found it
  // go ahead and check the right branches
  result = dfs(tree->right, query);
  if (result != -1) return result;

  // A nice indication that we didnt find what we were after
  return -1;
}

int bfs(tree_t* tree, int query){
 if (!tree) return -1;
 // Create a double ended queue 
 // to store the frontier
 deque* frontier = deque_push(deque_new(), tree);

 while (tree){
   if (tree->data == query) return tree->data;
   if (tree->left) frontier = deque_push(frontier, tree->left);
   if (tree->right) frontier = deque_push(frontier, tree->right);
   tree = deque_pop(frontier);
 }
 
 return -1;

}

int main(int argc, char* argv[]){

  tree_t* rtree = random_tree(400);
  int query = 330;
  int result;

  result = dfs(rtree, query);
  if (result != -1) printf("Found the item! %i\n", query);
  
  result = bfs(rtree, query);
  if (result != -1) printf("Found the item! %i\n", query);

  return 0;
}
