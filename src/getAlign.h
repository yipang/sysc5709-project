/* Traceback to give the best comparing result */
#ifndef getAlign_H
#define getAlign_H

extern char seq1_align[100];
extern char seq2_align[100];
extern int scores[50][50];
extern int score_array[5][5];

void getAlign(char seq1[], char seq2[], int match_score, int mismatch_score, int gap_penalty);

#endif