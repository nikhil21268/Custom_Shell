#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[])
{
    //int len=strlen(argv[0]);
    //if(argv[1]!=NULL)
    //printf("ok\n");
    //if(len<1)
    /*printf("%s\n",argv[0]);
    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);*/
    
    //if(argv[])
    char str1[]={'-','p','\0'};
    char str2[]={'-','v','\0'};
    if(argv[1]!=NULL && (strcmp(argv[1],str2))==0)
    {
        int k=2;
        while(argv[k]!=NULL)

        {
            int c=mkdir(argv[k],0777);
            if(!c)
            {
                printf("mkdir: created directory '%s'\n",argv[k]);
            }
            else
            {
                printf("error\n");
            }
            //return 1;
            k++;

        }
        return 1;

    }
    /*if(argv[1]!=NULL && (strcmp(argv[1],str1))!=0)
    {
        int c=mkdir(argv[1],0777);
        if(!c)
        {
            printf("created successfuly\n");
        }
        else
        {
            printf("error\n");
        }
        return 1;

    }*/
    /*else if(argv[1]!=NULL && (strcmp(argv[1],str2))!=0)
    {
        int k=2;
        while(argv[k]!=NULL)

        {
            int c=mkdir(argv[k],0777);
            if(!c)
            {
                printf("mkdir: created directory '%s'\n",argv[k]);
            }
            else
            {
                printf("error\n");
            }
            //return 1;
            k++;

        }
        return 1;

    }*/
    
   else if(argv[1]!=NULL && strcmp(argv[1],str1)==0)
   {
    int c=mkdir(argv[2],0777);
        if(!c)
        {
            printf("created successfuly\n");
            return 1;
        }
        else
        {
            //printf("error\n");
            //printf("%s\n",argv[2]);
            char *token = strtok(argv[2], "/");
            //char *token2=strtok(argv[2], "/");
            char str2[100000]="";
            int flg=0;
            //int c=mkdir(str2,0777);
            int c=mkdir(token,0777);
            //strcat(str2,"/");
            strcat(str2,token);
            strcat(str2,"/");

            while (token != NULL)
            {


                token = strtok(NULL, "/");
                //token2 = strtok(NULL, "/");
                //printf("ok\n");
                /*if(token==NULL)
                {
                    break;
                }*/
                //printf("%s\n", token);
                //int c=mkdir(argv[2],0777);
                /*if(flg==0)
                {
                    strcat(str2,token);
                    //printf("%s\n",str2);

                    //int c=mkdir(token,0777);
                    int c=mkdir(str2,0777);
                    //token = strtok(NULL, "/");
                    flg=1;
                    continue;

                }*/
                strcat(str2,"/");
                strcat(str2,token);
                //printf("%s\n",str2);

                int c=mkdir(str2,0777);
                /*if(token2==NULL)
                {
                    break;
                }
                int c=mkdir(str2,0777);
                //token = strtok(NULL, "/");
            }


            //int c=mkdir(argv[2],0777);
            /*if(!c)
            {
                printf("created successfuly\n");
            }
            else
            {
                printf("error\n");
            }
            printf("created successfuly\n");

        }*/
   }//printf("created successfully\n");
   }}
        else if(argv[1]!=NULL && (strcmp(argv[1],str1))!=0) //(strcmp(argv[1],str2))!=0)
    {
        //printf("afasfaqf");
        int k=1;
        while(argv[k]!=NULL)
        {
            int c=mkdir(argv[k],0777);
            if(!c)
            {
                printf("created successfuly %s\n",argv[k]);
            }
            else
            {
                printf("error\n");
            }
            k++;

        }
        /*int c=mkdir(argv[1],0777);
        if(!c)
        {
            printf("created successfuly\n");
        }
        else
        {
            printf("error\n");
        }*/
        return 1;

    }

        else
        {
            //printf("error\n");
            //printf("%s\n",argv[2]);
            char *token = strtok(argv[2], "/");
            //char *token2=strtok(argv[2], "/");
            char str2[100000]="";
            //int flg=0;
            //int c=mkdir(str2,0777);
            int c=mkdir(token,0777);
            //strcat(str2,"/");
            strcat(str2,token);
            //strcat(str2,"/");
            token = strtok(NULL, "/");

            while (token != NULL)
            {
                
                //token2 = strtok(NULL, "/");
                //printf("ok\n");
                /*if(token==NULL)
                {
                    break;
                }*/
                //printf("%s\n", token);
                //int c=mkdir(argv[2],0777);
                /*if(flg==0)
                {
                    strcat(str2,token);
                    printf("%s\n",str2);

                    //int c=mkdir(token,0777);
                    int c=mkdir(str2,0777);
                    //token = strtok(NULL, "/");
                    flg=1;
                    continue;

                }*/
                strcat(str2,"/");
                strcat(str2,token);
                //printf("%s\n",str2);

                //int c=mkdir(token,0777);
                /*if(token2==NULL)
                {
                    break;
                }*/
                int c=mkdir(str2,0777);
                //token = strtok(NULL, "/");
                token = strtok(NULL, " / ");
            }


            //int c=mkdir(argv[2],0777);
            /*if(!c)
            {
                printf("created successfuly\n");
            }
            else
            {
                printf("error\n");
            }
            printf("created successfuly\n");

        }*/

        }
        return 1;



//}
    return 1;
    
}