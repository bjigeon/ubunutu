#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int status1 = system("data");
    printf("종료 코드 %d",WEXITSTATUS(status1));

    sleep(3);
    int status2 = system("ps");
    printf("종료 코드 %d",WEXITSTATUS(status2));

    sleep(3);
    int status3 = system("ls");
    printf("종료 코드 %d",WEXITSTATUS(status3));
}