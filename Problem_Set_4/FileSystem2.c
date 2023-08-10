
/*

===============================================================================================================
Problem Statement   : Write a program which accept directory name form user and create new directory of that name
Commands            : 1] Compile - gcc FileSystem2.c  -o FileSystem2  2] Execute - ./FileSystem2
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
  
    char dirName[20] = "{\0}";
    int iRet = 0;

    printf("Enter the Name of New Directory : \n");
    scanf("%s",dirName);

    iRet = mkdir(dirName,0777);
    // upon scuuessful creation of directory makdir() return 0

    if(iRet == 0) 
    {
        printf("Directory Created \n");
    }
    else
    {
        printf("Directory Not Created \n");
    }

    return 0;
}
