#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Rock defeats Scissors, Scissors defeats Paper, and Paper defeats Rock. If both players choose the same shape, the round instead ends in a draw.

//the second column says how the round needs to end: X means you need to lose, Y means you need to end the round in a dra
//, and Z means you need to win. Good luck!"


// A  && X FOR ROCK
// B && Y FOR PAPER 
// C && Z FOR SCIZORS
int calc_outcome (char opponent, char me) {
    int r = 0;
    if (opponent == 'A') {
        printf ("Ele jogou pedra:%c\n",opponent);

        if (me == 'X') { 
            r += 3;    

        }
        else if (me == 'Y')  {
        r += 4;
        }
         else {r+=8;}
    }
    else if (opponent == 'B') {
        printf ("Ele jogou papel:%c\n",opponent);

        if (me == 'X') {
            r += 1;
        }
        else if (me == 'Y')  {
        r += 5;
        }
            else if (me == 'Z') {r+=9;}
    }
    
    else if (opponent == 'C') {
        printf ("Ele jogou tesoura:%c\n",opponent);

        if (me == 'X') {
            r += 2;
        }
        else if (me == 'Y')  {
        r += 6;
    }
        else if (me == 'Z') {r+=7;}
    }
return r;
}

int  get_total_score (FILE * input) {
    char opponent;
    char status;
    char * token;
    int total = 0;
    int i = 0;
    size_t len;
    char * line = NULL;
    while (getline( & line, & len, input) != -1 && !feof (input)) {
        //char * line_aux = line;
        //token = strsep( & line_aux, ";\n");
        opponent = line[0];
        status = line[2];
        printf ("Ele jogou:%c\n",opponent);
        if (status == 'X') {
        printf ("Devo perder:%c\n",status);
        }
            else if (status == 'Y') {
             printf ("Devo empatar:%c\n",status);
            }
                else { 
                     printf ("Devo ganhar:%c\n",status);
                }
    total += calc_outcome (opponent,status);
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