#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int agrc, char **argv){
    printf("argc = %d\n",agrc); //파라메타 개수
    printf("argv[0] = %s\n",argv[0]);//
    printf("argv[1] = %s\n",argv[1]);

    struct atat buf;
    lstat(argv[1],&buf);

    printf("stat %o %x\n",buf.st_mode,buf.st_mode);
    // 10777
    if(S_ISREG(buf.st_mode))
        printf("일반 파일 입니다\n");
    if (S_ISDIR(buf.st_mode))
        printf("디렉토리 파일이 입니다\n");
    
    
}