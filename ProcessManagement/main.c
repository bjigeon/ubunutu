#define _CRT_NONSTDC_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
void doA(){
    printf("\ndoA함수를 호출합니다\n");
}

void doB(){
    printf("doB함수를 호출합니다\n");
}

extern char **environ;

int main()
{
    int *status;
    int i = 0;

    atexit(doA);
    atexit(doB);

    printf("프로그램이 시작되었습니다\n");
    char cmd[200];
    while (1)
    {

        printf("명령어를 입력하세요 : ");
        scanf(" %[^\n]s",cmd);
        if (strstr(cmd,"quit"))
        {
            printf("접속을 종료합니다");
            exit(0);
        }
        else if(strstr(cmd,"env")){
            for(i=0; environ[i];i++){
               printf("%s\n" , environ[i]);
            }
           continue;
        }
        else if(strstr(cmd,"ps")){
            system(cmd);
            continue;
        }

        int pid = fork();
        if(pid == 0){
            execl("/bin/sh","sh","-c",cmd,NULL);
        }
        int ret = waitpid(pid,status,0);
    }
    
}