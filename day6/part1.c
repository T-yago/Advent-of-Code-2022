#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int parser (FILE * input) {
    char * line = NULL;
    ssize_t len;
    int pos=0;
    int found = 0;
    int index=0;
    getline (&line,&len,input);
    while (isalpha(line[pos])) {
           if (line[pos] != line[pos+1] && line[pos] != line[pos+2] && line[pos] != line[pos+3] && line[pos+1] != line[pos+2] && line[pos+1] != line[pos + 3] && line[pos+2] != line[pos+3]) {
                index = pos+4;
                printf("%d\n",index);
                break;
            }
                    pos++;

    }
}
        

int main () {
    FILE * input = fopen ("input.txt","r");
    int answer = parser (input);
    //printf ("Total:%d\n",answer);
    fclose (input);
}