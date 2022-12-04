#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_if_contain (int first_inf, int first_sup, int second_inf, int second_sup) {
    if (first_inf >= second_inf && first_sup <= second_sup) return 1;
    else return 0;
}   

int parser (FILE * input) {
    ssize_t len;
    int total = 0;
    int first_inf, first_sup, second_inf, second_sup;
    char * first = NULL;
    char * second = NULL;
    char * line = NULL;
    while (getline(& line,& len,input) != -1) {
        first = strtok (line,",");
        second = strtok (NULL, "\n");
        first_inf = atoi (strtok (first, "-"));
        first_sup = atoi (strtok (NULL, "\n"));
        second_inf = atoi (strtok (second, "-"));
        second_sup = atoi (strtok (NULL, "\n")); 
        if (check_if_contain (first_inf, first_sup, second_inf, second_sup) || check_if_contain (second_inf, second_sup, first_inf,first_sup)){
         total += 1;   
        }
    }
    return total;
}



int main () {
    FILE * input = fopen ("input.txt","r");
    int answer = parser (input);
    printf ("Total:%d\n",answer);
    fclose (input);
}