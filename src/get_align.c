/**
 * getAlign() including 8 parameters to give the optimal alignment result as
 * well as the number of match, mismatch, and alignment length.  
 * seq1, seq2, match_score, mismatch_score, gap_penalty are used for 
 * generating the matrix, scores is used to record the matri, 
 * seq1_align and seq2_align are used to record the optimal alignment.
 * After the score matrix has been made, the mothod traceback is applied to
 * generate the results.
 * seq1 and seq2 are checked by check_input().
 * The method is explained in details in user manual.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_align.h"
#include "get_max.h"

void get_align(char seq1[], char seq2[], int match_score, int mismatch_score, 
    int gap_penalty,char seq1_align[],char seq2_align[],int scores[50][50]){

    /* len1, len2 are the length of seq1 and seq2 */
    int len1 = strlen(seq1), len2 = strlen(seq2);

    /* The (0,0) in matrix is always 0. */
    scores[0][0] = 0;

    /* Assign value for the first column of the matrix */
    for(int i=1; i<=len1; i++){
        scores[i][0] = -i*gap_penalty;
    }
    /* Assign value for the first row of the matrix */
    for(int i=1; i<=len2; i++){
        scores[0][i] = -i*gap_penalty;
    }
    
    /* Assign the rest unit of the matrix */
    for (int i = 1; i <= len1; i++){
        for (int j = 1; j <= len2; j++){
            int score1, score2, score3, result = 0;

            if(seq1[i-1] == seq2[j-1]){  
                score1 = scores[i-1][j-1] + match_score;
            }else{
                score1 = scores[i-1][j-1] - mismatch_score;
            }
            score2 = scores[i-1][j] - gap_penalty;
            score3 = scores[i][j-1] - gap_penalty;
    
            /* Assign the maximal value of score1, score2, score3 to result. */
            result = get_max(score1, score2, score3);
            /* Assign result to the current position of the matrix. */
            scores[i][j] = result;
        }
    }

    int num = 0;
    int seq1_num = len1 - 1;
    int seq2_num = len2 - 1;
    int i = 0;
    int j = 0;
    int sum = 0;
    /* Find the largest value in the last row. */
    int max_score = scores[len2][0], max_j = 0;
    for (j = 1; j <= len1; j++){
        if (max_score <= scores[len2][j]){
            max_score = scores[len2][j];
            max_j = j;
        }
    }
    int col_max = scores[len2][max_j];
    
    /* Find the largest value in the last column. */
    int max_score1 = scores[0][len1], max_i = 0;
    for (i = 1; i <= len2; i++){
        if (max_score1 < scores[i][len1]){
            max_score1 = scores[i][len1];
            max_i = i;
        }
    }
    int row_max = scores[max_i][len1];

    /**
     * Find the larger value between the largest value in the last row and 
     * and the largest value in the last column as the start point for 
     * traceback. 
     */
    int starter1, starter2;
    if (col_max >= row_max){
        starter1 = len2;
        starter2 = max_j;
    }
    if (col_max < row_max){
        starter1 = max_i;
        starter2 = len1;
    }

    /* Sum up each unit between starter1 and len2 in the last column. */
    if (starter1 < len2){
        for (i = starter1 + 1; i <= len2; i++){
            sum += scores[i][len1];
        }
        /* Form part of the optimal alignment. */
        for (num = 0; num < len2 - starter1; num++){
            seq1_align[num] = '-';
            seq2_align[num] = seq2[seq2_num];
            seq2_num--;
        }
    }
    /* Sum up each unit between starter2 and len1 in the last row. */
    if (starter2 < len1){
        for (j = starter2 + 1; j<= len1; j++){
            sum += scores[len2][j];
        }
        /* Form part of the optimal alignment. */
        for (num = 0; num < len1 - starter2; num++){
            seq2_align[num] = '-';
            seq1_align[num] = seq1[seq1_num];
            seq1_num--;
        }
    }
    /**
     * The largest value is in the last unit in matrix. Form the part 
     * of the optimal alignment by copying the letter in seq1 and seq2 to 
     * seq1_align and seq2_align.
     */
    if (starter1 == len2 && starter2 == len1){
        num = 0;
        seq2_align[num] = seq2[seq2_num];
        seq1_align[num] = seq1[seq1_num];
        num++; 
        seq1_num--; 
        seq2_num--;
    }
    sum += scores[starter1][starter2];

    /* Form the complete optimal alignment. */
    while (starter1 > 1 && starter2 > 1 && seq1_num > 0 && seq2_num > 0){
        /**
         * score1: value of the left cell
         * score2: value of the upper cell
         * score3: value of the upper left cell
         */
        int scoremax = 0, score1 = 0, score2 = 0, score3 = 0;
        score1 = scores[starter1][starter2 - 1];
        score2 = scores[starter1 - 1][starter2];
        score3 = scores[starter1 - 1][starter2 - 1];
        scoremax = get_max(score1, score2, score3);
        sum += scoremax;
        if (score3 == scoremax){
            /* Move from current cell to upper left cell. */
            starter1 = starter1 - 1;
            starter2 = starter2 - 1;
            seq1_align[num] = seq1[seq1_num];
            seq2_align[num] = seq2[seq2_num];
            num++; seq1_num--; seq2_num--;
        }
        if (score1 == scoremax && score2 != scoremax){
            /* Move from current cell to left cell. */
            starter2 = starter2 - 1;
            seq1_align[num] = seq1[seq1_num];
            seq2_align[num] = '-';
            num++; seq1_num--;
        }
        if (score2 == scoremax){
            /* Move from current cell to upper cell. */
            starter1 = starter1 - 1;
            seq2_align[num] = seq2[seq2_num];
            seq1_align[num] = '-';
            num++; seq2_num--;
        }

    }
    /* Fill up seq2_align with '-'. */
    if (starter1 == 1 && starter2 != 1) {
        while (seq1_num >= 0){
            seq1_align[num] = seq1[seq1_num];
            seq2_align[num] = '-';
            seq1_num--; 
            num++;
        }
    }
    /* Fill up seq1_align with '-'. */
    if (starter2 == 1 && starter1 != 1) {
        while (seq2_num >= 0){
            seq2_align[num] = seq2[seq2_num];
            seq1_align[num] = '-';
            seq2_num--; 
            num++;
        }
    }
    if (starter2 == 1 && starter1 == 1)
    {
        seq2_align[num] = seq2[0];
        seq1_align[num] = seq1[0];
    }
}

