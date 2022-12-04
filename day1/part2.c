#include <stdio.h>
#include <stdlib.h>

int get_max (int *array, int size) {
    int i;
    int aux;
    int max = 0;
    int index_of_max;
    for (i = 0; i < size; i++) {
        aux = array[i];
        //printf ("Elf number%d",i);
        //printf (":%d\n",aux);
        if (aux > max) {max=aux;
        index_of_max = i;
        }
    }
        printf ("MAX:%d\n",max);
       array [index_of_max] = 0;
        printf ("INDEX:%d\n\n",index_of_max);
        return index_of_max;
}


void get_max_cal (FILE * input) {
    size_t len;
    int index_of_max;
    int size = 261;
    int aux = 0;
    int max=0;
    char * line = NULL;
    int array_elfs [261];
    int i = 0;
    for (i=0; i < 261; i++) {
        array_elfs[i] = 0;
    }
    i = 0;
    while (!feof(input)) {
        while (getline (&line, &len, input) != -1) {
            aux = atoi (line);
           
            array_elfs [i] += aux;
             if (aux == 0)  {
             i++;
            }
        }
    }
    int max_index = get_max (array_elfs, size);
    array_elfs [max_index] = 0;
    max_index = get_max (array_elfs, size);
    array_elfs [max_index] = 0;
    get_max (array_elfs, size);
/*int total = 0;
    for (int j = 0; j < size; j++) {
        aux = array_elfs[j];
        printf ("Elf number%d",j);
        printf (":%d\n",aux);
        if (aux > max) {max=aux;
        index_of_max = j;
        }
        else {;}
    }
        printf ("MAX:%d\n",max);
       array_elfs [index_of_max] = 0;
        printf ("INDEX:%d",index_of_max);
        total += max;
        max = 0;
for (int j = 0; j < size; j++) {
        aux = array_elfs[j];
        printf ("Elf number%d",j);
        printf (":%d\n",aux);
        if (aux > max) {max=aux;
        index_of_max = j;
        }
        else {;}
    }
        printf ("MAX:%d\n",max);
       array_elfs [index_of_max] = 0;
        printf ("INDEX:%d",index_of_max);
        total += max;
printf ("TOTAL:%d\n",total);

*/
} 

int main () {
    FILE * input = fopen ("input.txt","r");
    get_max_cal (input);
}