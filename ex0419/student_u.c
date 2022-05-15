#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

typedef struct 
{
    char name[24];
    int id;
    int score;
} STUDENT;

int main(){
    int fd, fd1;
    fd = open("studentdb", O_RDWR);
    
    if(fd == -1){
        printf("file open fail");
    }

    fd1 = open("studentdb", O_RDONLY);
    printf("fd = %d", fd);
    printf("fd1 = %d", fd1);
    char c;
    STUDENT student;

    do{
        printf("검색하실 학번을 입력하세요");
        scanf("%d", &student.id);
        if(student.id != 0){
            lseek(fd, sizeof(student.id), SEEK_SET);
            read(fd, &student, sizeof(student));

            printf("한번 = %d, 이름 = %s, 점수 = %d", student.id, student.name, student.score);

            printf("수정하실 점수 입력 ? ");

            scanf("%d", &student.score);
            if(student.score != 0){
                lseek(fd, -(sizeof(student)), SEEK_CUR);
                write(fd, &student, sizeof(student));
            }
        }

        printf("계속하시겠습니까? Y/N");
        scanf(" %c", &c);
    }while(c == 'Y' || c == 'y');
    close(fd);
    return 0;
}