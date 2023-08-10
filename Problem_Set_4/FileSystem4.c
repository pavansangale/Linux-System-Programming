
/*

===============================================================================================================
Problem Statement   : Write a program which accept directory name from user and copy first 10 bytes from all regular
                        files into newly created file name as Demo.txt
Commands            : 1] Compile - gcc FileSystem4.c  -o FileSystem4  2] Execute - ./FileSystem4
===============================================================================================================

*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/dir.h>

int main(int argc, char *argv[])
{
  
    char dirName[20] = "{\0}";
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    int iRet = 0;
    int fd1 = 0, fd2 = 0, fd3 = 0, ret = 0;
    struct stat obj1, obj2;
    char Buffer1[10];
    char Buffer2[1024];
    int iCnt = 0;
    char name[20];

    printf("Enter Directory Name : \n");
    scanf("%s",dirName);
  
    dp = opendir(dirName);
    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    }

    fd2 = creat("Demo.txt", 0777);
    if(fd2 == -1)
    {
        printf("File is not created \n");
        return -1;
    }
    
    fd3 = open("Demo.txt",O_WRONLY);
    if(fd3 == -1)
    {
        printf("Unable to open Demo.txt File file\n");
        return -1;
    }     

    while((entry = readdir(dp)) != NULL)
    {
       
        sprintf(name,"%s/%s",dirName,entry->d_name);
        stat(name,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            //printf("%20s\n",entry->d_name);
            
            fd1 = open(entry->d_name,O_RDONLY);
            if(fd1 == -1)
            {
                printf("Unable to open file\n");
                return -1;
            }

            iRet = read(fd1,Buffer1,10);
            write(fd3,Buffer1,iRet);            
        }
    }

    printf("Successfully Copied the 10 bytes from all files in the dir : %s and combined it into Demo.txt\n",dirName);


   

    close(fd1);
    close(fd2);
    close(fd3);
    closedir(dp);
    return 0;
}

