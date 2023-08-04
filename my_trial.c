#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

int my_trial_cd(char **args);
int my_trial_echo(char **args);
int my_trial_pwd(char **args);
int my_trial_ls(char **args);
int my_trial_cat(char **args);
int my_trial_date(char **args);
int my_trial_rm(char **args);
int my_trial_mkdir(char **args);


char *builtin_str[] = {
  "cd",
  "echo",
  "pwd",
  "ls",
  "cat",
  "date",
  "rm",
  "mkdir",
  "help"
  //"exit"
};

int (*builtin_func[]) (char **) = {
  //printf("called\n");
  &my_trial_cd,
  &my_trial_echo,
  &my_trial_pwd,
  &my_trial_ls,
  &my_trial_cat,
  
  &my_trial_date,
  &my_trial_rm,
  &my_trial_mkdir
  
  
};

int my_trial_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

void * my_trial_cd_trd(void *arg)
{
  //long long *limit_ptr = (long long*) arg;

  char ** args=(char **)arg;
	
  //long long limit = *limit_ptr;
  //char str2=**str1;
  /*printf("thread\n");
  printf("%s\n",args[0]);
  printf("%s\n",args[1]);*/
  //printf("%s\n",args[2]);

  char str2[]={'~','\0'};
  char str3[]={'/','\0'};
  char str4[]={'&','t','\0'};
  /*printf("%s\n",args[1]);
  printf("%s\n",str3);*/
  //char str4[]="&t";
  //if (args[1] == NULL || args[1]=="~") {
    if (args[1] == NULL || strcmp(args[1],str2)==0) {
		chdir(getenv("HOME")); 
		//return 1;
	} 
  
  //else if(args[1]=="/")
  
  else if(strcmp(args[1],str3)==0)
  {
    //printf("entered");
    //todo
    //try running on linux
    //int a=chdir(getenv("ROOT")); 
    chdir(getenv("ROOT")); 
    //printf("%d\n",a);
		//return 1;
  }
  else if(strcmp(args[1],str4)==0 )
  {
    printf("entered");
    chdir(getenv("HOME")); 

  }
  else {
    if (chdir(args[1]) != 0) {
      perror("my_trial");
    }
  }
  //return 1;

	/*for (long long i = 0; i <= limit; i++) {
		sum += i;
	}*/

	// n

	pthread_exit(0);

}

//long long sum = 0;

/*void* sum_runner(void* arg)
{
	long long *limit_ptr = (long long*) arg;
	long long limit = *limit_ptr;

	for (long long i = 0; i <= limit; i++) {
		sum += i;
	}

	// n

	pthread_exit(0);
}*/

int my_trial_cd(char **args)
{
  /*if (args[1] == NULL) {
    fprintf(stderr, "my_trial: expected argument to \"cd\"\n");
  }*/
  char str_trd[]={'&','t','\0'};
  if(args[3]!=NULL)
  {
    printf("error: too many args.. max 3 args are allowed\n");
    return 1;
  }
  //printf("%d\n",strlen(*args));
  if(args[2]!=NULL && strcmp(args[2],str_trd)==0)

  {
    /*if (argc < 2) {
		printf("Usage: %s <num>\n", argv[0]);
		exit(-1);
    }*/

    //long long limit = atoll(argv[1]);


    // Thread ID:
    pthread_t tid;

    // n
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_cd_trd, args);

    // n

    // n
    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;
    
  }
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    /*if (argc < 2) {
		printf("Usage: %s <num>\n", argv[0]);
		exit(-1);
    }*/

    //long long limit = atoll(argv[1]);


    // Thread ID:
    pthread_t tid;

    // n
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_cd_trd, args);

    // n

    // n
    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;
    
  }
  char str2[]={'~','\0'};
  char str3[]={'/','\0'};
  //if (args[1] == NULL || args[1]=="~") {
    if (args[1] == NULL || strcmp(args[1],str2)==0) {
		chdir(getenv("HOME")); 
		return 1;
	} 
  
  //else if(args[1]=="/")
  else if(strcmp(args[1],str3)==0)
  {
    /*printf("%s\n",args[1]);
    printf("%s\n",str3);*/
    //printf("entered");
    //try running on linux
    int a=chdir(getenv("ROOT")); 
    /*if(a==-1)
    {
      chdir(getenv("//"));
    }*/
    //printf("%d\n",a);
		return 1;
  }
  else {
    if (chdir(args[1]) != 0) {
      perror("my_trial");
    }
  }
  return 1;
}

/*char* remove_quotes(char* s1) {
    size_t len = strlen(s1);
    if (s1[0] == '"' && s1[len - 1] == '"') {
        s1[len - 1] = '\0';
        memmove(s1, s1 + 1, len - 1);
    }
    return s1;
}*/

