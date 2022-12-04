#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Rock defeats Scissors, Scissors defeats Paper, and Paper defeats Rock. If both players choose the same shape, the round instead ends in a draw.
//1 for Rock, 2 for Paper, and 3 for Scissors
// + plus the score for the outcome of the round (0 if you lost, 3 if the round was a draw, and 6 if you won)

// A  && X FOR ROCK
// B && Y FOR PAPER 
// C && Z FOR SCIZORS
int calc_outcome (char opponent, char me) {
    int r = 0;
    if (opponent == 'A') {
        if (me == 'X') {
            r += 3;    
        }
        else if (me == 'Y')  {
        r += 6;
        }
         else r+=0;
    }
    else if (opponent == 'B') {
        if (me == 'Y') r += 3;
        else if (me == 'Z') r += 6;
        else r+=0;
    }
    
    else if (opponent == 'C') {
        if (me == 'Z') r += 3;
        else if (me == 'X') r += 6;
        else r+=0;
    }
return r;
}

int  get_total_score (FILE * input) {
    char opponent;
    char me;
    int total = 0;
    size_t len;
    char * line = NULL;
    while (getline( & line, & len, input) != -1) {
        opponent = line[0];
        me = line[2];
        if (me == 'X') {
        total += 1;
        }
            else if (me == 'Y') {
            total += 2;
            }
                else { 
                total += 3;
                }
    total += calc_outcome (opponent,me);
    }      
    return total;  
}

int main () {
    FILE * input = fopen ("input.txt","r");
    int answer = get_total_score (input);
    printf ("Total:%d\n",answer);
    fclose (input);
}