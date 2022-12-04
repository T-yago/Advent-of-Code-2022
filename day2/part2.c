#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Rock defeats Scissors, Scissors defeats Paper, and Paper defeats Rock. If both players choose the same shape, the round instead ends in a draw.

//the second column says how the round needs to end: X means you need to lose, Y means you need to end the round in a dra
//and Z means you need to win. Good luck!"
// A  && X FOR ROCK
// B && Y FOR PAPER 
// C && Z FOR SCIZORS

int calc_outcome (char opponent, char me) {
    int r = 0;
    if (opponent == 'A') {
        if (me == 'X') r += 3;    
        else if (me == 'Y') r += 4;
        else r+=8;
    }
    else if (opponent == 'B') {
        if (me == 'X') r += 1;
        else if (me == 'Y') r += 5;
        else r+=9;
    }
    else if (opponent == 'C') {
        if (me == 'X') r += 2;
        else if (me == 'Y') r += 6;
        else r+=7;
    }
return r;
}

int  get_total_score (FILE * input) {
    char opponent;
    char status;
    int total = 0;
    size_t len;
    char * line = NULL;
    while (getline( & line, & len, input) != -1) {
        opponent = line[0];
        status = line[2];
    total += calc_outcome (opponent,status);
    }      
    return total;  
}

int main () {
    FILE * input = fopen ("input.txt","r");
    int answer = get_total_score (input);
    printf ("Total:%d\n",answer);
    fclose (input);
}