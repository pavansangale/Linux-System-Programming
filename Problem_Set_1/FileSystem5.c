
/*

===============================================================================================================
Problem Statement   : Write a program which accept file name and number of bytes from user and read that 
                      number of bytes from file.
Input               : 
Output              :
Commands            : 1] Compile - gcc FileSystem5.c  -o FileSystem5   2] Execute - ./FileSystem5 Test.txt 10
Description         : 
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{

    int fd = 0;
    char buffer[20] = {'\0'};
    int Ret = 0;

    if(argc != 3)
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

    Ret = read(fd,buffer,atoi(argv[2]));
    if(Ret == 0)
    {
        printf("Unable to read the data from file\n");
        return -1;
    }

    printf("Data From File : %s\n",buffer);   


    return 0;
}
