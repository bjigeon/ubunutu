#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void en()
{

}

void start()
{
    printf(system("env"));    
}


int main()
{
    // char env = strtol("env",(char **)NULL, 2);
    // printf("%s", env);

    start();
    // char cmd[100];
    // while(1)
    // {
    //     printf("무슨 명령어를 실행 하시겠습니까?\n");
    //     scanf("%s",cmd);
        
    //     int tmpcmd = strtol(cmd,(char **)NULL, 2);
    //     switch (tmpcmd)
    //     {
    //     case env:
    //         printf("e n v");
    //         break;
        
    //     default:
    //         break;
    //     }


    // }
}