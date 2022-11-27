#include "../include/libcpe.h"
#include <string.h>

int main(int argc, char** argv)
{
    char command[64];
    
    if(argc>1)
    { 
        if(strcmp(argv[1], "modify") == 0)     
        {
            sprintf(command, "./x%s %s", argv[1], argv[2]);
            system(command);
        }
        else if(strcmp(argv[1], "run") == 0)     
        {
            sprintf(command, "./x%s", argv[1]);
            system(command);
        }
        else
            printf("\n[ERROR] Could not load module : %s.\n\n", argv[1]);
    }
    else
        printf("\n[ERROR] xesc needs module specification as command line argument.\n\n");
}