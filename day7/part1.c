#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct File {
    int size;
    char* name;
}file;

struct Directory {
    int size;
    char * current_dir;
    //max files = 100?
    struct File** files;
    char *name;
    struct Directory * parent;
    int num_files;
    struct Directory** subdirs ;
    int num_subdirs;
} directory;

int fill_dirs (struct Directory *dir)
{
    // The sizes of all files contained in that directory will be added to the total size of that directory
    int sum = 0;
        for (int i = 0;i<dir->num_files;i++){
            sum += dir->files[i]->size;
        }
        dir->size = sum;

    // If there are subdirectories in that directory, the size of the directory will be equal to the
    // sum of all files in that directory plus the sum of sizes of all subdtirectories contained in that directory
    
    if (dir->num_subdirs != 0){
        for (int j = 0;j<dir->num_subdirs;j++){
            sum += fill_dirs (dir->subdirs[j]);
        }
        dir->size = sum;
    }
    return sum;
}

int sum_at_most (struct Directory *dir, int size_at_most)
{
    // If the directories size is less then the size_at_most we want,
    // we add that to the total sum.

    int sum = 0;
    if (dir->size<=size_at_most){
    sum += dir->size;
    }
    // and then we move to every subdir of the original directory recursively, therefore
    // checking every directory possible.

    for (int i = 0;i<dir->num_subdirs;i++){
        sum += sum_at_most (dir->subdirs[i],size_at_most);
    }

    return sum;
}


int parser (FILE * input, struct Directory* dir) {
    char * line = NULL;
    char * command_name;
    char * filename;
    char * dir_name;
    char * trash;
    ssize_t len;
    getline (&line,&len,input);
        if (line[0] == '$') {
            trash = strtok (line," ");
            command_name = strtok (NULL, " \n");

            // "cd" command was found
            if (!strcmp (command_name,"cd")) 
            { 
                    // "cd .." command
                    trash = strtok(NULL,"\n");

                        // move out one directory if possible
                        if (!strcmp (trash,"..")) { 
                            if (dir->parent != NULL) 
                            {
                                dir = dir->parent;
                            }
                            if (!feof (input)) parser (input,dir);
                        }
                        // "cd <directory_name> command"
                        else 
                        { 
                            dir_name = strdup (trash);
                            for (int i=0; i < dir->num_subdirs;i++) {
                                if (!strcmp (dir->subdirs[i]->name, dir_name)) { 
                                dir->subdirs[i]->subdirs = malloc (100* sizeof(struct Directory));
                                    dir = dir->subdirs[i];  // move to the subdirectory
                                } 
                            }
                            if (!feof (input)) parser (input,dir); 
                        } 
                        
            }
               
            // "ls" command was found -> in this case there's really nothing to do except continuing to read the input.
            else if (!strcmp(command_name,"ls")) {
               if (!feof (input)) parser (input,dir);
            }
        }
        else {  // Directory or File was found
            if (isalpha(line[0])) { // In case it is a dir;
                trash = strtok (line," ");
                dir_name = strtok (NULL,"\n");
                
                //Initializes the new directory
                struct Directory * newdir = malloc (sizeof(struct Directory));
                newdir->files = malloc (100*sizeof (struct File));
                newdir->name = strdup (dir_name);  
                newdir->num_files = 0;
                newdir->num_subdirs = 0;
                newdir->size = 0;
                newdir->subdirs = NULL;
                newdir->parent = dir;

                // Adds the subdirectory to the current directory we're in
                dir->subdirs[dir->num_subdirs] = newdir;
                dir->num_subdirs++;
             
                if (!feof (input)) parser (input,dir);
            } 
            else { //File was found
                trash = strtok (line," "); // In this case, trash is actually size of file
                
                // Initializes the new file
                struct File*  file = malloc (sizeof (struct File));
                file->size = atoi (trash);
                filename = strtok (NULL,"\n");
                file->name = malloc (40 * (sizeof (char)));
                file->name = strdup (filename);

                // Adds the file to the current directory
                dir->files[dir->num_files] = file;
                dir->size += file->size;
                dir->num_files++;
                if (!feof (input)) parser (input,dir);
            }
        }
}


int main () {
    FILE * input = fopen ("input.txt","r");

    //Initializes the "root" directory
    struct Directory* root = malloc (sizeof(struct Directory));
    root->name = "/";
    root->files = malloc (100* sizeof (struct File));
    root->num_files = 0;
    root->num_subdirs = 0;
    root->current_dir = NULL;
    root->size = 0;
    root->subdirs = malloc (100 * sizeof(struct Directory));    
    root->parent = NULL;

    // Function parser is called.
    // How recursion in parser works: The function is called until there is no lines left of input.
    // During each call, the function will fill the current directory with wathever comes after the "ls" command
    // If there is a "cd" command found, the "directory" the function receives as argument will be altered to be
    // the directory the outermost or one of the inermost directories, depending if "cd .." or "cd <dir_name>" was called
    parser (input,root);
    fill_dirs(root);
    int size_total = sum_at_most (root,100000);
    printf ("Total: %d\n",size_total);
    fclose (input);
}