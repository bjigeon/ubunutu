#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid, status, child;

    pid = fork();
    printf("처음 프로세스 pid = %d\n",getpid());

    if (pid == 0)
    {
        //자식 프로세스
        printf("자식프로세스 pid = %d\n",getpid());
        exit(1);
    }
    child = wait(&status);
    printf("부모 프로세스 pid = %d child = %d\n",getpid(),child);
    
}