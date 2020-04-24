/**
 * matrix_builder() including 6 parameters builds a matrix through Needleman-
 * Wunsch Algorithm. seq1 and seq2 are char arrays along with match_score, 
 * mismatch_score and gap_penalty that user inputs at main function, which
 * are used to generate a matrix presented by scores. 
 * The limitations of the seq1 and seq2 are checked by check_input().
 * The Algorithm is explained in details in user manual.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrix_builder.h"
#include "get_max.h"

void matrix_builder(char seq1[],char seq2[],int match_score,int mismatch_score,
    int gap_penalty,int scores[50][50]){
    
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
        for (int j = 1; j <= len2; j++)
        {   
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
}