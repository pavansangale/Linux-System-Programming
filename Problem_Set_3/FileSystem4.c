
/*

===============================================================================================================
Problem Statement   : Write a program which accept directory name from user and delete all empty files from that directory.
Commands            : 1] Compile - gcc FileSystem4.c  -o FileSystem4  2] Execute - ./FileSystem4 test
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char name[30] = {'\0'};

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

   
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size == 0)
            {
                remove(name);    
            }       
        }
    }

    closedir(dp);

    return 0;
}
