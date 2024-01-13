#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <ctype.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>

int flg=0;

int main(int argc,char *argv[10000])
{
    /*char str1[]="-n";
    char str2[]="-b";*/
    char str1[]={'-','n','\0'};
    char str2[]={'-','b','\0'};


    if(strcmp(argv[1],str1)!=0 && strcmp(argv[1],str2)!=0)
    {
        int i=1;
        //int flg=0;
        /*printf("%s\n",argv[1]);
        printf("enterd\n");*/
        while(argv[i]!=NULL)

        {
            FILE *fptr;
            //printf("%s\n",argv[i]);
            //printf("ok1\n");
            fptr=fopen(argv[i],"r");
            ///printf("ok2\n");
            //printf("%d\n",fptr);
            /*if(fptr==NULL )//|| argc!=2)
            {
                printf("error");

            }*/
            /*else if(fptr!=NULL)

            {
                printf("werird\n");
            }*/

            if(!fptr )//|| argc!=2)
            {
                printf("error: file does not exist\n");
                return 1;

            }
            if(fptr!=NULL)
            {
                
                char c;
                while((c=fgetc(fptr))!=EOF)
                {
                    //printf("did\n");
                    flg=1; 
                    printf("%c",c);
                }
                fclose(fptr);
                i++;
                printf("\n");

            }
            
            /*char c;
            while((c=fgetc(fptr))!=EOF)
            {
                //printf("did\n");
                flg=1; 
                printf("%c",c);
            }
            /*if(flg==0)
        {
            printf("what\n");
            perror("file does not exist");

        }*/
            //printf("done something\n");
            /*if(fptr!=NULL)
            {
                fclose(fptr);
                i++;
                printf("\n");

            }*/
            


        }

        if(flg==0)
        {
            //printf("what\n");
            perror("file does not exist");

        }

    }
    else if(strcmp(argv[1],str1)==0)

    {
        //int flg=0;
        FILE *fptr;
        fptr=fopen(argv[2],"r");
        if(!fptr )//|| argc!=2)
        {
            printf("error");

        }
        char c;
        printf("1  ");
        int j=2;
        while((c=fgetc(fptr))!=EOF)
        {
            flg=1;
            printf("%c",c);
            if(c=='\n')

            {
                printf("%d  ",j);
                j++;
            }
        }
        //printf("done something\n");
        printf("\n");
        fclose(fptr);

        if(flg==0)
        {
            //printf("what\n");
            perror("file does not exist");

        }


    }
    else if(strcmp(argv[1],str2)==0)

    {
        //int flg=0;
        FILE *fptr;
        fptr=fopen(argv[2],"r");
        if(!fptr )//|| argc!=2)
        {
            printf("error");
            

        }
        char c;
        int j=1;

        printf("1  ");
        j++;
        while((c=fgetc(fptr))!=EOF)
        {
            //printf("%d  ",j);
            flg=1;
            printf("%c",c);
            if(c=='\n')

            {
                c=fgetc(fptr);
                if(c=='\n')
                {
                    printf("\n");
                    printf("%d  ",j);
                    j++;
                }
                else if(c!='\n' && c!=EOF)
                {
                    printf("%d  ",j);
                    j++;
                    printf("%c",c);

                }
                
            }
            /*else
            {
                printf("%d  ",j);
                    j++;

            }*/

            //fseek(fp, -2, SEEK_CUR);
        }
        //printf("done something\n");
        printf("\n");
        fclose(fptr);

        if(flg==0)
    {
        //printf("what\n");
        perror("file does not exist");

    }


    }
    else
    {
        perror("file does not exist");
    }
    //printf("flg is%d\n",flg);

    if(flg==0)
    {
        //printf("what\n");
        perror("file does not exist");

    }
    //printf("hi\n");



    
    
}

/*int main(int argc,char *argv[])
{
    //if()
    FILE *fptr;
    fptr=fopen(argv[1],"r");
    if(!fptr || argc!=2)
    {
        printf("error");

    }
    char c;
    while((c=fgetc(fptr))!=EOF)
    {
        printf("%c",c);
    }
    //printf("done something\n");
    fclose(fptr);

}*/