
/*

===============================================================================================================
Problem Statement   : Write a program which accept file name and mode from user and then open that 
                      file in specific mode.
Input               : 
Output              :
Commands            : 1] Compile - gcc FileSystem2.c  -o FileSystem2    2] Execute - ./FileSystem1 Test.txt Read
Description         : 
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int Mode = 0;

    if(argc != 3)
    {
        printf("Invalid Argumnets\n");
        return -1;
    }

    if(strcmp(argv[2],"Read") == 0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"Write") == 0)
    {
        Mode = O_WRONLY;
    }    
    else
    {
        Mode = O_RDONLY;
    }

    fd = open(argv[1], Mode);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    else
    {
        printf("File is opened with fd = %d\n",fd);
    }

    return 0;
}
