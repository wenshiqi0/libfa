#include "./include/tree.h"

int main(){
  BinaryTree tree = makeNode(20);
  insertTree(tree,10);
  insertTree(tree,34);
  insertTree(tree,19);
  insertTree(tree,76);
  insertTree(tree,8);
  insertTree(tree,32);

  Position temp = findTreeNode(tree,76);

  iterateTree(tree);

  printf("\n");

  printf("%d\n", (findMin(tree))->value);
  printf("%d\n", (findMax(tree))->value);

  return 1;
}
