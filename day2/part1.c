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
        printf ("Ele jogou pedra:%c\n",opponent);

        if (me == 'X') {
            r += 3;    //   printf ("A * X");

        }
        else if (me == 'Y')  {
        r += 6;
        }
         else {r+=0;}
    }
    else if (opponent == 'B') {
        printf ("Ele jogou papel:%c\n",opponent);

        if (me == 'Y') {
            r += 3;
        }
        else if (me == 'Z')  {
        r += 6;
        }
            else if (me == 'X') {r+=0;}
    }
    
    else if (opponent == 'C') {
        printf ("Ele jogou tesoura:%c\n",opponent);

        if (me == 'Z') {
            r += 3;
        }
        else if (me == 'X')  {
        r += 6;
    }
        else if (me == 'Y') {r+=0;}
    }
return r;
}

/*
int calc_outcome (char opponent, char me) {
    int r = 0;
    switch (opponent)
    {
    case 'A':
        if (me == 'X') {
            r += 3;
             //   printf ("A * X");

        }
        else if (me == 'Y')  {
        r += 6;
    }
            else {r+=0;}
        break;
    case 'B':
        if (me == 'Y') {
            r += 3;
        }
        else if (me == 'Z')  {
        r += 6;
    }
    else {r+=0;}
    break;
    case 'C':
         if (me == 'Z') {
            r += 3;
        }
        else if (me == 'A')  {
        r += 6;
    }
        else {r+=0;}

    break;
    }
return r;
}
*/
int  get_total_score (FILE * input) {
    char opponent;
    char me;
    char * token;
    int total = 0;
    int i = 0;
    size_t len;
    char * line = NULL;
    while (getline( & line, & len, input) != -1 && !feof (input)) {
        //char * line_aux = line;
        //token = strsep( & line_aux, ";\n");
        opponent = line[0];
        me = line[2];
        printf ("Eu joguei:%c\n",me);
        printf ("Ele jogou:%c\n",opponent);
        if (me == 'X') {
        printf ("Eu joguei pedra:%c\n",me);
        total += 1;
        }
            else if (me == 'Y') {
             printf ("Eu joguei papel:%c\n",me);
            total += 2;
            }
                else { 
                     printf ("Eu joguei tesoura:%c\n",me);
                total += 3;
                }
                printf ("ELE JOGOU:%c\n",opponent );
    total += calc_outcome (opponent,me);
    printf ("Total_ronda%d:",i);
    printf ("%d\n",total);
    i++;
    }      
    return total;  
}

int main () {
    FILE * input = fopen ("input.txt","r");
    int answer = get_total_score (input);
    printf ("Total:%d\n",answer);
    fclose (input);
}