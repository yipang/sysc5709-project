/** 
 * check_input is to check the property of char seq[]. 
 * The first is to check it's not null. 
 * The second is to check the length is not zero, and not over 10. 
 * The third check is to check the char sequence only contains ACGU.
 */

#include <string.h>
#include "check_input.h"

int check_input(char seq[]){

    /* Check if seq is not empty. */
    if(seq == NULL){
        return -1;
    }

    /* Check if the length is over 10 or is less than or equal to 0. */
    int length = strlen(seq);
    if(length<=0||length>10){
        return -1;
    }

    /* Check if the sequence only contains 'A','C','G','U'. */
    for(int i=0;i<length-1;i++) {
        if((seq[i]!='A')&&(seq[i]!='C')&&(seq[i]!='G')&&(seq[i]!='U')){
            return -1;
        }
    }
    return 0;
}