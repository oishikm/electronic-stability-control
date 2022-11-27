#include <stdio.h>
#include<string.h>

int main(int argc, char** argv)
{
    FILE* fptr;
    char read_buffer[BUFSIZ];
    char cfg_specification[16];
    char cfg_file_path[64];

    if(argc>1)
    { 
        strcpy(cfg_specification, argv[1]);
        
        sprintf(cfg_file_path, "./src/modify_%s.txt", cfg_specification);
        fptr = fopen(cfg_file_path, "r");
        if(fptr)
        {
            while(fgets(read_buffer, BUFSIZ, fptr) != NULL)
                printf("%s", read_buffer);
            
            fclose(fptr);
        }
        else
            printf("\n[ERROR] Could not read configuration manual : %s.\n\n", cfg_file_path);
    }
    else
        printf("\n[ERROR] xmodify needs configuration specification as command line argument.\n\n");
    return 0;
}