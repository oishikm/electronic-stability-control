#include "../include/libcpe.h"

int main(int argc, char** argv)
{
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
        printf("\n[ERROR] xrun needs configuration specification as command line argument.\n\n");
}