char* remove_quotes(char* s1) {
  size_t len = strlen(s1);
  for(int i=0;i<strlen(s1);i++)

  {
    if (s1[0] == '"') 
    {//&& s1[strlen(s1) - 1] == '"') {
        //s1[strlen(s1) - 1] = '\0';
        return s1 + 1;
    }
    else if(s1[strlen(s1)-1]== '"')
    {
      s1[strlen(s1) - 1] = '\0';
      return s1;
    }
  }
    
    return s1;
}

void * my_trial_echo_trd(void *arg)
{
  //long long *limit_ptr = (long long*) arg;

  printf("thread\n");

  char ** args=(char **)arg;
	
  //long long limit = *limit_ptr;
  //char str2=**str1;
  /*printf("ok\n");
  printf("%s\n",args[0]);
  printf("%s\n",args[1]);
  printf("%s\n",args[2]);*/

  char str2[]={'*','\0'};
    char str3[]={'-','n','\0'};

    //if(args[1]=="*")
    //if(args[1]==str2)
    if(args[1]==NULL)
    {
      //printf("ok\n");
      printf("\n");
      //return 1;
    }
    if(strcmp(args[1],str2)==0)
    {
      //printf("enetrede here\n");
      DIR *d;
      struct dirent *dir;
      d = opendir(".");
      if (d)
      {
          while ((dir = readdir(d)) != NULL)
          {
              printf("%s ", dir->d_name);
          }
          closedir(d);
      }
      printf("\n");
    }
 
    

    //else if(args[1]=="-n")
    else if(strcmp(args[1],str3)==0)
    {
      //printf()
      //for(int i=1;i<argc;i++)
      /*int i=0;
      while(args[i+2]!=NULL)
      {
        /*printf("%s ",args[i+1]);*/
        
        /*8if(i==1)
          {
            int size=sizeof(args[i])/sizeof(args[i][0]);
            for(int j=1;j<size;j++)
            {
              printf("%c",args[i][j]);

            }
            printf(" ");
            continue;
          }
          if(i==argc-1)
          {
            int size=sizeof(args[i])/sizeof(args[i][0]);
            for(int j=0;j<size-1;j++)
            {
              printf("%c",args[i][j]);

            }
            //printf(" ");
            continue;
          }
            printf("%s ",args[i]);
          i++;

      }*/
      //printf("%s ",args[i+2]);
      /*int j=0;
      char str4[]={'"','\0'};
      while(args[i][j+1]!=NULL)
      {
        //if(strcmp(args[i][j],str4)==0)
        if(args[i][j]=='"')
        {
          args[i][j]="";
        }
        j++;
      }
      i++;*/
      
        //{
          
        //}
      //add -e option  - only 1 fucntionality
    //}
      //while(args[i+2]!=NULL)
      //{
        /*printf("%s ",args[i+1]);*/
        
        /*8if(i==1)
          {
            int size=sizeof(args[i])/sizeof(args[i][0]);
            for(int j=1;j<size;j++)
            {
              printf("%c",args[i][j]);

            }
            printf(" ");
            continue;
          }
          if(i==argc-1)
          {
            int size=sizeof(args[i])/sizeof(args[i][0]);
            for(int j=0;j<size-1;j++)
            {
              printf("%c",args[i][j]);

            }
            //printf(" ");
            continue;
          }
            printf("%s ",args[i]);
          i++;

      }*/
      //printf("%s ",args[i+2]);
      //i++;
        //{
          
        //}
      //add -e option  - only 1 fucntionality
    ///}
    //}
    //else
    //{
      //printf("%d\n",argc);
      //printf("trial\n");
      /*for(int i=0;i<argc;i++)
        {
            printf("%s ",args[i+1]);
        }
        printf("\n");*/
      /*for(int i=0;i<argc;i++)
        {
            printf("%s ",args[i+1]);
        }
        printf("\n");*/
      //remove_quotes(args[2])

      //change
      int i=1;
      while(args[i+2]!=NULL)
      {
        //args[i+1]=remove_quotes(args[2]);
        char *s1=remove_quotes(args[i+1]);
        //printf("%s ",args[i+1]);
        printf("%s ",s1);
        i++;
      }
      //printf("\n");

    //}

     

    //}
}
  else
  {
    //printf("entered\n");
    int i=0;
      while(args[i+2 ]!=NULL)
      {
        //args[i+1]=remove_quotes(args[2]);
        //char *s1=remove_quotes(args[i+1]);
        //printf("%s ",args[i+1]);
        printf("%s ",args[i+1]);
        
        i++;
      }
      printf("\n");
  }
  /*char str_trd[]={'&','t','\0'};
  if(strcmp(args[1],str_trd)==0)

  {
    printf("\n");
      //return 1;

  }*/
  //return 1;   

	pthread_exit(0);

}


