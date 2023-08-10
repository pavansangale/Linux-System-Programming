
/*

===============================================================================================================
Problem Statement   : Write a program which accept two file names from user and check whether contents of that 
                        two files are equal or not.
Commands            : 1] Compile - gcc FileSystem3.c  -o FileSystem3  2] Execute - ./FileSystem3
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  
    char firstFileName[20] = "{\0}";
    char secondFileName[20] = "{\0}";
    int iRet = 0;
    int fd1 = 0, fd2 = 0, ret = 0;
    struct stat obj1, obj2;
    char Buffer1[1024];
    char Buffer2[1024];
    int iCnt = 0;

    printf("Enter First File Name : \n");
    scanf("%s",firstFileName);
    printf("Enter Second File Name : \n");
    scanf("%s",secondFileName);    

    fd1 = open(firstFileName,O_RDONLY);
    fd2 = open(secondFileName,O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fstat(fd1,&obj1);
    fstat(fd2, &obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Files are different as sizes are different\n");
        return -1;
    }

    while((iRet = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        iCnt++;
        iRet = read(fd2,Buffer2,(sizeof(Buffer2)));
        if(memcmp(Buffer1,Buffer2,iRet) != 0)
        {
            break;
        }
    }

    if(iRet == 0) 
    {
        printf("Both Files are Identical\n");
    }
    else
    {
        printf("Both Files are different\n");
    }

    close(fd1);
    close(fd2);

    return 0;
}
