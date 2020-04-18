#include "getMax.h"
/**
* This functions takes in three parameters, score1, score2, score3.
* Each of them represents a score from current, from moving horizontally, score from moving vertically.
* The result will give the max of them.
*/
int getMax(int score1, int score2, int score3)
{
    if(score3 >= score1 && score3>=score2){
        return score3;
    }
    
    if(score2 >= score1 && score2>=score3){
        return score2;
    }

    if(score1 >= score3 && score1>=score2){
        return score1;
    }   
}