int my_trial_echo(char **args)
{
  /*if (args[1] == NULL) {
    fprintf(stderr, "my_trial: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("my_trial");
    }
  }
  return 1;*/
  
  

  /*if(argc<=1)
    {
        printf("enter more args");
    }
    else
    {*/
    
    //int argc=sizeof(args)/sizeof(args[0]);
    /*printf("%s\n",args[0]);
    printf("%s\n",args[1]);
    //printf("%s\n",args[2]);
    printf("%d\n",args[1]=="*");
    char str1[]={"*",};
    printf("%d\n",strcmp(args[1],str1));*/

    char str_trd[]={'&','t','\0'};

    
  //printf("%ld\n",strlen(args));
  if(args[2]!=NULL && strcmp(args[2],str_trd)==0)

  {
    /*if (argc < 2) {
		printf("Usage: %s <num>\n", argv[0]);
		exit(-1);
    }*/

    //long long limit = atoll(argv[1]);


    // Thread ID:
    pthread_t tid;

    // n
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_echo_trd, args);

    // n

    // n
    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;
    
  }

  int j=0;
  while(args[j+1]!=NULL)

  {
    j++;
  }
  if(strcmp(args[j],str_trd)==0)
{
  pthread_t tid;

    // n
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_echo_trd, args);

    // n

    // n
    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

}
    char str2[]={'*','\0'};
    char str3[]={'-','n','\0'};

    //if(args[1]=="*")
    //if(args[1]==str2)
    if(args[1]==NULL)
    {
      //printf("ok\n");
      printf("\n");
      return 1;
    }
    if(strcmp(args[1],str2)==0)
    {
      //printf("enetrede here\n");
      DIR *d;
      struct dirent *dir;
      d = opendir(".");
      if (d)
      {
          while ((dir = readdir(d)) != NULL)
          {
              printf("%s ", dir->d_name);
          }
          closedir(d);
      }
      printf("\n");
    }

    

    //else if(args[1]=="-n")
    else if(strcmp(args[1],str3)==0)
    {
      //printf()
      //for(int i=1;i<argc;i++)
      /*int i=0;
      while(args[i+2]!=NULL)
      {
        /*printf("%s ",args[i+1]);*/
        
        /*8if(i==1)
          {
            int size=sizeof(args[i])/sizeof(args[i][0]);
            for(int j=1;j<size;j++)
            {
              printf("%c",args[i][j]);

            }
            printf(" ");
            continue;
          }
          if(i==argc-1)
          {
            int size=sizeof(args[i])/sizeof(args[i][0]);
            for(int j=0;j<size-1;j++)
            {
              printf("%c",args[i][j]);

            }
            //printf(" ");
            continue;
          }
            printf("%s ",args[i]);
          i++;

      }*/
      //printf("%s ",args[i+2]);
      /*int j=0;
      char str4[]={'"','\0'};
      while(args[i][j+1]!=NULL)
      {
        //if(strcmp(args[i][j],str4)==0)
        if(args[i][j]=='"')
        {
          args[i][j]="";
        }
        j++;
      }
      i++;*/
      
        //{
          
        //}
      //add -e option  - only 1 fucntionality
    //}
      //while(args[i+2]!=NULL)
      //{
        /*printf("%s ",args[i+1]);*/
        
        /*8if(i==1)
          {
            int size=sizeof(args[i])/sizeof(args[i][0]);
            for(int j=1;j<size;j++)
            {
              printf("%c",args[i][j]);

            }
            printf(" ");
            continue;
          }
          if(i==argc-1)
          {
            int size=sizeof(args[i])/sizeof(args[i][0]);
            for(int j=0;j<size-1;j++)
            {
              printf("%c",args[i][j]);

            }
            //printf(" ");
            continue;
          }
            printf("%s ",args[i]);
          i++;

      }*/
      //printf("%s ",args[i+2]);
      //i++;
        //{
          
        //}
      //add -e option  - only 1 fucntionality
    ///}
    //}
    //else
    //{
      //printf("%d\n",argc);
      //printf("trial\n");
      /*for(int i=0;i<argc;i++)
        {
            printf("%s ",args[i+1]);
        }
        printf("\n");*/
      /*for(int i=0;i<argc;i++)
        {
            printf("%s ",args[i+1]);
        }
        printf("\n");*/
      //remove_quotes(args[2])

      //change
      int i=1;
      while(args[i+1]!=NULL)
      {
        //args[i+1]=remove_quotes(args[2]);
        char *s1=remove_quotes(args[i+1]);
        //printf("%s ",args[i+1]);
        printf("%s ",s1);
        i++;
      }
      //printf("\n");

    //}

     

    //}
}
  else
  {
    //printf("entered\n");
    int i=0;
      while(args[i+1]!=NULL)
      {
        //args[i+1]=remove_quotes(args[2]);
        //char *s1=remove_quotes(args[i+1]);
        //printf("%s ",args[i+1]);
        printf("%s ",args[i+1]);
        
        i++;
      }
      printf("\n");
  }
  return 1;   
}

