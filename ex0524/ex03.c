#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
       printf("%s\n",argv[i]);
    }
    
}