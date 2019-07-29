/*	Name: Richard Tran
 * 	Date: July 22, 2019
 * 	Class: CS241L SUM 2019
 *
 *	This file is responsible for parsing user input from stdin and 
 *	executing the proper commands based on the input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"
#include "bTree.h"

#define ASSIGNMENT_NUM 5
#define BUFFER_SIZE 100
void parse () 
{
	struct TreeNode* tree = NULL;
	char line[BUFFER_SIZE];

	char delim[2] = " ";
	char *token;
	char *stringOfCharacters;

	printf("Command: ");

	while (fgets(line, BUFFER_SIZE, stdin) != NULL)
	{	
		/* Takes off the new line character at the end and replaces it
			with null terminator. */
		if ((line[0] != '\0') && (line[strlen(line) -1] == '\n'))
		{
            line[strlen(line) -1] = '\0';
        }

        /* I left this in so that the user can see the command when feeding
        	a text file into the program. (aka when using ./main < input.txt 
        */
		printf("Echoing line: %s\n", line);
		
		token = strtok(line, delim);
		
		/* Create command */
		if (!strcmp(token, "Create") || !strcmp(token, "create"))
		{	
			token = strtok(NULL, delim);
			/* Added the +1 to malloc in order to include null terminator. */
			stringOfCharacters = malloc(sizeof(char) * strlen(token)+1);
			memcpy(stringOfCharacters, token, sizeof(char)*strlen(token)+1);
			tree = insertIntoTree(tree, token, 0, strlen(token));
			printf("Create Executed Successfully.\n");
		}
		/* Author command */
		else if (!strcmp(token, "Author") || !strcmp(token, "author"))
		{
			printName(ASSIGNMENT_NUM);
		}
		/* Clear command */
		else if (!strcmp(token, "Clear") || !strcmp(token, "clear"))
		{
			freeTree(tree);
			free(stringOfCharacters);
			tree = NULL;
			printf("Clear Executed Successfully.\n");
		}

		/* Exit command. Frees the list memory and exits the program.*/
		else if (!strcmp(token, "Exit") || !strcmp(token, "exit"))
		{
			printf("Exiting program...\n");
			/* Doesn't free the memory if clear was called before it.
				Reduces seg fault error. */
			if (tree != NULL)
			{
				freeTree(tree);
				tree = NULL;
				free(stringOfCharacters);
			}
			exit(1);
		}

		/* Depth command. Prints the depth of the tree. */
		else if (!strcmp(token, "Depth") || !strcmp(token, "depth"))
		{
			printf("Depth: %d\n", getDepth(tree) - 1);
		}
		else if (!strcmp(token, "Find") || !strcmp(token, "find"))
		{	
			token = strtok(NULL, delim);
			if (!findChar(tree, token[0], 0))
			{
				printf("Character not found in tree.\n");
			}
		}
		/* Help command. Prints the help text. */
		else if (!strcmp(token, "Help") || !strcmp(token, "help"))
		{
			printHelp();
		}
		/* IsEmpty command. Outputs if the tree is empty or not. */
		else if (!strcmp(token, "IsEmpty") || !strcmp(token, "isempty"))
		{
			if (getDepth(tree))
			{
				printf("FALSE\n");
			}
			else
			{
				printf("TRUE\n");
			}
		}
		/* BONUS COMMAND. Prints the tree in Pre-Order along with the node number
		   in parenthesis. */
		else if (!strcmp(token, "Print") || !strcmp(token, "print"))
		{
			printf("Printing Pre-Order: ");
			printPreorder(tree);
			printf("\n");
		}
		/* FPrint command. Prints the tree to an output file named TreeOutput.txt */
		else if (!strcmp(token, "FPrint") || !strcmp(token, "fprint"))
		{
			FILE *file;

			if ((file = fopen("TreeOutput.txt", "w")) == NULL)
			{
				fprintf(stderr, "Cannot open file TreeOutput.txt\n");
				exit(1);
			}

  			printf("Program output written to file TreeOutput.txt.\n");

  			/* Prints the output of this function to the file */
  			printVisualTree(stringOfCharacters, file);
  			fclose(file);
		}
		/* SPrint command. Prints the tree to the screen.*/
		else if (!strcmp(token, "SPrint") || !strcmp(token, "sprint"))
		{
			printVisualTree(stringOfCharacters, stdout);
		}

		/* If no matched command, outputs invalid command. */
		else
		{
			printf("Invalid command. Please type \"Help\" or \"help\" to view available commands.\n");
		}
		
		printf("Command: ");
	}
}