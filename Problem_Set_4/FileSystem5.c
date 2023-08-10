
/*

===============================================================================================================
Problem Statement   : Write a program which accept file name and position from user and read 20 bytes from that position.
Commands            : 1] Compile - gcc FileSystem5.c  -o FileSystem5  2] Execute - ./FileSystem5
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
  

    int iRet = 0;
    int fd1 = 0;
    char Buffer1[20];
    int iCnt = 0;
    char fileName[20];
    int start = 0;

    printf("Enter File Name : \n");
    scanf("%s",fileName);

    printf("Enter position :");
    scanf("%d",&start);


    fd1 = open(fileName,O_RDONLY);
    if(fd1 == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    
    iRet = lseek(fd1,start,SEEK_CUR);
    read(fd1,Buffer1,20);
    write(1,Buffer1,20);              

    close(fd1);

}

