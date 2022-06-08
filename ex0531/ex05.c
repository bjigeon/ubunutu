#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    if (fork() == 0)
    {
        printf("1번쨰 자식프로셋, 시작\n");
        execl("/bin/echo", "echo", "hihi",NULL);
        printf("1번째 자식프로세스 끝");
        exit(1);
    }
    if (fork() == 0)
    {
        printf("2번쨰 자식프로셋, 시작\n");
        execl("/bin/date", "date",NULL);
        printf("2번째 자식프로세스 끝");
        exit(1);
    }
    if (fork() == 0)
    {
        printf("3번쨰 자식프로셋, 시작\n");
        execl("/bin/ls", "ls", "-al",NULL);
        printf("3번째 자식프로세스 끝");
        exit(1);
    }
    
}