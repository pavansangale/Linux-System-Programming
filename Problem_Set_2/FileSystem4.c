
/*

===============================================================================================================
Problem Statement   : Write a program which accept directory name from user and print all file names and its 
                      types from that directory
Commands            : 1] Compile - gcc FileSystem4.c  -o FileSystem4   2] Execute - ./FileSystem4 
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
    char *type = NULL;
    
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
        if(S_ISREG(sobj.st_mode))
        {
            type = "Regular";
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            type = "Directory";
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            type = "Symbloic Link";
        }
        printf("FIle Name : %20s  Type : %s\n",entry->d_name,type);
    }
    closedir(dp);

    return 0;
}
