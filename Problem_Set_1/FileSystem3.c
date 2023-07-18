
/*

===============================================================================================================
Problem Statement   : Write a program which accept file name and on mode and that program checks whether \
                      our process can access that file in accepted mode or not.
Input               : 
Output              :
Commands            : 1] Compile - gcc FileSystem3.c  -o FileSystem3   2] Execute - ./FileSystem1 Test.txt Read
Description         : 
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int Mode = 0;

    if(argc != 3)
    {
        printf("Invalid Argumnets\n");
        return -1;
    }

    if(strcmp(argv[2],"Read") == 0)
    {
        Mode = R_OK;
    }
    else if(strcmp(argv[2],"Write") == 0)
    {
        Mode = W_OK;
    }    
    else if(strcmp(argv[2],"Execute") == 0)
    {
        Mode = X_OK;
    }

    if(access(argv[1], Mode) < 0)
    {
        printf("Unable to access %s file in %s mode\n",argv[1],argv[2]);
    }
    else
    {
        printf("%s file accessible in %s mode\n",argv[1],argv[2]);
    }

    return 0;
}
