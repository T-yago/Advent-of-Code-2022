#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_sum (char * first,char * second) {
    int total = 0;
    int i,j;
    int ocurr = 0;
    int length_first = strlen (first) ;
    int length_second = strlen (second) ;
        //printf ("Length_first: %d\n",length_first);
        //printf ("Length_second: %d\n",length_second);
    for (i=0;i < length_first; i++) {
        for (j=0; j < length_second; j++) {
            if (first [i] == second [j] && ocurr < 1) {
                printf ("Found: %c\n",first[i]);
                if islower (first[i]) {
                    total += first[i] - 96;
                    ocurr++;
                    printf ("Total: %d\n\n",total);
                }
                else if isupper (first[i]) {
                    total += first[i] - 38;
                    ocurr++;
                   printf ("Total: %d\n\n",total);
                }
            }
        }
    }
    return total;
}

void divide_string (char * line, int length, char * first, char * second) {
    int index = length / 2;
    //printf ("Size of Line: %d\n", length);
    //printf ("Index: %d\n",index);
    int i;
    for (i = 0; i < index ; i++) {
        first [i] = line [i];
    }
    first [index] = '\0';
    int j = 0;
    for (i= index; i <= length; i++) {
        second [j] = line [i];
        j++;
    }
    second [length-index] = '\0';
    
}

int parser (FILE * input) {
    size_t len;
    int total = 0;
    int length;
    char * line = NULL;
    char first[100];
    char second [100];
    int i = 0;
    while (getline( & line, & len, input) != -1 && !feof (input)) {
        //printf ("%ld\n",len);
    
        length = strlen (line) - 1;
        //printf ("%d\n",length);
        divide_string (line,length,first,second);

        printf ("First: %s\n",first);
        printf ("Second: %s\n",second);
        total += get_sum (first,second);
        i++;
    }   
  
    return total;
}


int main () {
    FILE * input = fopen ("input.txt","r");
    int answer = parser (input);
    printf ("Total:%d\n",answer);
    fclose (input);
}