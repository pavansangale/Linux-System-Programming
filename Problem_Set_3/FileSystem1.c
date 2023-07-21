
/*

===============================================================================================================
Problem Statement   : Write a program which accept two file names from user and copy the contents of an existing 
                      file into newly created file
Commands            : 1] Compile - gcc FileSystem1.c  -o FileSystem1  2] Execute - ./FileSystem1 test1.txt test2.txt
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSource = 0;
    int fdDest = 0;
    int Ret = 0;

    char Buffer[BLOCKSIZE] = {'\0'};

    if(argc != 3)
    {
        printf("Invalid argument count\n");
        return -1;
    }

    fdSource = open(argv[1], O_RDONLY);
    if(fdSource == -1)
    {
        printf("Unable to open the source file\n");
        return -1;
    }

    fdDest = creat(argv[2],0777);
    if(fdDest == -1)
    {
        printf("Unable to create destination file\n");
        close(fdSource);
        return -1;
    }

    while((Ret = read(fdSource,Buffer,sizeof(Buffer))) != 0)
    {
        write(fdDest,Buffer,Ret);
        memset(Buffer,0,sizeof(Buffer));
    }

    close(fdSource);
    close(fdDest);

    return 0;
}
