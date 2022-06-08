#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// ps 현재 실행되고 있는 프로세스 보기
// ps -j pid pgid sid
// 프로세스아이디 프로세스그룹아이디 세션아이디
// kill 프로세스 죽이기
// kill -9 프로레스스그룹명

int main()
{
    int pid;
    printf("자식프로세스 생성 전 pid = %d \n",getpid());
    pid = fork();
    printf("자식프로세스 생성 후 pid = %d \n",getpid());
    printf("자식프로세스 생성 전 pgid = %d \n",getpid(getpid()));
}