void * my_trial_pwd_trd(void *arg)
{
  //long long *limit_ptr = (long long*) arg;

  char ** args=(char **)arg;

  //printf("thread\n");
	
  //long long limit = *limit_ptr;
  //char str2=**str1;
  /*printf("ok\n");
  printf("%s\n",args[0]);
  printf("%s\n",args[1]);
  printf("%s\n",args[2]);

  char str2[]={'~','\0'};
  char str3[]={'/','\0'};
  //if (args[1] == NULL || args[1]=="~") {
    if (args[1] == NULL || strcmp(args[1],str2)==0) {
		chdir(getenv("HOME")); 
		//return 1;
	} 
  
  //else if(args[1]=="/")
  else if(strcmp(args[1],str3)==0)
  {
    //printf("entered");
    //try running on linux
    int a=chdir(getenv("ROOT")); 
    printf("%d\n",a);
		//return 1;
  }
  else {
    if (chdir(args[1]) != 0) {
      perror("my_trial");
    }
  }*/
  //return 1;

	/*for (long long i = 0; i <= limit; i++) {
		sum += i;
	}*/

	// n

  /* char str_trd[]={'&','t','\0'};
  //printf("%d\n",strlen(*args));
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;

    // n
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_pwd_trd, args);

    // n

    // n
    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    //return 1;

  }*/

  char str2[]={'-','-','h','e','l','p','\0'};
  char str3[]={'-','L','\0'};

  if(args[1]!=NULL)
  {
    if(strcmp(args[1],str3)==0)
    {
      char wd[1000];
      printf("current working directory is: %s ",getcwd(wd,sizeof(wd)));
      printf("\n");
      //return 1;
    }

    //if(args[1]=="--help")
    else if(strcmp(args[1],str2)==0)

    {
      printf("pwd: pwd [-LP]\n");
      printf("  Print the name of the current working directory.\n");
      printf("\n");
      printf("  Options:\n");
      printf("  -L	print the value of $PWD if it names the current working directory\n");
      printf("  -P	print the physical directory, without any symbolic links\n");
      printf("\n");
      printf("  By default, `pwd' behaves as if `-L' were specified.\n");
      printf("\n");
      printf("Exit Status: Returns 0 unless an invalid option is given or the current directory cannot be read.\n");
      /*printf("");
      printf("");*/
      //return 1;
    }

    else
  {
    char wd[1000];
    printf("current working directory is: %s ",getcwd(wd,sizeof(wd)));
    printf("\n");
    

  }

	pthread_exit(0);

}
}


int my_trial_pwd(char **args)
{
  /*if (args[1] == NULL) {
    fprintf(stderr, "my_trial: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("my_trial");
    }
  }*/

    char str_trd[]={'&','t','\0'};
    if(args[3]!=NULL)
  {
    printf("error: too many args.. max 3 args are allowed\n");
    return 1;
  }
  //printf("%d\n",strlen(*args));
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;

    // n
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_pwd_trd, args);

    // n

    // n
    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

  }
  int j=0;
  while(args[j+1]!=NULL)

  {
    j++;
  }
  if(strcmp(args[j],str_trd)==0)
{
  pthread_t tid;

    // n
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_pwd_trd, args);

    // n

    // n
    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

}

  char str2[]={'-','-','h','e','l','p','\0'};
  char str3[]={'-','L','\0'};

  if(args[1]!=NULL)
  {
    if(strcmp(args[1],str3)==0)
    {
      char wd[1000];
      printf("current working directory is: %s ",getcwd(wd,sizeof(wd)));
      printf("\n");
      return 1;
    }

    //if(args[1]=="--help")
    else if(strcmp(args[1],str2)==0)

    {
      printf("pwd: pwd [-LP]\n");
      printf("  Print the name of the current working directory.\n");
      printf("\n");
      printf("  Options:\n");
      printf("  -L	print the value of $PWD if it names the current working directory\n");
      printf("  -P	print the physical directory, without any symbolic links\n");
      printf("\n");
      printf("  By default, `pwd' behaves as if `-L' were specified.\n");
      printf("\n");
      printf("Exit Status: Returns 0 unless an invalid option is given or the current directory cannot be read.\n");
      /*printf("");
      printf("");*/
      return 1;
    }
    else
    {
      printf("incorrect format for pwd.. please try again\n");
    }

  }

  //if(args[1]=="-L")
  else
  {
    char wd[1000];
    printf("current working directory is: %s ",getcwd(wd,sizeof(wd)));
    printf("\n");
    

  }
  return 1;
  
}

