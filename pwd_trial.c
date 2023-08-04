#include <unistd.h>
#include <stdio.h>
int main()
{
    char wd[1000];
    printf("current working directory is: %s ",getcwd(wd,sizeof(wd)));
}