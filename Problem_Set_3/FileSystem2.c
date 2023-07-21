
/*

===============================================================================================================
Problem Statement   : Write a program which accept directory name and file name from user and check whether that 
                      file is present in that directory or not.
Commands            : 1] Compile - gcc FileSystem2.c  -o FileSystem2  2] Execute - ./FileSystem2 test test2.txt
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

    if(argc != 3)
    {
        printf("Invalid argument count\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        if((strcmp(argv[2],entry->d_name)) == 0)
        {
            printf("File is present in directory\n");
            break;
        }
    }   

    if(entry == NULL)
    {
        printf("There is no such file\n");
        return -1;
    }
    
    closedir(dp);

    return 0;
}
