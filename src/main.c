/**
 * This is the main function of our program for accomplishing Needleman-Wunsch 
 * Algorithm. The first step is to request user input for 2 
 * sequences, match score, mismatch score, and gap penalty.
 * The program can accept inputs by manully or from file.
 * Then the program provides 5 options for user to choose:
 * 1. Call matrix_builder() to build a matrix according to the inputs.
 * 2. Call get_align() to output the optimal alignment.
 * 3. Save the information of option 1 and option 2 to a txt file.
 * 4. Ask user to input new data.
 * 5. Continue to read the file.
 * 6. Exit the program.
 * The program runs iteratively until user chooses option 6.
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "matrix_builder.h"
#include "get_align.h"
#include "get_max.h"
#include "check_input.h"

int main(){
    char seq1_align[100] = "\0", seq2_align[100] = "\0";
    int scores[50][50] = {0};
    char seq1[100] = "\0", seq2[100] = "\0";
    int i = 0;
    int j = 0;
    int match_score = 0;
    int mismatch_score = 0;
    int gap_penalty = 0;
    char name[50] = "\0";
    char name1[50] = "\0";
    char path[50] = "\0";
    bool check_start = true;
    jump:
    /* Start main part of the program. */
    while(check_start == true){
        FILE *read_pointer = NULL;
        int method = 0;
        float temp = 0.0;
        /*Ask users to choose the way to input data*/
        printf("Please select the way to input your data:\n");
        printf("1: By manual\n");
        printf("2: From file\n");
        scanf("%d",&method);
        fflush(stdin);
        if(method == 1){
        /* User types sequences and match score, mismatch score, gap penalty. */
            printf("Please input RNA sequence 1: ");
            scanf("%s",seq1);
            if(check_input(seq1) == -1){
                printf("Invalid input\n");
                continue;
            }
            printf("Please input the sequence 2: ");
            scanf("%s",seq2);
            if(check_input(seq2) == -1){
                printf("Invalid input\n");
                continue;
            }
            printf("Please input the match score: ");
            scanf("%f",&temp);
            fflush(stdin);
            match_score = (int)temp;
            printf("Please input the mismatch score: ");
            scanf("%f",&temp);
            fflush(stdin); 
            mismatch_score = (int)temp;
            printf("Please input the gap penalty: ");
            scanf("%f",&temp);
            fflush(stdin);
            gap_penalty = (int)temp;
            printf("\n");
        }else if(method == 2){
            /* Input data from file */
            printf("Please input filename: ");
            scanf("%s",name);
            snprintf(path, sizeof(path), "./data/%s", name);
            read_pointer = fopen(path, "r");
            read_next:
            if(read_pointer == NULL){
                printf("Invalid filename\n");
                continue;
            }
            /* If this is not the end of the file, continue to read. */
            if(!feof (read_pointer)){
                fscanf(read_pointer,"%s",seq1);
                /* Make sure seq1 satisfies the requirement */
                if(check_input(seq1) == -1){
                    printf("Invalid input\n");
                    continue;
                }
                fscanf(read_pointer,"%s",seq2);
                /* Make sure seq2 satisfies the requirement */
                if(check_input(seq1) == -1){
                    printf("Invalid input\n");
                    continue;
                }
                fscanf(read_pointer,"%f",&temp);
                match_score = (int)temp;
                fscanf(read_pointer,"%f",&temp);
                mismatch_score = (int)temp;
                fscanf(read_pointer,"%f",&temp);
                gap_penalty = (int)temp;
            }else{
                /* Reach the end of the file, output error message. */
                printf("No more data to read\n");
                continue;
            }

        }else{
            /* Wrong input. */
            printf("Error: Please choose from options 1 and 2!");
            continue;
        }

        int choice = 0;
        
        /* Options within this program */
        while(choice!=-1){
            /* Option for user to choose about this program */
            printf("Please select from following choices:\n");
	        printf("1. Print a modified matrix\n");
	        printf("2. Print the optimal alignment\n");
            printf("3. Save all the information\n");
	        printf("4. Input two new sequences\n");
            printf("5. Read the next data\n");
	        printf("6. Exit the program\n\n");
            printf("Select one of the options: ");
            scanf("%d",&choice);
            printf("\n");
	        switch(choice){
	        case 1:
                matrix_builder(seq1, seq2, match_score,mismatch_score,gap_penalty,scores);
                /* Print out the 2D array based on the modifications of scores[][] made in matrix_builder. */
                printf("the score array is:\n");
                for (i = 0; i <= strlen(seq1); i++){
                    for (j = 0; j <= strlen(seq2); j++){
                        if (j == strlen(seq2)){
                            printf("%4d\n", scores[i][j]);
                        }else{
                            printf("%4d", scores[i][j]);
                        }
                    }
                }
                printf("\n");
                break;
            case 2:
                get_align(seq1, seq2,match_score,mismatch_score,gap_penalty,seq1_align,seq2_align,scores);
                /* Print out the optimal alignment together with number of match, gap as well as alignment length. */
                int len1 = strlen(seq1_align);
                int len2 = strlen(seq2_align);
                for (i = len1-1; i >= 0; i--){
                    printf("%c", seq1_align[i]);
                }
                printf("\n");
                for (i = len2-1 ; i >= 0; i--){
                    printf("%c", seq2_align[i]);
                }

                printf("\n");
                int counter = 0;
                int counter1 = 0;
                char str1 = '-';
                for (i = len2-1; i >= 0; i--){
                    if(seq1_align[i]==seq2_align[i]){
                        counter++;  
                    }
                }
                for (i = len2-1; i >= 0; i--){
                    if(seq1_align[i]==str1||seq2_align[i]==str1){
                        counter1++;  
                    }
                }
                printf("Match: %d  ", counter);
                printf("Gap: %d\n", counter1);
                printf("Alignment Length: %d",len2);
                printf("\n\n");               
                break;
            case 3: 
             printf("Please input the filename to export\n");
                /*Open a file with write mode */
                scanf("%s",name1);
                FILE *fp = fopen(name1, "w");
                matrix_builder(seq1, seq2, match_score,mismatch_score,
                    gap_penalty,scores);
                fprintf(fp,"the score array is:\n");
                for (i = 0; i <= strlen(seq1); i++){
                    for (j = 0; j <= strlen(seq2); j++){
                        if (j == strlen(seq2)){
                            fprintf(fp,"%4d,\n", scores[i][j]);
                        }else{
                            fprintf(fp,"%4d,", scores[i][j]);
                        }
                    }
                }
                fprintf(fp,"\n");
                /* Print out the same output as case 1 + case 2. */
                get_align(seq1, seq2,match_score,mismatch_score,gap_penalty,
                    seq1_align,seq2_align,scores);
                len1 = strlen(seq1_align);
                len2 = strlen(seq2_align);
                fprintf(fp,"Seq1: ");
                for (i = len1 - 1; i >= 0; i--){
                    fprintf(fp,"%c", seq1_align[i]);
                }
                fprintf(fp,"\n");
                fprintf(fp,"Seq2: ");
                for (i = len2 - 1; i >= 0; i--){
                    fprintf(fp,"%c", seq2_align[i]);
                }

                fprintf(fp,"\n");
                counter = 0;
                counter1 = 0;
                str1 = '-';
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
                fprintf(fp,"Match: %d  ", counter);
                fprintf(fp,"Gap: %d\n", counter1);
                fprintf(fp,"Alignment Length: %d",len2);
                fprintf(fp,"\n\n"); 
                fclose(fp); 
                break;
            case 4:
            /* Back to the start of the program */
                goto jump;
            case 5:
            /* jump to the code that reads the next 5 line of the input file */
                goto read_next;
            case 6:
            /* Termiate the program. */
                return check_start=false;
            default:
            /* Default case */
                printf("Error: Please choose from options 1 to 5!\n");
                printf("\n"); 
            }
        }
    }
}