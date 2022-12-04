#include <stdio.h>
#include <stdlib.h>

int get_max_cal (FILE * input) {
    size_t len;
    int num_elfs=0;
    int result = 0;
    int aux = 0;
    int max_aux = 0;
    char * line = NULL;
    while (!feof(input)) {
        while (getline (&line, &len, input) != -1) {
            aux = atoi (line);
            if (aux == 0)  {
                max_aux = 0;
                num_elfs += 1;
            }
                        max_aux += aux;
                    if (max_aux >= result) { result = max_aux;}
        }
    int max_aux = 0;

    }
    printf ("Num_elfs:%d\n",num_elfs);
    return result;
} 


int main () {
    FILE * input = fopen ("input.txt","r");
    printf ("%d\n",get_max_cal (input));
}