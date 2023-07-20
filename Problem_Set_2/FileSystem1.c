
/*

===============================================================================================================
Problem Statement   : Write a program which accept file name from user and read whole file
Commands            : 1] Compile - gcc FileSystem1.c  -o FileSystem1   2] Execute - ./FileSystem1 Test.txt
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024
int main(int argc, char *argv[])
{

    int fd = 0;
    char buffer[BLOCKSIZE];
    int Ret = 0;

    if(argc != 2)
    {
        printf("Invalid argument count\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    
    while((Ret = read(fd,buffer,sizeof(buffer))))
    {
        write(1,buffer,Ret);
    }

    close(fd);

    return 0;
}
