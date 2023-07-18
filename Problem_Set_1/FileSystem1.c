
/*

==================================================================================================
Problem Statement   : Write a program which accept file name from user and open that file.
Input               : 
Output              :
Commands            : 1] Compile - gcc FileSystem1.c  -o FileSystem1    2] Execute - ./FileSystem1 Test.txt
Description         : 
==================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;

    if(argc != 2)
    {
        printf("Invalid Argumnets\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
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