void * my_trial_ls_trd(void *arg)
{
  //long long *limit_ptr = (long long*) arg;

  char ** args=(char **)arg;
  //printf("therad\n");
	
  //long long limit = *limit_ptr;
  //char str2=**str1;
  /*printf("ok\n");
  printf("%s\n",args[0]);
  printf("%s\n",args[1]);
  printf("%s\n",args[2]);

  char str2[]={'~','\0'};
  char str3[]={'/','\0'};
  //if (args[1] == NULL || args[1]=="~") {
    if (args[1] == NULL || strcmp(args[1],str2)==0) {
		chdir(getenv("HOME")); 
		//return 1;
	} 
  
  //else if(args[1]=="/")
  else if(strcmp(args[1],str3)==0)
  {
    //printf("entered");
    //try running on linux
    int a=chdir(getenv("ROOT")); 
    printf("%d\n",a);
		//return 1;
  }
  else {
    if (chdir(args[1]) != 0) {
      perror("my_trial");
    }
  }
  //return 1;

	/*for (long long i = 0; i <= limit; i++) {
		sum += i;
	}*/

	// n

  //system(args[1]);
  char str1[]="./ls_trial_2 ";

  if(args[1]!=NULL && strcmp("&t",args[1])!=0)
  {
    strcat(str1,args[1]);
    system(str1);

  }
  else
  {
    system("./ls_trial_2");
  }

  



	pthread_exit(0);

}

int my_trial_ls(char **args)
{
   char str_trd[]={'&','t','\0'};
  //printf("%d\n",strlen(*args));
   if(args[3]!=NULL)
  {
    printf("error: too many args.. max 3 args are allowed\n");
    return 1;
  }
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;

    // n
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_ls_trd, args);

    // n

    // n
    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

  }
  int j=0;
  while(args[j+1]!=NULL)

  {
    j++;
  }
  if(strcmp(args[j],str_trd)==0)
{
  pthread_t tid;

    // n
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_ls_trd, args);

    // n

    // n
    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

}

  pid_t pid=fork();
    if(pid<0)

    {
        perror("fork failed");
        exit(1);
    }
    else if(pid==0)
    {
        //printf("entered\n");
        //char *args[]=
        /*execl
        (
            "c/Users/suris/Desktop/x86_Practice/A1_backup/cat/cat_trial_yt",
            "c/Users/suris/Desktop/x86_Practice/A1_backup/cat/cat_trial_yt",
            "hi.txt",
            NULL

        );*/
        execl
        (
            /*"./cat_trial_yt",
            "cat_trial_yt",
            "hi.txt",
            NULL*/
            "./ls_trial_2",
            "ls_trial_2",
            //"hi.txt",
            args[1],
            NULL

        );

        //printf("entered 2s\n");
        //{
            
        //};
        
    }
    //printf("calling\n");
    //printf("hello..\n");
    wait(NULL);
    return 1;

}

void * my_trial_cat_trd(void *arg)
{
  //long long *limit_ptr = (long long*) arg;

  char ** args=(char **)arg;
  //printf("therad\n");
	
  //long long limit = *limit_ptr;
  //char str2=**str1;
  /*printf("ok\n");
  printf("%s\n",args[0]);
  printf("%s\n",args[1]);
  printf("%s\n",args[2]);

  char str2[]={'~','\0'};
  char str3[]={'/','\0'};
  //if (args[1] == NULL || args[1]=="~") {
    if (args[1] == NULL || strcmp(args[1],str2)==0) {
		chdir(getenv("HOME")); 
		//return 1;
	} 
  
  //else if(args[1]=="/")
  else if(strcmp(args[1],str3)==0)
  {
    //printf("entered");
    //try running on linux
    int a=chdir(getenv("ROOT")); 
    printf("%d\n",a);
		//return 1;
  }
  else {
    if (chdir(args[1]) != 0) {
      perror("my_trial");
    }
  }
  //return 1;

	/*for (long long i = 0; i <= limit; i++) {
		sum += i;
	}*/

	// n

  //system(args[1]);
  /*char str1[]="./cat_trial_copy ";
  if(args[1]!=NULL && strcmp("&t",args[1])!=0)
  {
    strcat(str1,args[1]);
    system(str1);

  }*/
  char str1[]="./cat_trial_copy ";
  int i=1;
  while(args[i+1]!=NULL)
  {
    //if(args[1]!=NULL && strcmp("&t",args[1])!=0)
  //{
    strcat(str1,args[i]);
    strcat(str1," ");
    //system(str1);
    i++;

  //}


  }
  //printf("%s\n",str1);
  system(str1);
  
  
  //system("./cat_trial_copy");



	pthread_exit(0);

}

