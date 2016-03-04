#ifndef _TREE_H_
#define _TREE_H_

#include "header.h"

struct TreeNode{
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *BinaryTree;
typedef struct TreeNode *Position;

#define TREE_PTR_SIZE sizeof(struct TreeNode)
#define TREE_NODE_SIZE sizeof(struct TreeNode)

extern BinaryTree initTree();

extern Position makeNode(int value);

extern BinaryTree makeTree(int *array, int size);

extern BinaryTree insertTree(BinaryTree tree, int value);

extern void iterateTree(BinaryTree tree);

extern Position findTreeNode(BinaryTree tree, int value);

extern Position findMin(BinaryTree tree);

extern Position findMax(BinaryTree tree);

extern Position deleteTreeNode(BinaryTree tree, int value);

#endif
