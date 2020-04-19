/**
 * getAlign() including 5 parameters to give a best sequence comparing result.
 * 'seq1' and 'seq2' take in a sequence of character for comparing, the length of them will be the length and width of the matrix.
 * The algorithm compares the two sequences according to moving the position from current position.
 * From left to right, from up to down, and from current to the next position.
 * Final score of that position = current position score + score during moving. 
 * 'match_score' is a user typed int as a comparing criterion, a positive integer. 
 * 'mismatch_score' is a user typed int as a comparing criterion, a positive integer.
 * 'gap_penalty' is a user typed int as a comparing criterion, a positive integer.
 * After the score matrix has been made, go traceback from the right bottom corner of the code to find the best comparing result.
 * The final result will give a best comparing result sequence.  
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getAlign.h"
#include "getMax.h"

void getAlign(char seq1[], char seq2[], int match_score, int mismatch_score, int gap_penalty){
    
    int index1, index2;
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);

    scores[0][0] = 0;
    for(int i=1; i<=len1; i++){
        scores[0][i] = -i*gap_penalty;
    }

    for(int i=1; i<=len2; i++){
        scores[i][0] = -i*gap_penalty;
    }
    
    for (int i = 1; i <= len2; i++){
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

    int num;
    int seq1_num = len1 - 1;
    int seq2_num = len2 - 1;
    int i, j;
    int sum = 0;
    int getMax(int score1, int score2, int score3);
    /*Find the largest value in the last row*/
    int max_score = scores[len2][0], max_j = 0;
    for (j = 1; j <= len1; j++)
        if (max_score <= scores[len2][j])
        {
            max_score = scores[len2][j];
            max_j = j;
        }
    int col_max = scores[len2][max_j];
    
    /* Find the largest value in the last column */
    int max_score1 = scores[0][len1], max_i = 0;
    for (i = 1; i <= len2; i++)
        if (max_score1 < scores[i][len1])
        {
            max_score1 = scores[i][len1];
            max_i = i;
        }
    int row_max = scores[max_i][len1];

    /* Find the largest value in the last row and last column as the start point for traceback */
    int starter1, starter2;
    if (col_max >= row_max)
    {
        starter1 = len2;
        starter2 = max_j;
    }
    if (col_max < row_max)
    {
        starter1 = max_i;
        starter2 = len1;
    }

    if (starter1 < len2)
    {
        for (i = starter1 + 1; i <= len2; i++)
            sum += scores[i][len1];
        for (num = 0; num < len2 - starter1; num++)
        {
            seq1_align[num] = '-';
            seq2_align[num] = seq2[seq2_num];
            seq2_num--;
        }
    }
    if (starter2 < len1)
    {
        for (j = starter2 + 1; j<= len1; j++)
            sum += scores[len2][j];
        for (num = 0; num < len1 - starter2; num++)
        {
            seq2_align[num] = '-';
            seq1_align[num] = seq1[seq1_num];
            seq1_num--;
        }
    }
    if (starter1 == len2 && starter2 == len1)
    {
        num = 0;
        seq2_align[num] = seq2[seq2_num];
        seq1_align[num] = seq1[seq1_num];
        num++; 
        seq1_num--; 
        seq2_num--;
    }
    sum += scores[starter1][starter2];
    while (starter1 > 1 && starter2 > 1 && seq1_num > 0 && seq2_num > 0)
    {
        /**
         *score1: value of the left cell
         *score2: value of the upper cell
         *score3: value of the upper left cell
         */
        int scoremax = 0, score1 = 0, score2 = 0, score3 = 0;
        score1 = scores[starter1][starter2 - 1];
        score2 = scores[starter1 - 1][starter2];
        score3 = scores[starter1 - 1][starter2 - 1];
        scoremax = getMax(score1, score2, score3);
        sum += scoremax;
        if (score3 == scoremax)
        {
            starter1 = starter1 - 1;
            starter2 = starter2 - 1;
            seq1_align[num] = seq1[seq1_num];
            seq2_align[num] = seq2[seq2_num];
            num++; seq1_num--; seq2_num--;
        }
        if (score1 == scoremax && score2 != scoremax)
        {
            starter2 = starter2 - 1;
            seq1_align[num] = seq1[seq1_num];
            seq2_align[num] = '-';
            num++; seq1_num--;
        }
        if (score2 == scoremax && score1 != scoremax)
        {
            starter1 = starter1 - 1;
            seq2_align[num] = seq2[seq2_num];
            seq1_align[num] = '-';
            num++; seq2_num--;
        }
        if (score2 == scoremax && score1 == scoremax)
        {
            starter1 = starter1 - 1;
            seq2_align[num] = seq2[seq2_num];
            seq1_align[num] = '-';
            num++; seq2_num--;
        }
    }
    if (starter1 == 1 && starter2 != 1)
        while (seq1_num >= 0)
        {
            seq1_align[num] = seq1[seq1_num];
            seq2_align[num] = '-';
            seq1_num--; 
            num++;
        }
    if (starter2 == 1 && starter1 != 1)
        while (seq2_num >= 0)
        {
            seq2_align[num] = seq2[seq2_num];
            seq1_align[num] = '-';
            seq2_num--; 
            num++;
        }
    if (starter2 == 1 && starter1 == 1)
    {
        seq2_align[num] = seq2[0];
        seq1_align[num] = seq1[0];
    }
    printf("The best scores is %d\n", sum);

}