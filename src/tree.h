// Tree a = Leaf a | Node a Tree Tree

// We have nullable types in C so we can use the same representation
typedef struct tree {
  int data;
  struct tree* left;
  struct tree* right;
} tree_t;

