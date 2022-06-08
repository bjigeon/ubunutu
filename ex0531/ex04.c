#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    printf("여기서 출력\n");
    if (fork() == 0)
    {
        sleep(3);
        execl("/bin/echo", "echo" ,"hello",NULL);
        printf("exel 실행후 출려됨\n");
        exit(1);
    }
    printf("부모 프로세스 종료");
    
}