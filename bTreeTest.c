/*  Name: Richard Tran
 *  Date: July 22, 2019
 *  Class: CS241L SUM 2019
 *
 *  This is the test file that tests the various functions of
 *  the binary tree file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bTree.h"

/* Tests if getDepth knows when the tree is empty. */
void testTreeEmpty()
{
  struct TreeNode* root = NULL;
  if (getDepth(root))
  {
    printf("FAIL - Tree Empty\n");
  }
  else
  {
    printf("OK - Tree Empty\n");
  }
}

/* Tests if getDepth knows when the tree is occupied. */
void testTreeNotEmpty()
{
  struct TreeNode* root = NULL;
  char words[] = "abcdefghijklmnopqrstuvwxyz";
  root = insertIntoTree(root, words, 0, strlen(words));

  if (getDepth(root) == 0)
  {
    printf("FAIL - Tree Not Empty\n");
  }
  else
  {
    printf("OK - Tree Not Empty\n");
  }
  freeTree(root);
}

/* Tests if getDepth gets the proper depth of the tree. */
void testGetDepth()
{
  struct TreeNode* root = NULL;
  char words[] = "reallylongwordshouldhavedepth5";
  root = insertIntoTree(root, words, 0, strlen(words));

  if (getDepth(root) == 5)
  {
    printf("OK - Get Depth\n");
  }
  else
  {
    printf("FAIL - Get Depth\n");
  }
  freeTree(root);
}

/* Tests if findChar is able to find characters in the tree. */
void testFindChar()
{
  struct TreeNode* root = NULL;
  char words[] = "thisisatesttofindmultiplechars";
  printVisualTree(words, stdout);
  root = insertIntoTree(root, words, 0, strlen(words));
  printf("OK? - Find Char: ");
  findChar(root, 't', 0);
  freeTree(root);
}

/* Tests if printing the tree in pre-order works correctly. 
   Needs to be visually inspected. */
void testPrintPreOrderTree()
{
  struct TreeNode* root = NULL;
  char words[] = "abcdefghijklmnopqrstuvwxyz";
  root = insertIntoTree(root, words, 0, strlen(words));
  printf("OK? - Print Pre-order Tree: ");
  printPreorder(root);
  freeTree(root);
}

/* Tests if printing the tree visually works correctly.
    Needs to be visually inspected. */
void testPrintVisualTree()
{
  struct TreeNode* root = NULL;
  char words[] = "abcdefghijklmnopqrstuvwxyz";
  root = insertIntoTree(root, words, 0, strlen(words));
  printf("\nOK? - Print Visual Tree: \n");
  printVisualTree(words, stdout);
  freeTree(root);
}

int main(int argc, char** argv)
{
  testTreeEmpty();
  testTreeNotEmpty();
  testGetDepth();
  testFindChar();
  testPrintPreOrderTree();
  testPrintVisualTree();

  return 0;
}
