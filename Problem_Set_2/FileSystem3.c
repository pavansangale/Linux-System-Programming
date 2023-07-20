
/*

===============================================================================================================
Problem Statement   : Write a program which accept directory name from user and print all file names from that directory
Commands            : 1] Compile - gcc FileSystem3.c  -o FileSystem3  2] Execute - ./FileSystem3 
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>


int main(int argc, char *argv[])
{

    DIR *dp = NULL;
    struct dirent *entry = NULL;
    
    if(argc != 2)
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
        printf("%s\n",entry->d_name);
    }
    closedir(dp);

    return 0;
}
