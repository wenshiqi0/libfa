#include "../include/tree.h"

void defaultIteratorFunctioin(int value){
  printf("%d\n", value);
}

Position makeNode(int value){
  Position node = (Position)malloc(TREE_NODE_SIZE);
  node->value = value;
  node->left = node->right = NULL;
  return node;
}

BinaryTree makeTree(int *array, int size){
  BinaryTree tree = NULL;
  for(int i = 0;i < size;i++){
    tree = insertTree(tree, array[i]);
  }
  return tree;
}

BinaryTree insertTree(BinaryTree tree, int value){
  if(!tree)
    return makeNode(value);
  if(tree->value > value)
    tree->left = insertTree(tree->left, value);
  else
    tree->right = insertTree(tree->right, value);
  return tree;
}

//后序遍历
void iterateTree(BinaryTree tree){
  if(tree->left)
    iterateTree(tree->left);

  if(tree->right)
    iterateTree(tree->right);

  defaultIteratorFunctioin(tree->value);
}

Position findTreeNode(BinaryTree tree, int value){
  if(!tree) return NULL;
  if(tree->value > value)
    return findTreeNode(tree->left, value);
  if(tree->value < value)
    return findTreeNode(tree->right, value);
  return tree;
}

Position findMin(BinaryTree tree){
  if(tree)
    while(tree->left)
      tree = tree->left;
  return tree;
}

Position findMax(BinaryTree tree){
  if(tree)
    while(tree->right)
      tree = tree->right;
  return tree;
}

Position deleteTreeNode(BinaryTree tree, int value){
  Position node;
  if(!tree)
    return NULL;
  else
  if(tree->value > value)
    tree->left = deleteTreeNode(tree->left, value);
  else
  if(tree->value < value)
    tree->right = deleteTreeNode(tree->right, value);
  else
  if(tree->left && tree->right){
    node = findMin(tree->right);
    tree->value = node->value;
    tree->right = deleteTreeNode(tree->right, tree->value);
  }else{
    node = tree;
    if(!tree->left)
      tree = tree->right;
    else
    if(!tree->right)
      tree = tree->left;
    free(node);
  }
  return tree;
}
