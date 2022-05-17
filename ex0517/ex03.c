#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    if (symlink("a1","alink") < 0)
    {
        perro("에러");
    }
    
}