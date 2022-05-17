//
//  main.c
//  FileSystem
//
//  Created by 박지건 on 2022/05/03.
//

//gcc main.c -o main  
// ./main   실행

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

void createFile()
{
    system("clear");

    FILE *fp = NULL;
	char filename[100];

	printf("파일 이름을 입력하시오(파일 만들기): ");
	scanf("%s", filename);

    strcat(filename,".txt");

    if( (fp = fopen(filename, "r")) != NULL ) {
		printf("원본 파일 %s가 이미 존재합니다\n", filename);
        printf("파일 생성 모드를 종료합니다\n");
        return;
    }

    fopen(filename,"w+");

    printf("파일을 만들었습니다.\n파일 생성 모드를 종료합니다.\n\n");
}

void addFileContents()
{
    system("clear");

	char filename[100];
    char contents[1000];
    char an;

    FILE *fp = NULL;
	printf("파일 이름을 입력하시오(내용 추가): ");

	scanf("%s", filename);

    strcat(filename,".txt");

    if( (fp = fopen(filename, "r")) == NULL ) {
		printf("원본 파일 %s을 열 수 없습니다.\n", filename);
        printf("파일 내용 추가하기 모드를 종료 합니다.\n");
        return;
	}
    else
    {
        printf("파일 내용을 덮어쓰겠습니까? (다른 문자 입력시 모드 종료) Y/N ");
        scanf(" %c", &an);

        if( an == 'y'|| an == 'Y' )
        {
            fp = fopen(filename,"w");

            printf("덮어 쓸 파일 내용을 입력하세요\n");
            scanf("%s",contents);

            fputs(contents, fp);

            printf("파일 내용 덮어쓰기가 완료되었습니다. 파일 내용 덮어쓰기 모드를 종료합니다.\n");
            fclose(fp);
        }
        else if(an == 'n' || an == 'N')
        {
            fp = fopen(filename,"a");

            printf("추가 할 파일 내용을 입력하세요\n");
            scanf("%s",contents);

            fputs(contents, fp);

            printf("파일 내용 추가가 완료되었습니다. 파일 내용 추가 모드를 종료합니다.\n");
            fclose(fp);
        }
    }
}

void readFile()
{
    system("clear");

	char filename[100];

    FILE *fp = NULL;
	printf("파일 이름을 입력하시오(읽기): ");

	scanf("%s", filename);

    strcat(filename,".txt");

	if( (fp = fopen(filename, "r")) == NULL ) {
		printf("원본 파일 %s을 열 수 없습니다.\n", filename);
        fclose(fp);

        printf("파일 읽기 모드를 종료 합니다.\n");
        return;
	}
    else
    {
        char buffer[2000];

        fp = fopen(filename, "r");

        printf("\n파일의 내용\n");

        while (feof(fp) == 0)
        {
            fgets(buffer,2000,fp);
            printf("%s",buffer);
        }
        
        printf("\n파일 읽기 모드를 종료 합니다.\n");
        fclose(fp);
    }

}

void  deleteFile()
{
    system("clear");
    char filename[100];

    FILE *fp = NULL;
	printf("파일 이름을 입력하시오(삭제): ");

	scanf("%s", filename);

    strcat(filename,".txt");

    if( (fp = fopen(filename, "r")) == NULL ) {
		printf("원본 파일 %s을 열 수 없습니다.\n", filename);
        printf("파일 삭제 모드를 종료합니다\n");
        return;
    }

    int result = remove( filename );

	if( result == 0 )
	{
		printf( "파일 삭제를 성공하였습니다. 파일 삭제 모드를 종료 합니다.\n");
	}
	else if( result == -1 )
	{
		printf( "파일 삭제 실패하였습니다. 파일 삭제 모드를 종료 합니다.\n");
	}
}

void chmode(){
    system("clear");

    FILE *fp = NULL;
	char filename[100];
    char mod[10];
    char *end;

    printf("권한을 변경할 파일 이름을 입력하시오(파일 권한변경): ");
	scanf("%s", filename);

    strcat(filename,".txt");

    if( (fp = fopen(filename, "r")) == NULL ) {
		printf("원본 파일 %s을 열 수 없습니다.\n", filename);
        printf("파일 권한 변경 모드를 종료합니다\n");
        return;
    }
    else
    {
        printf("파일 권한을 입력하시오 : ");
        scanf("%s", mod);

        chmod(filename, strtol(mod,(char **)NULL, 8));
        printf("파일 권한을 변경하였습니다.\n");

        printf("파일 권한변경 모드를 종료합니다\n");
    }
}   

void mkdi(){
    system("clear");

	char filename[100];
    
    printf("만들 폴더 이름을 입력하세요(폴더 만들기): ");
	scanf("%s", filename);

    mkdir(filename,0777);

    printf("폴더를 만들었습니다.\n");
    printf("폴더 만들기 모드를 종료 합니다.\n");
}

void rmdi(){
    system("clear");

    char filename[100];
    
    printf("삭제할 폴더 이름을 입력하세요(폴더 삭제하기): ");
	scanf("%s", filename);

    rmdir(filename);

    printf("폴더를 삭제하였습니다.\n");
    printf("폴더 삭제 모드를 종료 합니다.\n");
}

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
    printf(" %c%s ", type(st->st_mode), perm(st->st_mode));
    printf(" %lld ", st->st_blocks);
    printf(" %3d",st->st_nlink);
    printf(" %s %s", (getpwuid(st->st_uid)->pw_name), (getgrgid(st->st_gid)->gr_name));
    printf(" %9lld",st->st_size);
    printf(" %12s",ctime(&st->st_mtime));
    printf(" %s\n", file);
}

int main(int argc, char **argv) {
    DIR *dp;
    struct dirent *d;
    char path[BUFSIZ];
    struct stat st;
    char directoryname[512];
    
    while (1)
    {
        int num;
        printf("\n종료를 원하면 0번\n");
        printf("1. 파일 만들기 & 파일 덮어쓰기\n");
        printf("2. 파일 내용 추가하기\n");
        printf("3. 파일 내용 보기\n");
        printf("4. 파일 삭제\n");
        printf("5. 디렉토리 보기\n");
        printf("6. 파일 권한 변경\n");
        printf("7. 폴더 생성\n");
        printf("8. 폴더 삭제\n");

        printf("파일 모드 번호를 입력하세요.\n");
        scanf(" %d",&num);

        switch (num)
        {
        case 0:
            return 0;

        case 1:
            createFile();
            break;

        case 2:
            addFileContents();
            break;

        case 3:
            readFile();
            break;

        case 4:
            deleteFile();
            break;

        case 5:

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
                printf("\n");
            }
            break;

        case 6:
            chmode();
            break;

        case 7:
            mkdi();
            break;

        case 8:
            rmdi();
            break;

        default:
            system("clear");
            printf("다시 입력하세요.\n");
            break;
        }
    }
}
