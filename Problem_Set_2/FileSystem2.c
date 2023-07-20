
/*

===============================================================================================================
Problem Statement   : Write a program which accept file name from user and write string in that
Commands            : 1] Compile - gcc FileSystem2.c  -o FileSystem2   2] Execute - ./FileSystem2 test1.txt Hi
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{

    int fd = 0;
    int Ret = 0;
    char *inputString = "Hello !";

    if(argc != 2)
    {
        printf("Invalid argument count\n");
        return -1;
    }

    fd = open(argv[1], O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    write(fd,inputString,sizeof(inputString));

    close(fd);

    return 0;
}
