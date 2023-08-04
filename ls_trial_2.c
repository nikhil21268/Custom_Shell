#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>
#include <time.h>


void _ls(const char *dir,int op_a,int op_l)

{
    int flg=0;
    struct dirent *d;
    DIR *dh=opendir(dir);
    if(!dh)
    {
        if(errno==ENOENT)

        {
            perror("directory does not exist");

        }
        else
        {
            perror("unable to read directory");
        }
        exit(EXIT_FAILURE);
    }
    while((d=readdir(dh))!=NULL)

    {
        if(!op_a && d->d_name[0]=='.')

        {
            continue;
        }
        if(!op_l)

        {
            printf("%s ",d->d_name);
            continue;

        }
        //printf("%s ",d->d_name);
        if(op_l)
        {
            char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
            char statusDirectory[2048] = "./";
            //DIR *dir = opendir( "./");

            //struct dirent* dirent;
            struct stat status;
            //sampel
            //else if(argc == 3 && (strcmp(argv[1],"ls") == 0) && (strcmp(argv[2],"-l") == 0)) {

            //while((dirent = readdir(dir)) != NULL) {

                if(((strcmp(d->d_name,"..") != 0) && (strcmp(d->d_name,".") != 0 ))) {

                    strcat(statusDirectory,d->d_name);
                    stat(statusDirectory,&status);

                    char permission[] = "?rwxrwxrwx";

                    for(int i = 8 ; i >= 0 ; i--) {
                        if(((status.st_mode &  (1 << i)))) {

                        }
                        else {
                            permission[9-i] = '-';
                        }

                    }

                    switch (status.st_mode & __S_IFMT) {
                        case __S_IFDIR:
                            permission[0] = 'd';
                            break;
                        case __S_IFLNK:
                            permission[0] = 'l';
                            break;
                        case __S_IFREG:
                            permission[0] = '-';
                            break;
                    }

                    unsigned int link = status.st_nlink;
                    struct passwd *user = getpwuid(status.st_uid);
                    struct passwd *group = getpwuid(status.st_gid);

                    time_t time = status.st_mtim.tv_sec;
                    struct tm *localTime = localtime(&time);
                    int month = localTime->tm_mon;
                    int mday = localTime->tm_mday;
                    int hour = localTime->tm_hour;
                    int minute = localTime->tm_min;

                    printf("%s %*u %*s %*s %*ld %*s %02d %02d:%02d %s\n",permission,2,link,10,user->pw_name,10,group->pw_name,15,status.st_size,10,months[month],mday,hour,minute,d->d_name);
                    strcpy(statusDirectory,"./");
                    flg=1;
                    
                //}
            //}
        }
            
            //printf("\n");
            /*if(flg==1)
            {
                return;

            }*/
            
        }
        if(flg==0)
        {
            printf("%s ",d->d_name);

        }
        
    }
    if(!op_l)

    {
        printf("\n");

    }
    //printf("func called\n");
    
}

int main(int argc,const char *argv[])
{
    if(argc==1)

    {
        _ls(".",0,0);
    }
    else if(argc==2)

    {
        if(argv[1][0]=='-')
        {
            int op_a=0;
            int op_l=0;
            char *p=(char *)(argv[1]+1);
            while(*p)
            {
                if((*p)=='a')
                {
                    op_a=1;


                }
                else if(*p=='l')

                {
                    op_l=1;
                }
                else
                {
                    perror("unknown option error");
                    exit(EXIT_FAILURE);

                }
                p++;
            }
            /*else
            {

            }*/
            _ls(".",op_a,op_l);
        }
        else
        {
            _ls(argv[1],0,0);
        }
        
    }
    else if(argc==3)

        {
            if(argv[1][0]!='-')
            {
                perror("incorrect usage error");
            }
        }

}

/*#include <stdio.h>
#include <dirent.h>
#include <string.h>

#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define WHITE "\x1b[37m"

void Usage() {
    fprintf(stderr, "\nUsage: exec [OPTION]... [DIR]...\n");
    fprintf(stderr, "List DIR's (directory) contents\n");
    fprintf(stderr, "\nOptions\n-R\tlist subdirectories recursively\n");
    return;
}

void RecDir(char * path, int flag) {
    DIR * dp = opendir(path);
    if(!dp) {
        perror(path);
        return;
    }
    struct dirent * ep;
    char newdir[512];
    printf(BLUE "\n%s :\n" WHITE, path);
    while((ep = readdir(dp)))
        if(strncmp(ep->d_name, ".", 1))
            printf(GREEN "\t%s\n" WHITE, ep->d_name);
    closedir(dp);
    dp = opendir(path);
    while((ep = readdir(dp))) if(strncmp(ep->d_name, ".", 1)) {
        if(flag && ep->d_type == 4) {
            sprintf(newdir, "%s/%s", path, ep->d_name);
            RecDir(newdir, 1);
        }
    }
    closedir(dp);
}

int main(int argc, char ** argv) {
    switch(argc) {
    case 2:
        if(strcmp(argv[1], "-R") == 0) Usage();
        else RecDir(argv[1], 0);
        break;
    case 3:
        if(strcmp(argv[1], "-R") == 0) RecDir(argv[2], 1);
        else Usage();
        break;
    default: Usage();
    }
    return 0;
}*/

/*#include<stdio.h>
#include<dirent.h>
#include <stdlib.h>
void main(int argc,char *argv)
{
    char dirname[10];
    DIR*p;
    struct dirent *d;
    printf("Enter directory name\n");
    scanf("%s",dirname);
    p=opendir(dirname);
    if(p==NULL)
    {
    perror("Cannot find directory");
    exit(-1);
    }
    while(d=readdir(p))
    printf("%s\n",d->d_name);
}*/