Name: Richard Tran
Assignment: 5
Course: CS241L Summer 2019
Date: July 22 2019

USEFUL INFO : - Using valgrind --leak-check=full ./main results in no memory leaks, at least on my machine. Also no leaks on the bTreeTest (test file).
              - For an unknown reason, the program does not recognize the input file commands without the dummy args even though it is based off the previous assignment where my input file worked without dummy args. When running the program "manually", input does NOT require dummyargs! Refer to sample INPUT/OUTPUT section of this readme. The input file is not for a grade so I did not spend time fixing this. It is mostly for you to run to see that every command works.
              - Added an additional command 'Print' which will print the tree in a pre-order way which includes the char's node number in parenthesis.

Directory: Top
Compile Command: make main
                    OR    
                 gcc -Wall -ansi -pedantic -g -o main main.c bTree.c help.c parse.c -lm && ./main

Run Command: ./main

Run Command with input.txt: ./main < input.txt

Running Test: make bTreeTest && ./bTreeTest        
                    OR 
              gcc -Wall -ansi -pedantic -g -o bTreeTest bTree.c bTreeTest.c -lm && ./bTreeTest

Bugs:
	- Hitting the return key as the command with no other input will seg fault the program.

How to use:
-----------------HELP-----------------
The program will take a command from its interface input as the program is running.
The program will print:
         Command:
when it is ready for the next command. To enter the command just
type one of the following commands:

         Create <followed by the word>
                 Adds characters of that word into the binary tree.
                 Example: Create averylongwordbutlimitedto50characters

         Author
                 Prints author information.

         Clear
                 Removes all elements of the tree

         Depth
                 Returns the depth of the tree. Returns 0 if empty.

         Exit
                 Exits the program.

         Find <followed by the char to find>
                 Returns the location in the tree where that char can be found.
                 Example: Found <char> at level <instance 1>, <instance 2>, etc...
                 Otherwise reurns "Char not found" if char is not in the tree.

         Help
                 Prints this help information.

         IsEmpty
                 Returns TRUE if there is nothing in the tree. Otherwise FALSE is returned.

         Print
                 Prints the tree in pre-order.
                 The print format is: the character in that node and in parens, the 'number' of the node in order of insertion starting with 1.

         SPrint
                 Prints the tree to the screen. Credit for this function towards Wayne Just for class CS241L Summer 2019.

         FPrint
                 Prints the tree to a file. The file name is 'TreeOutput.txt'.
--------------------------------------

SAMPLE INPUT AND OUTPUTS:
You can run the following commands in order:
Help
Author
IsEmpty
create abcdefghijklmnopqrstuvwxyz
IsEmpty
sprint
find b
print
depth
fprint
clear
exit



valgrind --leak-check=full ./main
==276== Memcheck, a memory error detector
==1307== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1307== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==1307== Command: ./main
==1307==
==1307== error calling PR_SET_PTRACER, vgdb might block
Command: IsEmpty
Echoing line: IsEmpty
TRUE
Command: Create abcdefghijklmnopqrstuvwxyz
Echoing line: Create abcdefghijklmnopqrstuvwxyz
Create Executed Successfully.
Command: IsEmpty
Echoing line: IsEmpty
FALSE
Command: SPrint
Echoing line: SPrint
                               a
               /                               \
               b                               c
       /               \               /               \
       d               e               f               g
   /       \       /       \       /       \       /       \
   h       i       j       k       l       m       n       o
 /   \   /   \   /   \   /   \   /   \   /   \   /   \   /   \
 p   q   r   s   t   u   v   w   x   y   z

Command: Find b
Echoing line: Find b
Found b at level: 1
Command: Print
Echoing line: Print
Printing Pre-Order: a(1) b(2) d(4) h(8) p(16) q(17) i(9) r(18) s(19) e(5) j(10) t(20) u(21) k(11) v(22) w(23) c(3) f(6) l(12) x(24) y(25) m(13) z(26) g(7) n(14) o(15)
Command: Depth
Echoing line: Depth
Depth: 4
Command: FPrint
Echoing line: FPrint
Program output written to file TreeOutput.txt.
Command: Clear
Echoing line: Clear
Clear Executed Successfully.
Command: exit
Echoing line: exit
Exiting program...
==1307==
==1307== HEAP SUMMARY:
==1307==     in use at exit: 0 bytes in 0 blocks
==1307==   total heap usage: 31 allocs, 31 frees, 13,491 bytes allocated
==1307==
==1307== All heap blocks were freed -- no leaks are possible
==1307==
==1307== For counts of detected and suppressed errors, rerun with: -v
==1307== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)









valgrind --leak-check=full ./bTreeTest
==1314== Memcheck, a memory error detector
==1314== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1314== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==1314== Command: ./bTreeTest
==1314==
==1314== error calling PR_SET_PTRACER, vgdb might block
OK - Tree Empty
OK - Tree Not Empty
OK - Get Depth
                               t
               /                               \
               h                               i
       /               \               /               \
       s               i               s               a
   /       \       /       \       /       \       /       \
   t       e       s       t       t       o       f       i
 /   \   /   \   /   \   /   \   /   \   /   \   /   \   /   \
 n   d   m   u   l   t   i   p   l   e   c   h   a   r   s

OK? - Find Char: Found t at level: 0
Found t at level: 3
Found t at level: 4
Found t at level: 3
Found t at level: 3
OK? - Print Pre-order Tree: a(1) b(2) d(4) h(8) p(16) q(17) i(9) r(18) s(19) e(5) j(10) t(20) u(21) k(11) v(22) w(23) c(3) f(6) l(12) x(24) y(25) m(13) z(26) g(7) n(14) o(15)
OK? - Print Visual Tree:
                               a
               /                               \
               b                               c
       /               \               /               \
       d               e               f               g
   /       \       /       \       /       \       /       \
   h       i       j       k       l       m       n       o
 /   \   /   \   /   \   /   \   /   \   /   \   /   \   /   \
 p   q   r   s   t   u   v   w   x   y   z

==1314==
==1314== HEAP SUMMARY:
==1314==     in use at exit: 0 bytes in 0 blocks
==1314==   total heap usage: 139 allocs, 139 frees, 7,408 bytes allocated
==1314==
==1314== All heap blocks were freed -- no leaks are possible
==1314==
==1314== For counts of detected and suppressed errors, rerun with: -v
==1314== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)