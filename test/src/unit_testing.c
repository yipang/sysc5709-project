/* Unit testing file for functions matrix_builder, get_align and get_max */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "get_align.h"
#include "matrix_builder.h"
#include "get_max.h"
#include "check_input.h"

int main(){
	char logfile[100] = "./test/data/log";
	FILE *fp = fopen(logfile, "w");
	char seq1_align[100] = "\0";
	char seq2_align[100] = "\0";
	int scores[50][50] = {0};
	int result = 0;
	int result1 = 0;
	int index1 = 0;
	int index2 =0;


	/* Test cases for get_align function */
	fprintf(fp,"Test case for get_align function.\n\n");
	/**
 	 * The following test cases check if the length of seq1_align is equal
	 * to seq2_align.
	 */
	fprintf(fp,"The following test cases check if the length of seq1_align is equal to seq2_align.\n");
	/* Test case 1 */
	fprintf(fp,"Test case 1\n");
	get_align("AUUGAGCC", "UAAUC", 2, 1, 1, seq1_align,seq2_align,scores);
	/* Column check */
	for(int i = 0;i < 100;i++){
		if(seq1_align[i]!=0){
			index1 = i;
		}
	}
	/* Row check */
	for(int j = 0;j < 100;j++){
		if(seq2_align[j]!=0){
			index2 = j;
		}
	}
	/* Compare the length of two sequences. */
	result = index1 - index2;
	fprintf(fp,"result: %d, expected: 0\n", result);
	fprintf(fp,"\n");
	/* Test case 2 */
	fprintf(fp,"Test case 2\n");
	memset( seq1_align, 0, sizeof(seq1_align));
	memset( seq2_align, 0, sizeof(seq1_align));

	result = 0;
	get_align("GUAUACU", "UAGGUC", 2, 2, 4, seq1_align,seq2_align,scores);
	/* Column check */
	for(int i = 0;i < 100;i++){
		if(seq1_align[i]!=0){
			index1 = i;
		}
	}

	/* Row check */
	for(int j = 0;j < 100;j++){
		if(seq2_align[j]!=0){
			index2 = j;
		}
	}
	/* Compare the length of two sequences. */
	result = index1 - index2;
	fprintf(fp,"result: %d, expected: 0\n", result);
	fprintf(fp,"\n");
	/* Test case 3 */
	fprintf(fp,"Test case 3\n");
	result = 0;
	get_align("GAUACCC", "UAUC", 3, 1, 2, seq1_align,seq2_align,scores);
	/* Column check */
	for(int i = 0;i < 100;i++){
		if(seq1_align[i]!=0){
			index1 = i;
		}
	}

	/* Row check */
	for(int j = 0;j < 100;j++){
		if(seq2_align[j]!=0){
			index2 = j;
		}
	}
	/* Compare the length of two sequences. */
	result = index1 - index2;
	fprintf(fp,"result: %d, expected: 0\n", result);
	fprintf(fp,"\n");	

	/* The following test cases check if the results of seq1_align and seq2_align are correct.*/
	fprintf(fp,"The following test cases check if the length of seq1_align is equal to seq2_align.\n");
	/* Test case 4 */
	fprintf(fp,"Test case 4\n");
	memset( seq1_align, 0, sizeof(seq1_align));
	memset( seq2_align, 0, sizeof(seq1_align));
	result = 0;
	/* compare1 and compare2 are the expected value. */
	char compare1[11] = "CCGAGUU----";
	char compare2[11] = "------CUAAU";
	get_align("AUUGAGCC", "UAAUC", 2, 1, 1, seq1_align,seq2_align,scores);
	/* Compare the characters one by one */
	for(int i=strlen(seq1_align);i>=0;i--){
		if(seq1_align[i]!=compare1[i]){
			result1 = -1;
			break;
		}
	}
	for(int i=0;i<strlen(seq2_align)-1;i++){
		if(seq2_align[i]!=compare2[i]){
			result1 = -1;
			break;
		}
	}
	fprintf(fp,"result: %d, expected: 0\n", result);
	fprintf(fp,"result: %d, expected: 0\n", result1);
	fprintf(fp,"\n");

	/* Test case 5 */
	fprintf(fp,"Test case 5\n");
	memset( seq1_align, 0, sizeof(seq1_align));
	memset( seq2_align, 0, sizeof(seq1_align));
	result = 0;
	char compare3[50] = "--ACGU-GUA";
	char compare4[50] = "UGACAUA---";
	get_align("ACGUGUA", "ACAUA", 2, 5, 1, seq1_align,seq2_align,scores);
	for(int i=0;i<strlen(seq1_align);i++){
		if(seq1_align[i]!=compare3[i]){
			result = -1;
		}
		result = 0;
	}
	for(int i=0;i<strlen(seq2_align);i++){
		if(seq2_align[i]!=compare4[i]){
			result1 = -1;
		}
		result1 = 0;
	}
	fprintf(fp,"result: %d, expected: 0\n", result);
	fprintf(fp,"result: %d, expected: 0\n", result1);
	fprintf(fp,"\n");

	
	/* Test cases for check_input function */
	fprintf(fp,"Test cases for check_input function.\n\n");
	/**
	 * The following test cases check if the input sequences only contain letters G, U, A, C
	 * and if the length of input sequences are less than or equal to 10.
	 */
	fprintf(fp,"The following test cases check if the input sequences only contain letters G, U, A, C"); 
	fprintf(fp,", and if the length of input sequences are less than or equal to 10.\n");
	/* Test case 6 */
	fprintf(fp,"Test case 6\n");
	result = check_input("GAUACCC");
	fprintf(fp,"result: %d, expected: 0\n", result);
	fprintf(fp,"\n");

	/* Test case 7 */
	fprintf(fp,"Test case 7\n");
	/*The sequence contain letter 'S'.*/
	result = check_input("UAUCSDC");
	fprintf(fp,"result: %d, expected: -1\n", result);
	fprintf(fp,"\n");

	/* Test case 8 */
	fprintf(fp,"Test case 8\n");
	/* The sequence length exceeds 10. */
	result = check_input("GAUACCCCAGGGCCC");
	fprintf(fp,"result: %d, expected: -1\n", result);
	fprintf(fp,"\n");

	/* Test case 9 */
	fprintf(fp,"Test case 9\n");
	/* The sequence is NULL. */
	get_align("GAUACCCCAGGGCCC", "UAUCSDC", 2, 4, 4, seq1_align,seq2_align,scores);
	result = check_input("");
	fprintf(fp,"result: %d, expected: -1\n", result);
	fprintf(fp,"\n");
	
	/* Test cases for get_max function. */
	fprintf(fp,"Test case for get_max function\n\n");

	/** 
	 * As get_max function is called by matrix_builder function and get_align function, and its
	 * parameters are actually the parameter match_score, mis_matchsocre in those two fucntions, 
	 * so there is no need to check the correctness of inputs.
	 */

	/* Test case 10 */
	fprintf(fp,"Test case 10\n");
	result = get_max(1,4,5);
	fprintf(fp,"result: %d, expected: 5\n", result);
	fprintf(fp,"\n");

	/* Test case 11 */
	fprintf(fp,"Test case 11\n");
	result = get_max(8,4,1);
	fprintf(fp,"result: %d, expected: 8\n", result);
	fprintf(fp,"\n");

	/* Test case 12 */
	fprintf(fp,"Test case 12\n");
	result = get_max(4,9,2);
	fprintf(fp,"result: %d, expected: 9\n", result);
	fprintf(fp,"\n");

	/* Test case 13 */
	fprintf(fp,"Test case 13\n");
	result = get_max(2,2,2);
	fprintf(fp,"result: %d, expected: 2\n", result);
	fprintf(fp,"\n");

	/* Test cases for matrix_builder function */
	fprintf(fp,"Test case for matrix_builder function\n\n");	

	/* The following test cases check if the matrix generated is expected. */
	fprintf(fp,"The following test cases check if the matrix generated is expected.\n");
	
	/* Test case 14 */
	fprintf(fp,"Test case 14\n");
	char array[9][6] = {
						    { 0, -1, -2, -3, -4, -5},
    					    {-1, -1,  1,  0, -1, -2},
						 	{-2,  1,  0,  0,  2,  1},
						 	{-3,  0,  0, -1,  2,  1},
						 	{-4, -1, -1, -1,  1,  1},
						 	{-5, -2,  1,  1,  0,  0},
						 	{-6, -3,  0,  0,  0, -1},
						 	{-7, -4, -1, -1, -1,  2},
						 	{-8, -5, -2, -2, -2,  1}

	};
	matrix_builder("AUUGAGCC", "UAAUC", 2, 1, 1,scores);
	result = 0;
	for(int i = 0; i < 9; i++){
        for (int j = 0; j < 6; ++j){
            if(scores[i][j] != array[i][j]){
                result = -1;
            }
        }
    }
	fprintf(fp,"result: %d, expected: 0\n", result);
	fprintf(fp,"\n");

	/* Test case 15 */
	fprintf(fp,"Test case 15\n");
	memset( scores, 0, sizeof(scores));
	char array1[8][7] = {
						    { 0,  -2, -4, -6, -8, -10, -12},
    					    {-2,  -2, -4, -1, -3,  -5,  -7},
							{-4,  -4,  1, -1, -3,  -5,  -7},
							{-6,  -1, -1, -1, -3,   0,  -2},
							{-8,  -3,  2,  0, -2,  -2,  -2},
							{-10, -5,  0,  0, -2,  -4,   1},
							{-12, -7, -2, -2, -2,  -4,  -1},
							{-14, -9, -4, -4, -4,  -4,  -1}

	};
	matrix_builder("GAUACCC", "UAGGUC", 3, 2, 2,scores);
	result = 0;
	for(int i = 0; i < 8; i++){
        for (int j = 0; j < 7; ++j){
            if(scores[i][j] != array1[i][j]){
                result = -1;
            }
        }
    }
	fprintf(fp,"result: %d, expected: 0\n", result);
	fprintf(fp,"\n");


	/* The following test cases check if the rows and columns of the matrix are expected. */
	fprintf(fp,"The following test cases check if the rows and columns of the matrix are expected.\n");
	/* Test case 16 */
	fprintf(fp,"Test case 16\n");
	memset( scores, 0, sizeof(scores));
	matrix_builder("GAUCUUCC", "UACCAGUC", 3, 2, 2,scores);
	int row = strlen("UACCAGUC");;
	int column = strlen("GAUCUUCC");
	index1 = 0;
	index2 =0;
	result = 0;
	result1 =0 ;

	/* Column check */
	for(int i = 0;i < 50;i++){
		if(scores[0][i]!=0){
			index1 = i;
		}
	}
	if(column != index1){
	    result = -1; 
	}
	/* Row check */
	for(int j = 0;j < 50;j++){
		if(scores[j][0]!=0){
			index1 = j;
		}
	}
	if(row != index1){
	    result1 = -1; 
	}

	fprintf(fp,"result: %d, expected: 0\n", result);
	fprintf(fp,"result: %d, expected: 0\n", result1);
	fclose(fp); 
	
}

