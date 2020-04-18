#include <stdio.h>
#include <string.h>
#include "getMax.h"
#include "matrixBuilder.h"
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
int* matrixBuilder(char seq1[], char seq2[], int match_score, int mismatch_score, int gap_penalty){
     
    int matrix[11][11];
    int *pointer;
    pointer = &matrix;
    matrix[0][0] = 0;
    int length1 = strlen(seq1);
    int length2 = strlen(seq2);

    /* Go through the matrix horizontally and vertically and calculate score in each position with gap penalty */
    int temp = 0;
    for(int i=2; i<length1; i++){
        matrix[0][i] = seq1[i];
        matrix[1][i] = temp - gap_penalty;
    }
    for(int i=2; i<length2; i++){
        matrix[i][0] = seq2[i];
        matrix[i][1] = temp - gap_penalty;
    }

    /* Go through the matrix calculate the position score with gap penalty and current position score */
    /* Final position score in the matrix is the max of three scores */
    /* 'score1' is the score goes horizontally with gap penalty */
    /* 'score2' is the score goes vertically with gap penalty */
    /* 'score3' is the score of current position added the corresponding comparing result, result can be positive or negative */
    int score1 = 0;
    int score2 = 0;
    int score3 = 0;
    for(int i = 2; i <= length1+2; i++){
        int temp = (i-2)*gap_penalty;
        for(int j = 2; j <= length2+2; i++){
            temp = temp - gap_penalty;
            score1 = matrix[i][j-1] - gap_penalty;
            score2 = matrix[i-1][j] - gap_penalty;

            if(seq1[i-2] == seq2[j-2]){
                score3 = matrix[i-1][j-1] + match_score;
            }else{
                score3 = matrix[i-1][j-1] - mismatch_score;
            }
            
            matrix[i][j] = getMax(score1,score2,score3); /* Find the max from moving and current score as final socre */
        }
    }
    return pointer;
}