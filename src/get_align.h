#ifndef get_align_H
#define get_align_H

void get_align(char seq1[], char seq2[], int match_score, int mismatch_score,
	int gap_penalty, char* seq1_align,char* seq2_align,int scores[50][50]);

#endif//get_align_H