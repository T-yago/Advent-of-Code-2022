#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int handler (FILE * input) {

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
    // One collumn must be deducted because of "\n"
    columns--;
    
    
    // Allocating space for the matrix
   
    int** matrix = malloc(rows * sizeof(int*));   
    for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(columns * sizeof(int));
    }
  

    rewind (input);
    line = NULL;
    int row = 0;
    int largest_tree_scenic = 0;

    // Fills the matrix with the input
    while (getline(& line,& len,input) != -1) 
    {
        for (int i=0; i < columns;i++) 
        {
        matrix [row][i] = line[i] - '0';
        }
    row++;
    }
    
    // Gets the the tree scenic score for each tree.
    for (int i=0; i < rows;i++) 
    {
        for (int j=0; j < columns;j++) 
        {

        // Initialing each scenic value
        // This also means that edges will automatically have some sort of 0 in some direction
        int scenic_top = 0;
        int scenic_left = 0;
        int scenic_rigth = 0;
        int scenic_down = 0;

        // Current represents the current tree to be analised
        int current = matrix[i][j];            
        
        // Stop will be used so that whenever we reach a tree higher than the current one we're analising,
        // we don't continue looking further
        int stop = 0;
        
        // aux is j+1 so that we don't compare the current tree with itself
        int aux = j+1;  
            while (aux < columns && stop == 0) 
            { 
            
                if (matrix [i][aux] >= current) 
                {
                    stop =1; 
                    scenic_rigth++;
                } 
                else scenic_rigth++;
            
            aux++;
            }

        stop=0;
       
        // aux is j-1 so that we don't compare the current tree with itself
        aux = j-1;
            while (aux >= 0 && stop == 0) 
            {
               
                if (matrix [i][aux] >= current) 
                {
                stop = 1;
                scenic_left++;
                }
                else {scenic_left++;}
            
            aux--;
            }
        
        
        // aux is i+1 so that we don't compare the current tree with itself
        aux = i+1;
        stop=0;
            while (aux < rows && stop == 0) 
            {
               
                if (matrix [aux][j] >= current) 
                {
                    stop = 1;
                    scenic_down++;
                }
                else scenic_down++;

            aux++;
            }

        // aux is i-1 so that we don't compare the current tree with itself
        aux = i-1;
        stop=0;
            while (aux >= 0 && stop == 0) 
            {

                if (matrix [aux][j] >= current) 
                {
                    stop = 1;
                    scenic_top++;
                }
                else scenic_top++;
            
            aux--;
            }

            // Calculates the largest tree_scenic 
            int tree_scenic = scenic_down * scenic_left * scenic_rigth * scenic_top;
            if (tree_scenic > largest_tree_scenic) largest_tree_scenic = tree_scenic;
        }
    }

return largest_tree_scenic;
}


int main () {
    FILE * input = fopen ("input.txt","r");
    int answer = handler (input);
    printf ("Total:%d\n",answer);
    fclose (input);
}