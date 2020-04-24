/**
 * This function takes in three parameters, score1, score2, score3.
 * Each of them represents a score from current, from moving horizontally,
 * score from moving vertically. The result will give the get_max of them.
 */

#include "get_max.h"

int get_max(int score1, int score2, int score3){

    if(score3 >= score1 && score3>=score2){
        return score3;
    }else if(score2 >= score1 && score2>=score3){
        return score2;
    }else{
        return score1;
    }
            
}