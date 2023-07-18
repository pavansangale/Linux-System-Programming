
/*

===============================================================================================================
Problem Statement   : Write a program which accept file name from user and print all 
                      the information about the that file.
Input               : 
Output              :
Commands            : 1] Compile - gcc FileSystem4.c  -o FileSystem4   2] Execute - ./FileSystem4 Test.txt
Description         : 
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat statObj;

    if(argc != 2)
    {
        printf("Invalid Argumnets\n");
        return -1;
    }

    stat(argv[1],&statObj);

    printf("File Name            : %s\n",argv[1]);
    printf("Inode Number         : %ld\n",statObj.st_ino);
    printf("File Size            : %ld\n",statObj.st_size);
    printf("Mode                 : %d\n",statObj.st_mode);
    printf("Number of blocks     : %ld\n",statObj.st_blocks);
    printf("File System Number   : %lu\n",statObj.st_dev);
    printf("Number of links      : %lu\n",statObj.st_nlink);


    return 0;
}
