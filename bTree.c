/*  Name: Richard Tran
 *  Date: July 22, 2019
 *  Class: CS241L SUM 2019
 *
 *  This is the main driver program for binary tree functions.
 *  Also consists of some helper functions for binary tree functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bTree.h"

/* Creates and allocates memory for a new node in the tree. */
struct TreeNode* createNode(char character)
{
  struct TreeNode* node = malloc(sizeof(struct TreeNode));
  node -> character = character;
  node -> left = NULL;
  node -> right = NULL;
  
  return node;
}

/* This is a recursive function that inserts a char node into the tree in
 level-order, linking available nodes to it if applicable.  */
struct TreeNode* insertIntoTree(struct TreeNode* root, char* charArr, int start, int size)
{
  struct TreeNode* node = NULL;
  int left;
  int right;
  /*Left is 2 * i + 1*/
  left = 2*start + 1;
  /*Right is 2 * i + 2*/
  right = 2*start + 2;

  if (left > size || right > size)
  {
    return root;
  }

  /* If the tree is empty, assign root to the first created node */
  if (root == NULL)
  {
    node = createNode(charArr[start]);
    node->height = 1;
    root = node;
  }

  /* Otherwise check for an available spot by traversing the tree. */
  if(root->left == NULL && root->right == NULL)
  {
    if (left < size)
    {
      root->left = createNode(charArr[left]);
      /* Assign the 'number' of each node which will be used
         later to calculate height. */
      root->left->height = left+1;
    }
    if (right < size)
    {
      root->right = createNode(charArr[right]);
      /* Assign the 'number' of each node which will be used
         later to calculate height. */
      root->right->height = right+1;
    }
  }

  /* Recurse itself over left and right sides. */ 
  insertIntoTree(root->left, charArr, left, size);
  insertIntoTree(root->right, charArr, right, size);

  return root;
}

/* Recursive function that gets the depth of tree.
   Empty tree has depth 0. */
int getDepth(struct TreeNode* root)
{
  int depth = 0;
  if(!root)
  {
    return depth;
  }
  if(root->left && root->right)
  {
    int leftDepth = 0;
    int rightDepth = 0;
    leftDepth = getDepth(root->left);
    rightDepth = getDepth(root->right);
    
    if(leftDepth > rightDepth)
    {
      depth = depth + leftDepth;
    }
    else
    {
      depth = depth + rightDepth;
    }
  }
  if (root->left && !(root->right))
  {
    depth = depth + getDepth(root->left);
  }
  if (!(root->left) && root->right)
  {
    depth = depth + getDepth(root->right);
  }
  depth++;
  return depth;
}

/* Helper function for findChar which applies log2(nodeNumber)
   in order to give the level of which a particular node is located. */
int calculateLevel(int num)
{
  int result = log(num)/log(2);
  return floor(result);
}

/* Performs a pre-order traversal in order to find matching
   characters in the tree and printing the location. */
int findChar (struct TreeNode* root, char c, int timesFound)
{
  int count = timesFound;
  int leftRes = 0;
  int rightRes = 0;
  int location = 0;
  if (root == NULL)
  {
    return count;
  }
  if (root->character == c)
  {
    count++;
    location = calculateLevel(root->height);
    printf("Found %c at level: %d\n", c, location);
  }

  leftRes = findChar(root->left, c, count);
  rightRes = findChar(root->right, c, count);
  return (leftRes || rightRes);
}

/* Given the root, prints the tree in pre-order.
  The print format is: the character in that node and in parens, the
  'number' of the node in order of insertion starting with 1. */
int printPreorder (struct TreeNode* root)
{
  if (root == NULL)
  {
      return 0;
  }
  printf("%c(%d) ", root->character, root->height);

  printPreorder(root->left);
  printPreorder(root->right);
  return 0;
}

/* Prints the spaces, used by printVisualTree function.
  This function was created by Wayne Just for CS241 Summer 2019.*/
void printSpaces (int spaces, FILE* out)
{
  int i;
  for (i = 0; i < spaces; i++)
  {
    fprintf(out, " ");
  }
}

/* Prints the edges for the visual tree output used by printVisualTree function.
  This function was created by Wayne Just for CS241 Summer 2019.*/
void printEdges(int spaces, int children, FILE* out)
{
  int counter;
  int even;

  counter = 0;
  even = 1;

  while (counter < children)
  {
    if (even)
    {
      printSpaces(spaces - 1, out);
      fprintf(out, "/");
      even = 0;
    }
    else
    {
      printSpaces(spaces - 1, out);
      fprintf(out, "\\");

      even = 1;
    }
    printSpaces(spaces, out);
    counter++;
  }
  fprintf(out, "\n");
}

/* Prints the visual tree with edges.
   This function was created by Wayne Just for CS241 Summer 2019.
   The function was slightly modified in order to calculate the maxLeaves
   and to print to a specified output (stdout or file). */
void printVisualTree(char* string, FILE* out)
{
  int maxLeaves;
  int nodes;
  int i;
  int j;
  int level;
  int spaces;
  int children;

  /* The value of maxLeaves is determined by the number of nodes.
     The values up to 63 maxiumum nodes in the string have been calculated
     below.
      MaxLeaves     numNodes 
        1               1
        2               1 < n <= 3 
        4               3 < n <= 7
        8               7 < n <= 15 
        16              15 < n <= 31 
        32              31 < n <= 63 
  */
  nodes = strlen(string);
  level = 0;
  i = 0;

  if (nodes == 1)
  {
    maxLeaves = 1;
  }
  else if (nodes <= 3)
  {
    maxLeaves = 2;
  }
  else if (nodes <= 7)
  {
    maxLeaves = 4;
  }
  else if (nodes <= 15)
  {
    maxLeaves = 8;
  }
  else if (nodes <= 31)
  {
    maxLeaves = 16;
  }
  else if (nodes <= 63)
  {
    maxLeaves = 32;
  }

  /* While loop that iterates through the string. */
  while (i < nodes)
  {
        j = 0;
        /* If it is the first level, the amount of spaces 
          is determined by the maxLeaves multiplied by 2. */
        if (level == 0)
        {
            spaces = maxLeaves * 2;
            printSpaces(spaces - 1, out);
            fprintf(out, "%c\n", string[i]);
            level++;
            i++;
        }
        /* Otherwise, the number of children need to be calculated and
          the amount of edges per line as well as the number of spaces 
          between them will need to be determined. */
        else 
        {
            spaces = spaces / 2;
            if (level == 1)
            {
                children = 2;
            }
            else children = children * 2;

            printEdges(spaces, children, out);

            while (j < children && (j + i) < nodes) 
            {
                printSpaces (spaces - 1, out);
                fprintf(out, "%c", string[j + i]);
                printSpaces (spaces, out);
                j++;
            }
            i = i + j;
            fprintf(out, "\n");
            level++;
        }
    }
    fprintf(out, "\n");
}

/* Frees the memory used by the tree */
void freeTree(struct TreeNode* root)
{
  if(root->left)
  {
    freeTree(root->left);
  }
  if(root->right)
  {
    freeTree(root->right);
  }
  free(root);
}

