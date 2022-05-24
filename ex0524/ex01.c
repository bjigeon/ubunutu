#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int fd;
    fd = open("aaa",O_RDWR);
    struct flock lock;

    if (fd < 0)
    {
        printf("파일 열기 실패");
    }
    
    lock.l_type = F_WRLCK; //잠금 함수
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 100;

    fcntl(fd,F_SETLKW,&lock);//잠금설정

    if (lock.l_type == F_WRLCK)
    {
        printf("잠금 되어있음");
        sleep(20); //20초 동안 멈추기
    }
    lock.l_type = F_UNLCK;//잠금해제 함수
    fcntl(fd,F_SETLKW,&lock);//잠금 해제
    printf("잠금해제됨");

    close(fd);

}

