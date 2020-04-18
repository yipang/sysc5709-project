/**
 * This is the main function of our program for accomplishing the Needleman-Wunsch Algorithm for Release1. 
 * The first step is to request user input for 2 sequences, match score, mismatch score, and gap penalty.
 * Then call the matrixBuilder() to build a matrix according to the length of 2 sequences and give a score matrix accordingly.
 * getAlign()
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> 
#include "matrixBuilder.h"
#include "getAlign.h"

int main(int argc, char* argv[]){

    bool checkStart=true;
    while(checkStart==true){

        unsigned char *ptr_seq1;
        unsigned char *ptr_seq2;
        ptr_seq1 = (unsigned char *)malloc(64 * sizeof(unsigned char));
        ptr_seq2 = (unsigned char *)malloc(64 * sizeof(unsigned char));

        /* NULL pointer check */
        if (NULL == ptr_seq1) {
            printf("Error! memory not allocated.\n");
            exit(0);
        }

        /* NULL pointer check */
        if (NULL == ptr_seq2) {
            printf("Error! memory not allocated.\n");
            exit(0);
        }

        unsigned int match_score=0;
        unsigned int mismatch_score=0;
        unsigned int gap_penalty=0;
        /* User to type in comparing sequences and match score, mismatch score, gap penalty */
        printf("Please input RNA sequence 1:\n");
        scanf("%s",ptr_seq1); 
        printf("Please input RNA sequence 2:\n");
        scanf("%s",ptr_seq2);
        printf("Please input the match score:\n");
        scanf("%d",&match_score);
        printf("Please input the mismatch score:\n");
        scanf("%d",&mismatch_score);
        printf("Please input the gap penalty:\n");
        scanf("%d",&gap_penalty);

        int length1 = strlen(ptr_seq1);
        int length2 = strlen(ptr_seq2);

        /* Option for user to choose about this program */
	    printf("1. Print output a fixed matrix based on Needleman-Wunsch Algorithm\n");
	    printf("2. Print the optimal alignment\n");
//	    printf("3. Save all the information"\n);
	    printf("4. input two new sequences\n");
	    printf("5. Exit the program\n");
        printf("Select one of the options:\n");

        int choice = 0;
	    scanf("%d",&choice);

        /* Options within this program */
        while(choice!=-1){
	        switch(choice){
	        case 1:
            {
                int *ptr_matrix;
                ptr_matrix = matrixBuilder(*ptr_seq1, *ptr_seq2, match_score, mismatch_score, gap_penalty);
                for(int i = 0; i <= length1; i++){
                    for(int j = 0; j <= length2; j++){
                        printf("%d", (*ptr_matrix)[i][j]);
                    }
                }
		        break;
            }
	        case 2: 
                getAlign(ptr_seq1, ptr_seq2, match_score, mismatch_score, gap_penalty);
	            break;
	        case 4:
                choice = -1;
            case 5:
                return checkStart=false;
            default:
                printf("Error: Please choose from options 1 to 5!");
            }
        }
        free(ptr_seq1);
        free(ptr_seq2);
    }
}