int my_trial_cat(char **args)
{
   char str_trd[]={'&','t','\0'};
  //printf("%d\n",strlen(*args));
  /*if(args[3]!=NULL)
  {
    printf("error: too many args.. max 3 args are allowed\n");
    return 1;
  }*/
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;

    // n
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_cat_trd, args);

    // n

    // n
    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

  }

  int j=0;
  while(args[j+1]!=NULL)

  {
    j++;
  }
  if(strcmp(args[j],str_trd)==0)
{
  pthread_t tid;

    // n
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_cat_trd, args);

    // n

    // n
    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

}

  pid_t pid=fork();
    if(pid<0)

    {
        perror("fork failed");
        exit(1);
    }
    else if(pid==0)
    {
        //printf("entered\n");
        //char *args[]=
        /*execl
        (
            "c/Users/suris/Desktop/x86_Practice/A1_backup/cat/cat_trial_yt",
            "c/Users/suris/Desktop/x86_Practice/A1_backup/cat/cat_trial_yt",
            "hi.txt",
            NULL

        );*/
        //char str1[]=(char *)args[1];
        /*char str1[]="";
        //strcat(str1," ");
        int i=1;
        //while(args[i+1]!=NULL)
        while(args[i]!=NULL)
        {
          //if(args[1]!=NULL && strcmp("&t",args[1])!=0)
        //{
          strcat(str1,args[i]);
          strcat(str1," ");
          //system(str1);
          i++;
        }*/
        //printf("%s\n",str1); 
        execl
        (
            /*"./cat_trial_yt",
            "cat_trial_yt",
            "hi.txt",
            NULL*/
            "./cat_trial_copy",
            "cat_trial_copy",
            //"hi_copy.txt",
            //str1,
            args[1],
            args[2],
            args[3],
            args[4],
            args[5],
            NULL

        );

        //printf("entered 2s\n");
        //{
            
        //};
        
    }
    /*printf("calling\n");
    printf("hello..\n");*/
    wait(NULL);
    return 1;
}

void * my_trial_date_trd(void *arg)
{
  //long long *limit_ptr = (long long*) arg;

  char ** args=(char **)arg;
  //printf("therad\n");
	
  //long long limit = *limit_ptr;
  //char str2=**str1;
  /*printf("ok\n");
  printf("%s\n",args[0]);
  printf("%s\n",args[1]);
  printf("%s\n",args[2]);

  char str2[]={'~','\0'};
  char str3[]={'/','\0'};
  //if (args[1] == NULL || args[1]=="~") {
    if (args[1] == NULL || strcmp(args[1],str2)==0) {
		chdir(getenv("HOME")); 
		//return 1;
	} 
  
  //else if(args[1]=="/")
  else if(strcmp(args[1],str3)==0)
  {
    //printf("entered");
    //try running on linux
    int a=chdir(getenv("ROOT")); 
    printf("%d\n",a);
		//return 1;
  }
  else {
    if (chdir(args[1]) != 0) {
      perror("my_trial");
    }
  }
  //return 1;

	/*for (long long i = 0; i <= limit; i++) {
		sum += i;
	}*/

	// n

  //system(args[1]);
  /*char str1[]="./cat_trial_copy ";
  if(args[1]!=NULL && strcmp("&t",args[1])!=0)
  {
    strcat(str1,args[1]);
    system(str1);

  }*/
  char str1[]="./date_copy ";
  int i=1;
  while(args[i+1]!=NULL)
  {
    //if(args[1]!=NULL && strcmp("&t",args[1])!=0)
  //{
    strcat(str1,args[i]);
    strcat(str1," ");
    //system(str1);
    i++;

  //}


  }
  //printf("%s\n",str1);
  system(str1);
  
  
  //system("./cat_trial_copy");



	pthread_exit(0);

}

