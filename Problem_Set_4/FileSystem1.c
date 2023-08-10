
/*

===============================================================================================================
Problem Statement   : Write a program which is used to demonstrate concept of I/O redirection
Commands            : 1] Compile - gcc FileSystem1.c  -o FileSystem1  2] Execute - ./FileSystem1 < Input.txt > Output.txt
===============================================================================================================

*/

#include<stdio.h>

int main(int argc, char *argv[])
{
    int iNO1 = 0;
    int iNO2 = 0;
    int iResult = 0;

    scanf("%d",&iNO1);
    scanf("%d",&iNO2);

    iResult = iNO1 + iNO2;

    printf("Addition : %d\n",iResult);

    return 0;
}
