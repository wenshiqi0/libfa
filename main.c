#include "./include/tree.h"

int main(){
  int array[] = {20,10,34,19,76,8,32};
  BinaryTree tree = makeTree(array, 7);

  iterateTree(tree);

  return 1;
}
