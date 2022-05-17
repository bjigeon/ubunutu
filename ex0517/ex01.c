#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
    char di_name[20];
    char *di_name2 = "aaa";

    if (argc != 2)
    {
       strcpy(di_name,"temp");
    }
    else
    {
        strcpy(di_name,argc[1]);
    }

    printf("di_name = %s",di_name);
    
    if (mkdir(di_name, 0777) == -1)
    {
        perror("만들기 실패");
        return 1;
    }
    
    return 0;
}