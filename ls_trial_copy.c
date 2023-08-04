//#include <dir.h>
#include <dirent.h>
//#include "dir.h"
//#include <io.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
struct fil
{
    char name[20];
    long size;
}fb[50],temp;
void main(int argc,char *argv[])
{
    struct ffblk f;
    struct ftime t;
    int d,i,j,k;
    if(argc==1)
    {
        d=findfirst("*.c",&f,2);
        while(!d)
        {
            printf("\n %s",f.ff_name);
            d=f.findnext(&f);

        }

    }
    if(argc>2)

    {
        perror("error");
        exit(0);
    }
    /*if(strcmp(arg[1],"-a")==0)
    {
        i=0;
        d=findfirst("*.c",&f,2);
        while(!d)
        {
            strcpy(fb[i].name,f.ff_name);
            fb[i].size=f.ff_size;
            d=findnext(&f);
            i++;

        }
        for(k=0;k<i;k++)
        {
            for(j=0;j<i;j++)
            {
                if(fb[j].name[0]>fb[j+1].name[0])
                {
                    temp=fb[j];
                    fb[j]=fb[j+1];
                    fb[j+1]=temp;

                }

            }
            
        }
        for(j=0;j<i;j++)
        {
            printf("\n %s \t \t %d ",fb[j].name,fb[j].size);
            fp=fopen(fb[j].name,"r");
            getftime(fileno(fp),&t);
            printf("\t \t %d-%d-%d",t.ft_day,t.ft_month,t.ft_year+1980);
            printf("\t \t %d:%d:%d",t.ft_hour,t.ft_min,t.ft_tsec);
            
        }
        

    }*/
    if((strcmp(argv[-1],"-l"))==0)
    {
        i=0;
        d=findfirst("*.c",&f,2);
        while(!d)
        {
            strcpy(fb[i].name,f.ff_name);
            fb[i].size=f.ff_size;
            d=findnext(&f);
            i++;

        }
        for(k=0;k<i;k++)
        {
            for(j=0;j<i;j++)
            {
                if(fb[j].name[0]>fb[j+1].name[0])
                {
                    temp=fb[j];
                    fb[j]=fb[j+1];
                    fb[j+1]=temp;

                }

            }
            
        }
        for(j=0;j<i;j++)
        {
            printf("\n %s \t \t %d ",fb[j].name,fb[j].size);
            FILE* fp=fopen(fb[j].name,"r");
            getftime(fileno(fp),&t);
            printf("\t \t %d-%d-%d",t.ft_day,t.ft_month,t.ft_year+1980);
            printf("\t \t %d:%d:%d",t.ft_hour,t.ft_min,t.ft_tsec);
            
        }

    }


}