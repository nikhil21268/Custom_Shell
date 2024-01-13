

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/*#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <ftw.h>
#include <unistd.h>

int unlink_cb(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
    int rv = remove(fpath);

    if (rv)
        perror(fpath);

    return rv;
}

int rmrf(char *path)
{
    return nftw(path, unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
}*/

int main(int argc,char *argv[])
{
    //char dirName[16]=argv[1];
    int ret = 0;

    /*printf("Enter directory name: ");
    scanf("%s", dirName);*/
    //irName=argv[1];

    /*ret = rmdir(dirName);

    if (ret == 0)
        printf("Given empty directory removed successfully\n");
    else
        printf("Unable to remove directory %s\n", dirName);

    return 0;*/
    //printf("%s\n",argv[1]);
    char str1[]={'-','v','\0'};
    char str2[]={'-','i','\0'};
    //if((strcmp(argv[1],str1))==0) //&& argv[2]!=NULL)
    if((strcmp(argv[1],str1))!=0 && (strcmp(argv[1],str2))!=0) 
    {
        //printf("%s\n",argv[2]);
        //ret = rmdir(argv[2]);
        ret = rmdir(argv[1]);

        if (ret == 0)
            printf("Given empty directory removed successfully\n");
        else
            printf("Unable to remove directory %s\n", argv[2]);

        return 1;


    }
    else
    {
        char str2[]={'-','i','\0'};

        if((strcmp(argv[1],str2))==0)
        {
            printf("rm: remove regular file '%s'? ",argv[2]);
            char c='n';
            scanf("%c",&c);
            if(c=='y')

            {
                if(strchr(argv[2], '.') != NULL)
                {
                    if (remove(argv[2]) == 0)
                    {
                        printf("Deleted successfully\n");

                    }
                    
                    else
                        printf("Unable to delete the file\n");
                    
                    return 1;
                    
                }

            }
            else
            {
                return 1;
            }

        }
        //else if(strchr(argv[1], '.') != NULL)
        else if((strcmp(argv[1],str1))==0)
        {
            //if(strchr(argv[1], '.') != NULL)
            if(argv[2]!=NULL) //&& strchr(argv[2], '.') != NULL)
            {
                //int k=1;
                char str7[]={'&','t','\0'};
                int k=2;
                while(argv[k]!=NULL && strcmp(argv[k],str7)!=0)
                {
                    if (remove(argv[k]) == 0)
                    //chdir(argv[k]);
                    
                    //if (rmdir(argv[k]) == 0)
                {
                    printf("removed: '%s'\n",argv[k]);

                }
                else
                {
                    printf("Unable to delete the file\n");

                }
                k++;
                //k++;
                    


                }



            /*if (remove(argv[1]) == 0)
            {
                printf("Deleted successfully\n");

            }*/
            
            /*else
                printf("Unable to delete the file\n");
            
            return 1;*/
                

            }

            /*int k=1;
            while(argv[k]!=NULL)
            {
                if (remove(argv[k]) == 0)
            {
                printf("Deleted successfully\n");

            }
            else
            {
                printf("Unable to delete the file\n");

            }
            k++;
                


            }*/

            /*if (remove(argv[1]) == 0)
            {
                printf("Deleted successfully\n");

            }*/
            
            /*else
                printf("Unable to delete the file\n");
            
            return 1;*/
            
        }
        else

        {
            printf("cannot remove a directory without using -r option\n");
            return 1;

        }
        
    }
    
}