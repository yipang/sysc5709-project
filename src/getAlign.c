#include <stdio.h>
#include <string.h>
#include "matrixBuilder.h"
#include "getMax.h"
#include "getAlign.h"

void getAlign(char[] seq1, char[] seq2, int match_score, int mismatch_score, int gap_penalty){

    int *ptr_matrix = matrixBuilder(*ptr_seq1, *ptr_seq2, match_score, mismatch_score, gap_penalty);
    char align1[];
    char align2[];
    char align3[];
    int length1 = strlen(seq1);
    int length2 = strlen(seq2);
    int count = 0;
    int sum = 0;
    int i = length1-1;
    int j = length1-1;
    int max = getMax(score1, score2, score3);
    while(i>0 && j>0){

            score1 = matrix[i+2][j+1];
            score2 = matrix[i+1][j+2];
            score3 = matrix[i+1][i+1];
            
            if (max==score3){
                align1[count] = seq1[i];
                align2[count]= "|"
                align3[count] = seq2[j];
                i-=1;
                j-=1;
                count+=1;
                sum+=score3;

            }
            //top最大
            if (max==score2){
                align1[count] = "-";
                align3[count] = seq2[j];
                i-=1;
                count+=1;
                sum+=score2;
            }    

            if (max==score1){
                align1[count] = seq1[i];
                align3[count] = "-";
                i-=1;
                count+=1;
                sum+=score1;
            }    
        }
    }
    for(int a=count;a>0;a--){
        printf("align1[a]\n");
        printf("align2[a]\n");
        printf("align3[a]\n");
    }
  
}