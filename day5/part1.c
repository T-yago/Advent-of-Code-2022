#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void handler () {
    //parsing of stack
    FILE * input_stack = fopen ("stack.txt","r");
    char  matrix [56][9];
    for (int i=0; i <= 9;i++) {
        for (int j=0; j <= 56; j++) {
            matrix [i][j] = ' ';
        }
    }  
    char * line = NULL;
    ssize_t len;
    int row = 7;
    while (getline(& line,& len,input_stack) != -1 && row >= 0) {
            int column = 0;
            for (int i=1;i<34;i+=4) {
                    if(line[i] != ' ') {
                    matrix [row][column] = line[i];  
                    }
            column++;
            }
    row--;
    }

    //Parsing of commands
    FILE * input = fopen ("input.txt","r");
    line = NULL;
    char * trash;
    int num_crates;
    ssize_t len2;
    int from;
    int to;
    int cont = 0;
    while (getline(& line,&len2,input) != -1) {
        trash = strtok (line," ");
        num_crates = atoi(strtok (NULL, " "));
        trash =  (strtok (NULL, " "));
        from =  atoi (strtok (NULL, " "));
        trash =  (strtok (NULL, " ")); 
        to = atoi (strtok (NULL, "\n"));

        from--;
        to--;
        
        int size_from=0;
        int size_to = 0;
        for (int i=0;(matrix[i][from])>= 65 && (matrix[i][from]) <= 90 ;i++) {               
            size_from++;
        }
        for (int i=0; (matrix[i][to])>= 65 && (matrix[i][to]);i++) {
            size_to++;
        }
        // Filling the matrix
        while (num_crates >0 && (matrix[size_from-1][from])>= 65 && (matrix[size_from-1][from]) <= 90) {
            char aux = matrix[size_from-1][from];
            matrix[size_from-1][from] = ' ';
            matrix [size_to][to] = aux;
            num_crates--;
            size_from--;
            size_to++;
        }

    }
    int index_i;
    int index_j;
    for (int i= 0; i <= 8; i++) {
        for (int j=0;isalpha (matrix [j][i]); j++) {
            index_i = i;
            index_j = j;    
        }
    printf ("Top%d: %c\n",index_i+1,matrix[index_j][index_i]);
    }
}

int main () {
    handler (); 
}