int my_trial_date(char **args)
{

   char str_trd[]={'&','t','\0'};
  //printf("%d\n",strlen(*args));
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;


    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_date_trd, args);

   
    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

  }

  int j=0;
  while(args[j+1]!=NULL)

  {
    j++;
  }
  if(strcmp(args[j],str_trd)==0)
{
  pthread_t tid;

 
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_date_trd, args);


    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

}

  pid_t pid=fork();
    if(pid<0)

    {
        perror("fork failed");
        exit(1);
    }
    else if(pid==0)
    {
        //printf("entered\n");
        //char *args[]=
        /*execl
        (
            "c/Users/suris/Desktop/x86_Practice/A1_backup/cat/cat_trial_yt",
            "c/Users/suris/Desktop/x86_Practice/A1_backup/cat/cat_trial_yt",
            "hi.txt",
            NULL

        );*/
        
        execl
        (
            /*"./cat_trial_yt",
            "cat_trial_yt",
            "hi.txt",
            NULL*/
            "./date_copy",
            "date_copy",
           // "hi_copy.txt",
           args[1],
           args[2],
           args[3],
           args[4],
           args[5],
           args[6],
            NULL

        );

        //printf("entered 2s\n");
        //{
            
        //};s
        
    }
    /*printf("calling\n");
    printf("hello..\n");*/
    wait(NULL);
    return 1;

  /*char* time_now;                                                               
  time_t t = time(NULL);                                                        
  time_now = ctime(&t);                                                         
                                                                                
  printf("date and time now: %s", time_now);

  //for utc time
  time_t tmi;
  struct tm* utcTime;

  time(&tmi);
  utcTime = gmtime(&tmi);

  printf("UTC Time: %2d:%02d:%02d\n", (utcTime->tm_hour) % 24, utcTime->tm_min, utcTime->tm_sec);*/
  
}

void * my_trial_rm_trd(void *arg)
{
  //long long *limit_ptr = (long long*) arg;

  char ** args=(char **)arg;
  //printf("therad\n");
	
  //long long limit = *limit_ptr;
  //char str2=**str1;
  /*printf("ok\n");
  printf("%s\n",args[0]);
  printf("%s\n",args[1]);
  printf("%s\n",args[2]);

  char str2[]={'~','\0'};
  char str3[]={'/','\0'};
  //if (args[1] == NULL || args[1]=="~") {
    if (args[1] == NULL || strcmp(args[1],str2)==0) {
		chdir(getenv("HOME")); 
		//return 1;
	} 
  
  //else if(args[1]=="/")
  else if(strcmp(args[1],str3)==0)
  {
    //printf("entered");
    //try running on linux
    int a=chdir(getenv("ROOT")); 
    printf("%d\n",a);
		//return 1;
  }
  else {
    if (chdir(args[1]) != 0) {
      perror("my_trial");
    }
  }
  //return 1;

	/*for (long long i = 0; i <= limit; i++) {
		sum += i;
	}*/


  //system(args[1]);
  /*char str1[]="./cat_trial_copy ";
  if(args[1]!=NULL && strcmp("&t",args[1])!=0)
  {
    strcat(str1,args[1]);
    system(str1);

  }*/
  char str1[]="./rm_copy ";
  int i=1;
  while(args[i+1]!=NULL)
  {
    //if(args[1]!=NULL && strcmp("&t",args[1])!=0)
  //{
    strcat(str1,args[i]);
    strcat(str1," ");
    //system(str1);
    i++;

  //}


  }
  //printf("%s\n",str1);
  system(str1);
  
  
  //system("./cat_trial_copy");



	pthread_exit(0);

}

int my_trial_rm(char **args)
{

  char str_trd[]={'&','t','\0'};
  //printf("%d\n",strlen(*args));
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;


    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_rm_trd, args);

    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

  }

  int j=0;
  while(args[j+1]!=NULL)

  {
    j++;
  }
  if(strcmp(args[j],str_trd)==0)
{
  pthread_t tid;


    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_rm_trd, args);

    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

}
  pid_t pid=fork();
    if(pid<0)

    {
        perror("fork failed");
        exit(1);
    }
    else if(pid==0)
    {
        //printf("entered\n");
        //char *args[]=
        /*execl
        (
            "c/Users/suris/Desktop/x86_Practice/A1_backup/cat/cat_trial_yt",
            "c/Users/suris/Desktop/x86_Practice/A1_backup/cat/cat_trial_yt",
            "hi.txt",
            NULL

        );*/
        execl
        (
            /*"./cat_trial_yt",
            "cat_trial_yt",
            "hi.txt",
            NULL*/
            "./rm_copy",
            "rm_copy",
            args[1],
            args[2],
            args[3],
            args[4],
            args[5],
            //"hi.txt",
            NULL

        );

        //printf("entered 2s\n");
        //{
            
        //};
        
    }
    //printf("calling\n");
    //printf("hello..\n");
    wait(NULL);
    return 1;
  
}

