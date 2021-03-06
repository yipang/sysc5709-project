# sysc5709-project
### RNA Sequence Comparison by Needleman-Wunsch Algorithm ###

**Organization: Carleton University**

**Authors: Siyu Zhou, Yi Pang**

**Description:**
Recently, coronavirus is exploding in China, and has a trend of spreading over the world. The rapid mutation and unavailable targeted drugs determine the high order of severity. Due to the threat from it, identifying mutation in RNA sequences of Coronavirus seems a great step on how to conquer this problem.

Ribonucleic acid (RNA) is a polymeric molecule essential in various biological roles in coding decoding, regulation and expression of genes. It is assembled as a single strand chain of nucleotides conveying genetic information using nitrogenous bases of guanine (G), uracil (U), adenine (A) and Cytosine (C) in certain orders.  The purpose of the project is to take input of two sequences (consist of ‘GUAC’) of RNA from the user, calculate the match score and analyze the relativity between two sequences by using Needleman-Wunsch Algorithm. The software output will give the details about the relativity of two RNA sequences by showing the rearranged RNA sequences and calculate two dimension matrix based on Needleman-Wunsch Algorithm.

****

**Source File Organization**

+ /bin contains executable files project tests, generated at runtime
+ /build contains object files check\_input.o, get\_align.o, get\_max.o, matrix\_builder.o, generated at runtime
+ /data contains data used for inputs: data1.txt
+ /doc includes documentations user\_manual.pdf and project\_description.pdf
+ /include contains all the header files: check\_input.h, get\_align.h, get\_max.h, matrix\_builder.h
+ /src contains all the source files: check\_input.c, get\_align.c get\_max.c, main.c, matrix\_builder.c
+ /test
	+ /include contains header files
	+ /data logfile generated by unit tests: log.txt
	+ /src contains the unit test source file: unit\_testing.c		
+ makefile
+  README.md

****

**Dependencies**

main.c: matrix_builder.h get_align.h get_max.h check_input.h
check_input.c: check_input.h
get_max: get_max.h
matrix_builder.c: matrix_builder.h get_max.h
get_align.c: get_align.h get_max.h

**Instructions**

Detailed instructions about how to run this program and description about the project and NW algorithm can be found in user\_manual.pdf and project\_description.pdf under /doc folder. 