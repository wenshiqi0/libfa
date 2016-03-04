#include "../include/tree.h"

//default function for iterating
void defaultIteratorFunctioin(int value){
  printf("%d\n", value);
}

/**********
realization for binary tree operation
**********/
Position makeNode(int value){
  Position node = (Position)malloc(TREE_NODE_SIZE);
  if(!node){
    perror("malloc failed");
    exit(0);
  }
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

//postorder traversal
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

/**********
end
**********/


/**********
realization for AVL tree operation
**********/
static int AVLHeight(AVLPosition node){
  if(!node)
    return -1;
  else
    return node->height;
}

AVLTree singleRotateRightAVL(AVLPosition k1){
  AVLPosition k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;

  k1->height = MAX(AVLHeight(k1->left), AVLHeight(k1->right)) + 1;
  k2->height = MAX(AVLHeight(k2->left), AVLHeight(k2->right)) + 1;
  return k2;
}

AVLTree singleRotateLeftAVL(AVLPosition k2){
  AVLPosition k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;

  k1->height = MAX(AVLHeight(k1->left), AVLHeight(k1->right)) + 1;
  k2->height = MAX(AVLHeight(k2->left), AVLHeight(k2->right)) + 1;
  return k1;
}

AVLTree doubleRotateRightAVL(AVLPosition k3){
  k3->right = singleRotateLeftAVL(k3->right);
  return singleRotateRightAVL(k3);
}

AVLTree doubleRotateLeftAVL(AVLPosition k3){
  k3->left = singleRotateRightAVL(k3->left);
  return singleRotateLeftAVL(k3);
}

AVLPosition makeAVLNode(int value){
  AVLPosition node = (AVLPosition)malloc(AVLTREE_NODE_SIZE);
  if(!node){
    perror("malloc failed");
    exit(0);
  }
  node->value = value;
  node->height = 0;
  node->left = node->right = NULL;
  return node;
}

AVLTree makeAVLTree(int *array, int size){
  AVLTree tree = NULL;
  for(int i = 0;i < size;i++){
    tree = insertAVLTree(tree, array[i]);
  }
  return tree;
}

AVLTree insertAVLTree(AVLTree tree, int value){
  if(!tree)
    return makeAVLNode(value);
  else
  if(tree->value > value){
    tree->left = insertAVLTree(tree->left, value);
    if(AVLHeight(tree->left) - AVLHeight(tree->right) == 2){
      if(tree->left->value > value)
        tree = singleRotateLeftAVL(tree);
      else
        tree = doubleRotateLeftAVL(tree);
    }
  }else
  if(tree->value < value){
    tree->right = insertAVLTree(tree->right, value);
    if(AVLHeight(tree->right) - AVLHeight(tree->left) == 2){
      if(tree->right->value < value)
        tree = singleRotateRightAVL(tree);
      else
        tree = doubleRotateRightAVL(tree);
    }
  }

  tree->height = MAX(AVLHeight(tree->left), AVLHeight(tree->right)) + 1;
  return tree;
}

AVLPosition findAVLTreeNode(AVLTree tree, int value){
  if(!tree) return NULL;
  if(tree->value > value)
    return findAVLTreeNode(tree->left, value);
  if(tree->value < value)
    return findAVLTreeNode(tree->right, value);
  return tree;
}

AVLPosition findAVLMin(AVLTree tree){
  if(tree)
    while(tree->left)
      tree = tree->left;
  return tree;
}

AVLPosition findAVLMax(AVLTree tree){
  if(tree)
    while(tree->right)
      tree = tree->right;
  return tree;
}

AVLPosition deleteAVLTreeNode(AVLTree tree, int value){
  
}

//postorder traversal
void iterateAVLTree(AVLTree tree){
  if(tree->left)
    iterateAVLTree(tree->left);

  if(tree->right)
    iterateAVLTree(tree->right);

  defaultIteratorFunctioin(tree->value);
}

/**********
end
**********/
