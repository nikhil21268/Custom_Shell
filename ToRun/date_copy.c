#include<stdio.h>                                                                
#include<time.h>   
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void get_FileCreationTime(char *path) {
    struct stat attr;
    stat(path, &attr);
    printf("Last modified time: %s", ctime(&attr.st_mtime));
}


int main(int argc,char *argv[])
{
    //if(argv[1]=="-u")
    char str1[]={'-','u','\0'};
    char str2[]={'-','r','\0'};
    //printf("first one %s\n",argv[0]);
    //printf("%s\n",argv[1]);
    if(argv[1]!=NULL)
    
    {
        if(strcmp(argv[1],str1)!=0 && strcmp(argv[1],str2)!=0)
        {
            printf("bad input.. check your args...\n");
            return 1;
        }

    } //&& strcmp(argv[1],str1)==0)
    if(argv[1]!=NULL && strcmp(argv[1],str1)==0)
    {
        if(argv[2]!=NULL)
        {
            printf("bad input.. check your args...\n");
            return 1;

        }
        //for utc time
        time_t tmi;
        struct tm* utcTime;

        time(&tmi);
        utcTime = gmtime(&tmi);

        printf("UTC Time: %2d:%02d:%02d\n", (utcTime->tm_hour) % 24, utcTime->tm_min, utcTime->tm_sec);

    }
    

    else if(argv[1]!=NULL && strcmp(argv[1],str2)==0)
    {
        if(argv[3]!=NULL)
        {
            printf("bad input.. check your args...\n");
            return 1;

        }
        get_FileCreationTime(argv[2]);
        /*if(argv[3]!=NULL)
        {
            printf("bad input.. check your args...\n");
            return 1;

        }*/

    }
    
    else
    {
        char* time_now;                                                               
        time_t t = time(NULL);                                                        
        time_now = ctime(&t);                                                         
                                                                                        
        printf("date and time now: %s", time_now);


    }


    
    

}