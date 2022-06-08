
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int pid,status;

    pid = fork();

    //fork retvalue = 0;
    //child process
    if (pid == 0)
    {
        printf("child process pid = %d\n",getid());
        execl("bin/ls","ls","-al",NULL);
        system("ls");
        sleep(1);
        exit(0);
    }
    else{
        int child = waidpid(pid,&status,0);
        printf("child = %d\n",child);
        printf("parent process pid = %d\n",getpid());
        exit(0);
    }
    
}