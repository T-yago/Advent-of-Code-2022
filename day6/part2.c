#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int parser (FILE * input) {
    char * line = NULL;
    ssize_t len;
    int pos=0;
    int index=0;
    getline (&line,&len,input);
            int i =0;
    int j = 0;
   while (isalpha(line[pos])) {
        int found = 1;
        for (i=0;i<14;i++) {
            for (int j=0; j <14;j++) {
                if (line[pos+i] == line[pos+j] && pos+i != pos+j) {
                    found = 0;
                    index = pos+15;
                }
            }   
        }
            pos++;

        if (found == 1)  {
                    printf("Index:%d\n",index);
                    break;
        }                          
    }
}           
        

int main () {
    FILE * input = fopen ("input.txt","r");
    int answer = parser (input);
    //printf ("Total:%d\n",answer);
    fclose (input);
}