/**
 * matrixBuilder() including 5 parameters to build a matrix for calculating scores.
 * 'seq1' and 'seq2' take in a sequence of character for comparing, the length of them will be the length and width of the matrix.
 * The algorithm compares the two sequences according to moving the position from current position.
 * From left to right, from up to down, and from current to the next position.
 * Final score of that position = current position score + score during moving. 
 * 'match_score' is a user typed int as a comparing criterion, a positive integer. 
 * 'mismatch_score' is a user typed int as a comparing criterion, a positive integer.
 * 'gap_penalty' is a user typed int as a comparing criterion, a positive integer.
 * The final result will complete a matrix containing scores according to each comparing result. 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrixBuilder.h"
#include "getMax.h"

extern char seq1_align[100];
extern char seq2_align[100];
extern int scores[50][50];
extern int score_array[5][5];

void matrixBuilder(char seq1[], char seq2[],int match_score, int mismatch_score, int gap_penalty)//打分函数
{
    int index1, index2;
    int len1 = strlen(seq1), len2 = strlen(seq2);

    scores[0][0] = 0;
    for(int i=1; i<=len1; i++){
        scores[0][i] = -i*gap_penalty;
   
    }
    for(int i=1; i<=len2; i++){
        scores[i][0] = -i*gap_penalty;
    }
    
    for (int i = 1; i <= len2; i++)
        for (int j = 1; j <= len1; j++)
        {   
            int score1, score2, score3, result = 0;

            if(seq1[i-1] == seq2[j-1]){  
                score1 = scores[i-1][j-1] + match_score;
            }else{
                score1 = scores[i-1][j-1] - mismatch_score;
            }
            score2 = scores[i-1][j] - gap_penalty;
            score3 = scores[i][j-1] - gap_penalty;
            

            result = getMax(score1, score2, score3);
            scores[i][j] = result;
        }
}
