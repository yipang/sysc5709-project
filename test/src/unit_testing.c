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

