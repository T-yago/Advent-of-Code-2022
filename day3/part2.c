#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_priority (char * elf1, char * elf2, char * elf3) {
    printf ("Elf 1: %s", elf1);
    printf ("Elf 2: %s",elf2);
    printf ("Elf 3: %s",elf3);
    int len_1 = strlen (elf1 ) -1 ;
    int len_2 = strlen (elf2) -1;
    int len_3 = strlen (elf3) - 1;
    int total = 0;
    int ocurr = 0;

    int i,j,w;
    for (i=0; i < len_1; i++) {
        for (j=0; j < len_2; j++) {
            for (w = 0; w < len_3; w++) {
                if (elf1[i] == elf2[j] && ocurr < 1) {
                    if (elf1[i] == elf3[w]) {
                        if islower (elf1[i]) {
                            total += elf1[i] - 96;
                            ocurr++;
                        }
                        else {
                            total += elf1[i] - 38; 
                            ocurr++;
                        }
                    }
                }
            }
        }
    }
    printf ("Total_per_group: %d\n\n", total);
    return total;
}

int parser (FILE * input) {
    size_t len;
    int total = 0;
    char * line = NULL;
    int length;
    char * elf1 = NULL;
    char * elf2 = NULL;
    char * elf3 = NULL;

while (!feof (input)) {
    getline ( & line, & len, input);
    elf1 = strdup(line);
    getline ( & line, & len, input);
    elf2 = strdup(line);
    getline ( & line, & len, input);
    elf3 = strdup(line);

    total += get_priority (elf1,elf2,elf3);
    free (elf1);
    free (elf2);
    free (elf3);
}

    return total;
}

int main () {
    FILE * input = fopen ("input.txt","r");
    int answer = parser (input);
    printf ("Total:%d\n",answer);
    fclose (input);
}