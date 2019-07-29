#ifndef BTREE_H
#define BTREE_H

struct TreeNode
{
  char character;
  int height;
  struct TreeNode* left;
  struct TreeNode* right;
};

/* Creates and allocates memory for a new node in the tree. */
struct TreeNode* createNode(char character);

/* This is a recursive function that inserts a char node into the tree in
 level-order, linking available nodes to it if applicable.  */
struct TreeNode* insertIntoTree(struct TreeNode* root, char* charArr, int start, int size);

/* Recursive function that gets the depth of tree.
   Empty tree has depth 0. */
int getDepth(struct TreeNode* root);

/* Performs a pre-order traversal in order to find matching
   characters in the tree and printing the location. */
int findChar (struct TreeNode* root, char c, int timesFound);

/* Given the root, prints the tree in pre-order.
  The print format is: the character in that node and in parens, the
  'number' of the node in order of insertion starting with 1. */
int printPreorder (struct TreeNode* root);

/* Prints the visual tree with edges.
   This function was created by Wayne Just for CS241 Summer 2019.
   The function was slightly modified in order to calculate the maxLeaves
   and to print to a specified output (stdout or file). */
void printVisualTree(char* string, FILE* out);

/* Frees the memory used by the tree */
void freeTree(struct TreeNode* root);

#endif
