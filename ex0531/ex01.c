#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void atexit_handler1()
{
    printf("atexit_handler1 함수 호출합니다");
}

void atexit_handler2()
{
    printf("atexit_handler2 함수 호출합니다");
}

int main()
{
    atexit(atexit_handler1);
    atexit(atexit_handler2);
    printf("main 함수 종료\n");
    exit(0);
}