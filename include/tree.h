#ifndef _TREE_H_
#define _TREE_H_

#include "header.h"

//defination for Binary tree
struct TreeNode{
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *BinaryTree;
typedef struct TreeNode *Position;

#define TREE_SIZE sizeof(struct TreeNode)
#define TREE_NODE_SIZE sizeof(struct TreeNode)

//defination for AVL tree
struct AVLTreeNode{
  int value;
  struct AVLTreeNode *left;
  struct AVLTreeNode *right;
  int height;
};

typedef struct AVLTreeNode *AVLTree;
typedef struct AVLTreeNode *AVLPosition;

#define AVLTREE_SIZE sizeof(struct AVLTreeNode)
#define AVLTREE_NODE_SIZE sizeof(struct AVLTreeNode)

//Operation for Binary tree
extern Position makeNode(int value);
extern BinaryTree makeTree(int *array, int size);
extern BinaryTree insertTree(BinaryTree tree, int value);
extern void iterateTree(BinaryTree tree);
extern Position findTreeNode(BinaryTree tree, int value);
extern Position findMin(BinaryTree tree);
extern Position findMax(BinaryTree tree);
extern Position deleteTreeNode(BinaryTree tree, int value);

//Operation for AVL tree
extern AVLPosition makeAVLNode(int value);
extern AVLTree makeAVLTree(int *array, int size);
extern AVLTree insertAVLTree(AVLTree tree, int value);
extern void iterateAVLTree(AVLTree tree);
extern AVLPosition findAVLTreeNode(AVLTree tree, int value);
extern AVLPosition findAVLMin(AVLTree tree);
extern AVLPosition findAVLMax(AVLTree tree);
extern AVLPosition deleteAVLTreeNode(AVLTree tree, int value);

#endif
