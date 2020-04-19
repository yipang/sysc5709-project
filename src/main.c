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
#include "getMax.h"
#include "getAlign.h"

char seq1_align[100] = "\0", seq2_align[100] = "\0";
int scores[50][50] = { 0 };

int main(){
    
    char seq1[100] = "\0", seq2[100] = "\0";
    int i;
    int j;
    unsigned int match_score;
    unsigned int mismatch_score;
    unsigned int gap_penalty;
    
    bool checkStart = true;
    jump:
    while(checkStart == true){
        /* User to type in comparing sequences and match score, mismatch score, gap penalty */
        printf("Please input RNA sequence 1: ");
        scanf("%s",seq1);
        printf("Please input the sequence 2: ");
        scanf("%s",seq2);
        printf("Please input the match score: ");
        scanf("%u",&match_score);
        printf("Please input the mismatch score: ");
        scanf("%u",&mismatch_score);
        printf("Please input the gap penalty: ");
        scanf("%u",&gap_penalty);
        printf("\n");
        int choice;
        
        /* Options within this program */
        while(choice!=-1){
            /* Option for user to choose about this program */
            printf("Please select from following choices:\n");
	        printf("1. Print getAlign a fixed matrix\n");
	        printf("2. Print the optimal alignment\n");
            /* printf("3. Save all the information"\n); for release 2*/
	        printf("4. input two new sequences\n");
	        printf("5. Exit the program\n\n");
            printf("Select one of the options: ");

            scanf("%d",&choice);
            printf("\n");

	        switch(choice){
	        case 1:
                matrixBuilder(seq1, seq2, match_score,mismatch_score,gap_penalty);
                printf("the score array is:\n");
                for (i = 0; i <= strlen(seq2); i++){
                    for (j = 0; j <= strlen(seq1); j++){
                        if (j == strlen(seq1)){
                            printf("%4d\n", scores[i][j]);
                        }else{
                            printf("%4d", scores[i][j]);
                        }
                    }
                }
                printf("\n");
                break;
            case 2:
                getAlign(seq1, seq2,match_score,mismatch_score,gap_penalty);
                int len1 = strlen(seq1_align);
                int len2 = strlen(seq2_align);
                for (i = len1 - 1; i >= 0; i--){
                    printf("%c", seq1_align[i]);
                }
                printf("\n");
                for (i = len2 - 1; i >= 0; i--){
                    printf("%c", seq2_align[i]);
                }

                printf("\n");
                int counter;
                int counter1;
                char str1 = '-';
                for (i = len2 - 1; i >= 0; i--){
                    if(seq1_align[i]==seq2_align[i]){
                        counter++;  
                    }
                }
                for (i = len2 - 1; i >= 0; i--){
                    if(seq1_align[i]==str1||seq2_align[i]==str1){
                        counter1++;  
                    }
                }
                printf("Match: %d  ", counter);
                printf("Gap: %d\n", counter1);
                printf("Alignment Length: %d",len2);
                printf("\n\n");               
                break;
            case 4:
                goto jump;
            case 5:
                return checkStart=false;
            default:
                printf("Error: Please choose from options 1 to 5!");
            }
        }
    }
}






