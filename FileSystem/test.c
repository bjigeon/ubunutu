#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth)
{
    system("clear");
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    if((dp = opendir(dir)) == NULL)
    {
        fprintf(stderr, "cannot open directory: %s", dir);
        return;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name, &statbuf);
        if(S_ISDIR(statbuf.st_mode))
        {
            if(strcmp(".", entry->d_name) == 0 ||
                strcmp("..", entry->d_name) == 0)
                continue;
            printf("%*s%s/", depth, "", entry->d_name);
            printdir(entry->d_name, depth+4);
        }
        else printf("%*s%s", depth, "", entry->d_name);
    }
    chdir("..");
    closedir(dp);
}

int main()
{
    // char mod = "777";
    // int tmp;
    // char result[10];

    // for (int j = 0; j < 3; j++)
    // {
    //    mod[j] = (int)mod[j];
    //     for (int i = 4; i >= 0; --i) { //8자리 숫자까지 나타냄
    //         tmp = mod[j] >> i & 1;
    //     }
    //     strcat(result,tmp);
    // }
    // printf("%s",result);

    chmod("asd.txt", 511);
}