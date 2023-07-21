
/*

===============================================================================================================
Problem Statement   : Write a program which accept two directory names from user and move all files from source 
                      directory to destination directory.
Commands            : 1] Compile - gcc FileSystem3.c  -o FileSystem3  2] Execute - ./FileSystem3 temp temp1
===============================================================================================================

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char oldname[50];
    char newname[50];

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
        sprintf(oldname,"%s/%s",argv[1],entry->d_name);
        sprintf(newname,"%s/%s",argv[2],entry->d_name);

        rename(oldname,newname);
    }   
    
    closedir(dp);

    return 0;
}
