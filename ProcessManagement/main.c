#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
void doA(){
    printf("doA함수를 호출합니다\n");
}

void doB(){
    printf("doB함수를 호출합니다\n");
}

int main()
{
    atexit(doA);
    atexit(doB);
    
    char cmd[200];
    while (1)
    {
        scanf(" %[^\n]s",cmd);
        if (strstr(cmd,"quit"))
        {
            printf("접속을 종료합니다");
            exit(0);
        }
        execl("/bin/sh","sh","-c",cmd,NULL);
    }
    
}