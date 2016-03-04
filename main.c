#include "./include/tree.h"

int main(){
  int array[] = {1,2,3,4,5,6,7,8};
  AVLTree tree = makeAVLTree(array, GET_ARRAY_LEN(array));

  iterateAVLTree(tree);

  return 1;
}
