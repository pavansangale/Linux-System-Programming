
/*

===============================================================================================================
Problem Statement   : Write a program which accept directory name from user and print name of such a file
                      having largest size.
Commands            : 1] Compile - gcc FileSystem5.c  -o FileSystem5   2] Execute - ./FileSystem5 
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{

    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    int i = 1;
    char *fname = NULL;
    long int iMax = 0;

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
        stat(entry->d_name,&sobj);
        if(sobj.st_size > iMax)
        {
            iMax = sobj.st_size;
        }       
    }
    while((entry = readdir(dp)) != NULL)
    {
        stat(entry->d_name,&sobj);
        if(iMax == sobj.st_size)
        {
            printf("Largest File is %s with size %ld\n",entry->d_name,iMax);
        }       
    }
    closedir(dp);

    return 0;
}
