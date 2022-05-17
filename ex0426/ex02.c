#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argv, char **argv){
    int perm = strtol(&argv[1],(char)**NULL,8);
    chmod(argv[2],perm);
}