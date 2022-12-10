#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int parser (FILE * input) {

    // Calculates the dimensions of the matrix
    char * line = NULL;
    ssize_t len;
    int rows = 0;
    int columns = 0;
    getline(& line,& len,input);
    for (int i=0; i < strlen (line);i++) 
    {
            columns++;
    }
    rows++;
    while (getline(& line,& len,input) != -1) 
    {
        rows++;
    }
    columns--;
    
    // Allocating sapce the matrix
    int** matrix = malloc(rows * sizeof(int*));   
    for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(columns * sizeof(int));
    }
  
    // Filling the matrix with the input
    rewind (input);
    line = NULL;
    int row = 0;
    while (getline(& line,& len,input) != -1) 
    {
        for (int i=0; i < columns;i++) 
        {
        matrix [row][i] = line[i] - '0';
        }
    row++;
    }

    // Determines wether each tree is visible
    int num_visible = 0;
    for (int i=1; i < rows-1;i++) 
    {
        for (int j=1; j < columns-1;j++) 
        {
            // is_visible_<side> being 0 means that it is visible from that side
            int is_visible_top = 0;
            int is_visible_left = 0;
            int is_visible_rigth = 0;
            int is_visible_down = 0;
            int current = matrix[i][j];

            // aux is j+1 so that we don't compare the current tree with itself
            int aux = j+1;  

                //
                while (aux < columns) 
                {
                    // If we find a tree taller then the current one, then the current one is not visible from that side
                    if (matrix [i][aux] >= current) {
                        is_visible_rigth = 1; // means that it is not visible
                    }

                aux++;
                }
            
            // aux is j-1 so that we don't compare the current tree with itself
            aux = j-1;
                while (aux >= 0) 
                {
                    if (matrix [i][aux] >= current) 
                    {
                        is_visible_left = 1;
                    }
                    
                aux--;
                }

            // aux is i+1 so that we don't compare the current tree with itself
            aux = i+1;
                while (aux < rows) 
                {
                    if (matrix [aux][j] >= current) 
                    {
                        is_visible_down = 1;
                    }
                aux++;
                }
            
            // aux is i-1 so that we don't compare the current tree with itself
            aux = i-1; 
                while (aux >= 0) 
                {
                    if (matrix [aux][j] >= current) {
                        is_visible_top = 1;
                    }

                aux--;
                }
                
            // If the tree is visible from any side, increments the counter of visible trees by 1
            if (is_visible_down == 0 || is_visible_top == 0 || is_visible_left == 0 || is_visible_rigth == 0) 
            {
                num_visible++;
            }
        }
    }
    num_visible += 2*columns + 2*(rows -2);
    return num_visible;
}

int main () {
    FILE * input = fopen ("input.txt","r");
    int answer = parser (input);
    printf ("Total:%d\n",answer);
    fclose (input);
}