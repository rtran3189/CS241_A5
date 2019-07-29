/*	Name: Richard Tran
 * 	Date: July 22, 2019
 * 	Class: CS241L SUM 2019
 *
 *	This file includes helper functions used for the assignment and
 *	for printing helpful feedback for the user.
 */

#include <stdio.h>
#include <limits.h>

/*
 * Prints a banner containing Name, Course, Date, and Assignment number
 * based on the specified format from class.
 */
void printName(int assignmentNum)
{
	printf("\n\n");
	printf("/**********************************************/\n");
	printf("/*Name: Richard Tran                          */\n");
	printf("/*Course: CS241L Summer 2019                  */\n");
	printf("/*Date: July 22, 2019                         */\n");
	printf("/*Assignment: %d                               */\n", assignmentNum);
	printf("/**********************************************/\n");
}

/*
 * Print information on how torun the program. 
 * This information may be the same information
 * you included in your readme file.
 */
void printHelp()
{
	printf("\n-----------------HELP-----------------\n");
	printf("The program will take a command from its interface input as the program is running.\n");
	printf("The program will print: \n");
	printf("\t Command: \n");
	printf("when it is ready for the next command. To enter the command just\n");
	printf("type one of the following commands: \n");
	printf("\n\t Create <followed by the word> \n");
	printf("\t\t Adds characters of that word into the binary tree.\n");
	printf("\t\t Example: Create averylongwordbutlimitedto50characters\n");
	printf("\n\t Author \n");
	printf("\t\t Prints author information.\n");
	printf("\n\t Clear \n");
	printf("\t\t Removes all elements of the tree\n");
	printf("\n\t Depth \n");
	printf("\t\t Returns the depth of the tree. Returns 0 if empty.\n");
	printf("\n\t Exit \n");
	printf("\t\t Exits the program.\n");
	printf("\n\t Find <followed by the char to find> \n");
	printf("\t\t Returns the location in the tree where that char can be found.\n");
	printf("\t\t Example: Found <char> at heights <instance 1>, <instance 2>, etc...\n");
	printf("\t\t Otherwise reurns \"Char not found\" if char is not in the tree.\n");
	printf("\n\t Help \n");
	printf("\t\t Prints this help information.\n");
	printf("\n\t IsEmpty \n");
	printf("\t\t Returns TRUE if there is nothing in the tree. Otherwise FALSE is returned.\n");
	printf("\n\t Print \n");
	printf("\t\t Prints the tree in pre-order. \n");
	printf("\t\t The print format is: the character in that node and in parens, the\n");
  	printf("\t\t 'number' of the node in order of insertion starting with 1.\n");
	printf("\n\t SPrint \n");
	printf("\t\t Prints the tree to the screen. \n");
	printf("\t\t Credit for this function towards Wayne Just for class CS241L Summer 2019.\n");
	printf("\n\t FPrint\n");
	printf("\t\t Prints the tree to a file. The file name is 'TreeOutput.txt'.\n");
	printf("\t\t This file is written to the same directory as the program.\n");
	printf("--------------------------------------\n\n");

}	