void * my_trial_mkdir_trd(void *arg)
{
  //long long *limit_ptr = (long long*) arg;

  char ** args=(char **)arg;
  //printf("therad\n");
	
  //long long limit = *limit_ptr;
  //char str2=**str1;
  /*printf("ok\n");
  printf("%s\n",args[0]);
  printf("%s\n",args[1]);
  printf("%s\n",args[2]);

  char str2[]={'~','\0'};
  char str3[]={'/','\0'};
  //if (args[1] == NULL || args[1]=="~") {
    if (args[1] == NULL || strcmp(args[1],str2)==0) {
		chdir(getenv("HOME")); 
		//return 1;
	} 
  
  //else if(args[1]=="/")
  else if(strcmp(args[1],str3)==0)
  {
    //printf("entered");
    //try running on linux
    int a=chdir(getenv("ROOT")); 
    printf("%d\n",a);
		//return 1;
  }
  else {
    if (chdir(args[1]) != 0) {
      perror("my_trial");
    }
  }
  //return 1;

	/*for (long long i = 0; i <= limit; i++) {
		sum += i;
	}*/

	// n

  //system(args[1]);
  /*char str1[]="./cat_trial_copy ";
  if(args[1]!=NULL && strcmp("&t",args[1])!=0)
  {
    strcat(str1,args[1]);
    system(str1);

  }*/
  char str1[1000000]="./mkdir_copy ";
  int i=1;
  while(args[i+1]!=NULL)
  {
    //if(args[1]!=NULL && strcmp("&t",args[1])!=0)
  //{
    strcat(str1,args[i]);
    strcat(str1," ");
    //system(str1);
    i++;

  //}


  }
 // printf("%s\n",str1);
  system(str1);
  
  
  //system("./cat_trial_copy");



	pthread_exit(0);

}


int my_trial_mkdir(char **args)
{
  /*printf("ok1\n");
  printf("ok1\n");
  printf("ok1\n");
  printf("ok1\n");
  printf("ok1\n");
  printf("ok1\n");*/
  //return 1;
  char str_trd[]={'&','t','\0'};
  //printf("%d\n",strlen(*args));
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_mkdir_trd, args);

    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

  }

  int j=0;
  while(args[j+1]!=NULL)

  {
    j++;
  }
  if(strcmp(args[j],str_trd)==0)
{
  pthread_t tid;

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    //pthread_create(&tid, &attr, sum_runner, &limit);
    pthread_create(&tid, &attr, my_trial_mkdir_trd, args);


    pthread_join(tid, NULL);
    //printf("Sum is %lld\n", sum);
    return 1;

}
  pid_t pid=fork();
    if(pid<0)

    {
        perror("fork failed");
        exit(1);
    }
    else if(pid==0)
    {
        //printf("entered\n");
        //char *args[]=
        /*execl
        (
            "c/Users/suris/Desktop/x86_Practice/A1_backup/cat/cat_trial_yt",
            "c/Users/suris/Desktop/x86_Practice/A1_backup/cat/cat_trial_yt",
            "hi.txt",
            NULL

        );*/
        //printf("ok\n");
        //printf("%s\n",args[1]);
        execl
        (
            /*"./cat_trial_yt",
            "cat_trial_yt",
            "hi.txt",
            NULL*/
            "./mkdir_copy",
            "mkdir_copy",
            //"hi.txt",
            args[1],
            args[2],
            args[3],
            args[4],
            args[5],
            args[6],
            args[7],
            NULL

        );

        //printf("entered 2s\n");
        //{
            
        //};
        
    }
    /*printf("calling\n");
    printf("hello..\n");*/
    wait(NULL);
    return 1;
  
}


int my_trial_launch(char **args)
{
  pid_t pid, wpid;
  int status;


  pid = fork();
  if (pid == 0) {

    if (execvp(args[0], args) == -1) {
      perror("my_trial");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {

    perror("my_trial");
  } else {

    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int my_trial_execute(char **args)
{
  int i;

  if (args[0] == NULL) {

    return 1;
  }

  for (i = 0; i < my_trial_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      //printf("ret somehting\n");
      /*if(i==7)
      {
        i--;
      }*/
      return (*builtin_func[i])(args);
    }
  }


  return my_trial_launch(args);
}


#define MY_TRIAL_TOK_BUFSIZE 64
#define MY_TRIAL_TOK_DELIM " \t\r\n\a"
char **my_trial_split_line(char *line)
{
  int bufsize = MY_TRIAL_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token;

  if (!tokens) {
    fprintf(stderr, "my_trial: allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, MY_TRIAL_TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += MY_TRIAL_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
        fprintf(stderr, "my_trial: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }

    token = strtok(NULL, MY_TRIAL_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}


#define MY_TRIAL_RL_BUFSIZE 1024
char *my_trial_read_line(void)
{
  int bufsize = MY_TRIAL_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "my_trial: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {

    c = getchar();

    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;


    if (position >= bufsize) {
      bufsize += MY_TRIAL_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "my_trial: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}

void my_trial_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = my_trial_read_line();
    args = my_trial_split_line(line);
    status = my_trial_execute(args);

    free(line);
    free(args);
  } while (status);
}

int main(int argc, char **argv)
{
  
  my_trial_loop();

  return EXIT_SUCCESS;
}