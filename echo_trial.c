#include <stdio.h>
int main(int argc,char *argv)
{
    if(argc<=1)
    {
        printf("enter more args");
    }
    else
    {

        for(int i=1;i<argc;i++)
        {
            printf("%s ",argv[i]);
        }

    }
    
}