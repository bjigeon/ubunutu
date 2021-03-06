#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

struct aa
{
    char name[512];
};

char type(mode_t mode)
{
    if (S_ISREG(mode))  return '-';
    if (S_ISDIR(mode))  return 'd';
}

char *perm(mode_t mode)
{
    static char myString[10] = "---------"; // - 9개 + 마지막 null

    strcpy(myString,"---------");

    if (mode & S_IREAD){
        myString[1] = 'r';
    }
    if (mode & S_IWRITE){
        myString[2] = 'w';
    }
    if (mode & S_IEXEC){
        myString[3] = 'x';
    }
    if (mode & S_IREAD >> 3){
        myString[4] = 'r';
    }
    if (mode & S_IWRITE >> 3){
        myString[5] = 'w';
    }
    if (mode & S_IEXEC >> 3){
        myString[6] = 'x';
    }
    if (mode & S_IREAD >> 6){
        myString[7] = 'r';
    }
    if (mode & S_IWRITE >> 6){
        myString[8] = 'w';
    }
    if (mode & S_IEXEC >> 6){
        myString[9] = 'x';
    }
    return myString;
}

void printStat(char *pathname, char *file, struct stat *st)
{
    // printf("pathname = %s", pathname);
    printf(" %c%s ", type(st->st_mode), perm(st->st_mode));
    printf(" %lld ", st->st_blocks);
    printf(" %3d",st->st_nlink);
    printf(" %s %s", (getpwuid(st->st_uid)->pw_name), (getgrgid(st->st_gid)->gr_name));
    printf(" %9lld",st->st_size);
    printf(" %12s",ctime(&st->st_mtime));
    printf(" %s\n", file);
}

// void setaa(struct aa *pa){
//     printf("setaa pa = %d\n", pa);
//     strcpy(pa->name, "안녕하세요 이릅입니다");
// }
// void printaa(struct aa *pa){
//     printf("printaa pa = %d\n", pa);
//     printf("pa->name = %s\n", pa->name);
// }

int main(int argc, char **argv)
{

    // struct aa maina;
    // printf("&maina = %d\n", &maina);
    // setaa(&maina);
    // printaa(&maina);

    // 4644
    // setuid(0);

    /*
        읽고 싶은 폴더명 입력하세요
        ls linuxclass
        linuxclass
    */

    // 디렉토리,파일 엔트
    DIR *dp;
    // 디렉토리,파일 담는곳
    struct dirent *d;
    char path[BUFSIZ];
    struct stat st;

    printf("BUFSIZ = %d\n", BUFSIZ);

    char directoryname[512];
    if (argc == 1)
    {
        strcpy(directoryname, ".");
    }
    else
    {
        strcpy(directoryname, argv[1]);
    }
    printf("directoryname =  %s\n", directoryname);

    dp = opendir(directoryname);
    if (dp == NULL)
    {
        perror("dp is null");
        exit(0);
    }
    while ((d = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", directoryname, d->d_name);
        if (lstat(path, &st) < 0){
            perror(path);
        }

        printStat(path, d->d_name, &st);

        // printf("%5d",st.st_blocks);

        // printf("%s\n", d->d_name);
        // printf("path = %s", path);
    }

    return 0;
} 