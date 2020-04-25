#ifndef matrix_builder_H
#define matrix_builder_H

void matrix_builder(char seq1[], char seq2[],int match_score, 
	int mismatch_score, int gap_penalty,int scores[50][50]);

#endif//matrix_builder_H