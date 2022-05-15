#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/time.h>
#include<utime.h>
#include<stdlib.h>

int main(int argc , char **argv){
    DIR *dp;
    struct dirent *d;

    char directoryname[512];
    if (argc == 1)
    {
        stcpy(directoryname,".");
    }
    else{
        stcpy(directoryname,argv[1]);
    }
    printf("directoryname = %s",directoryname);

    dp = opendir(directoryname);
    if (dp = NULL)
    {
        perror("dp is null");
        exit(0);
    }
    while ((d = readdir(dp)) != NULL)
    {
        printf("%s\n",d->d_name);
    }
    
    return 0;
}
