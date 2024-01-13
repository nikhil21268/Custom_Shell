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
};

int (*builtin_func[]) (char **) = {

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


  char ** args=(char **)arg;
	


  char str2[]={'~','\0'};
  char str3[]={'/','\0'};
  char str4[]={'&','t','\0'};

    if (args[1] == NULL || strcmp(args[1],str2)==0) {
		chdir(getenv("HOME")); 

	} 
  

  
  else if(strcmp(args[1],str3)==0)
  {

    chdir(getenv("ROOT")); 

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


	pthread_exit(0);

}



int my_trial_cd(char **args)
{

  char str_trd[]={'&','t','\0'};
  if(args[3]!=NULL)
  {
    printf("error: too many args.. max 3 args are allowed\n");
    return 1;
  }
  if(args[2]!=NULL && strcmp(args[2],str_trd)==0)

  {

    pthread_t tid;

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, my_trial_cd_trd, args);

    pthread_join(tid, NULL);
    return 1;
    
  }
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {


    pthread_t tid;


    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, my_trial_cd_trd, args);


    pthread_join(tid, NULL);
    return 1;
    
  }
  char str2[]={'~','\0'};
  char str3[]={'/','\0'};

    if (args[1] == NULL || strcmp(args[1],str2)==0) {
		chdir(getenv("HOME")); 
		return 1;
	} 
  

  else if(strcmp(args[1],str3)==0)
  {

    int a=chdir(getenv("ROOT")); 

		return 1;
  }
  else {
    if (chdir(args[1]) != 0) {
      perror("my_trial");
    }
  }
  return 1;
}



char* remove_quotes(char* s1) {
  size_t len = strlen(s1);
  for(int i=0;i<strlen(s1);i++)

  {
    if (s1[0] == '"') 
    {
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

  printf("thread\n");

  char ** args=(char **)arg;
	


  char str2[]={'*','\0'};
    char str3[]={'-','n','\0'};


    if(args[1]==NULL)
    {
      printf("\n");
    }
    if(strcmp(args[1],str2)==0)
    {
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
 
    

    else if(strcmp(args[1],str3)==0)
    {

      int i=1;
      while(args[i+2]!=NULL)
      {
        char *s1=remove_quotes(args[i+1]);
        printf("%s ",s1);
        i++;
      }

}
  else
  {

    int i=0;
      while(args[i+2 ]!=NULL)
      {

        printf("%s ",args[i+1]);
        
        i++;
      }
      printf("\n");
  }
 

	pthread_exit(0);

}


int my_trial_echo(char **args)
{


    char str_trd[]={'&','t','\0'};

    
  if(args[2]!=NULL && strcmp(args[2],str_trd)==0)

  {
 


    pthread_t tid;


    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, my_trial_echo_trd, args);


    pthread_join(tid, NULL);
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

    pthread_create(&tid, &attr, my_trial_echo_trd, args);


    pthread_join(tid, NULL);
    return 1;

}
    char str2[]={'*','\0'};
    char str3[]={'-','n','\0'};

    if(args[1]==NULL)
    {
      printf("\n");
      return 1;
    }
    if(strcmp(args[1],str2)==0)
    {
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

    

    else if(strcmp(args[1],str3)==0)
    {

      int i=1;
      while(args[i+1]!=NULL)
      {
        char *s1=remove_quotes(args[i+1]);
        printf("%s ",s1);
        i++;
      }

}
  else
  {
    int i=0;
      while(args[i+1]!=NULL)
      {

        printf("%s ",args[i+1]);
        
        i++;
      }
      printf("\n");
  }
  return 1;   
}

void * my_trial_pwd_trd(void *arg)
{

  char ** args=(char **)arg;



  char str2[]={'-','-','h','e','l','p','\0'};
  char str3[]={'-','L','\0'};

  if(args[1]!=NULL)
  {
    if(strcmp(args[1],str3)==0)
    {
      char wd[1000];
      printf("current working directory is: %s ",getcwd(wd,sizeof(wd)));
      printf("\n");
    }

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


    char str_trd[]={'&','t','\0'};
    if(args[3]!=NULL)
  {
    printf("error: too many args.. max 3 args are allowed\n");
    return 1;
  }
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, my_trial_pwd_trd, args);

    pthread_join(tid, NULL);

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


    pthread_create(&tid, &attr, my_trial_pwd_trd, args);


    pthread_join(tid, NULL);

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

      return 1;
    }
    else
    {
      printf("incorrect format for pwd.. please try again\n");
    }

  }


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


  char ** args=(char **)arg;

  char str1[]="./lsCommand ";

  if(args[1]!=NULL && strcmp("&t",args[1])!=0)
  {
    strcat(str1,args[1]);
    system(str1);

  }
  else
  {
    system("./lsCommand");
  }

  



	pthread_exit(0);

}

int my_trial_ls(char **args)
{
   char str_trd[]={'&','t','\0'};
   if(args[3]!=NULL)
  {
    printf("error: too many args.. max 3 args are allowed\n");
    return 1;
  }
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, my_trial_ls_trd, args);

    pthread_join(tid, NULL);

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

    pthread_create(&tid, &attr, my_trial_ls_trd, args);

    pthread_join(tid, NULL);

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

        execl
        (

            "./lsCommand",
            "lsCommand",
            args[1],
            NULL

        );

    }

    wait(NULL);
    return 1;

}

void * my_trial_cat_trd(void *arg)
{

  char ** args=(char **)arg;

  char str1[]="./catCommand ";
  int i=1;
  while(args[i+1]!=NULL)
  {
    strcat(str1,args[i]);
    strcat(str1," ");
    i++;



  }
  system(str1);
  
  




	pthread_exit(0);

}

int my_trial_cat(char **args)
{
   char str_trd[]={'&','t','\0'};

  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, my_trial_cat_trd, args);


    pthread_join(tid, NULL);
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

    pthread_create(&tid, &attr, my_trial_cat_trd, args);


    pthread_join(tid, NULL);
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

        execl
        (

            "./catCommand",
            "catCommand",

            args[1],
            args[2],
            args[3],
            args[4],
            args[5],
            NULL

        );

        
    }

    wait(NULL);
    return 1;
}

void * my_trial_date_trd(void *arg)
{

  char ** args=(char **)arg;

  char str1[]="./dateCommand ";
  int i=1;
  while(args[i+1]!=NULL)
  {

    strcat(str1,args[i]);
    strcat(str1," ");
    i++;



  }
  system(str1);
  
  



	pthread_exit(0);

}

int my_trial_date(char **args)
{

   char str_trd[]={'&','t','\0'};
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;


    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, my_trial_date_trd, args);

   
    pthread_join(tid, NULL);
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

    pthread_create(&tid, &attr, my_trial_date_trd, args);


    pthread_join(tid, NULL);
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

        
        execl
        (
            "./dateCommand",
            "dateCommand",
           args[1],
           args[2],
           args[3],
           args[4],
           args[5],
           args[6],
            NULL

        );

        
    }
 
    wait(NULL);
    return 1;


}

void * my_trial_rm_trd(void *arg)
{

  char ** args=(char **)arg;

  char str1[]="./rmCommand ";
  int i=1;
  while(args[i+1]!=NULL)
  {
    
    strcat(str1,args[i]);
    strcat(str1," ");
    i++;



  }
  system(str1);
  
  



	pthread_exit(0);

}

int my_trial_rm(char **args)
{

  char str_trd[]={'&','t','\0'};
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;


    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, my_trial_rm_trd, args);

    pthread_join(tid, NULL);
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

    pthread_create(&tid, &attr, my_trial_rm_trd, args);

    pthread_join(tid, NULL);
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
        
        execl
        (
            
            "./rmCommand",
            "rmCommand",
            args[1],
            args[2],
            args[3],
            args[4],
            args[5],
            NULL

        );

        
        
    }

    wait(NULL);
    return 1;
  
}

void * my_trial_mkdir_trd(void *arg)
{

  char ** args=(char **)arg;
  
  char str1[1000000]="./mkdirCommand ";
  int i=1;
  while(args[i+1]!=NULL)
  
    strcat(str1,args[i]);
    strcat(str1," ");
    i++;



  }
  system(str1);
  
  



	pthread_exit(0);

}


int my_trial_mkdir(char **args)
{

  char str_trd[]={'&','t','\0'};
  if(args[1]!=NULL && strcmp(args[1],str_trd)==0)

  {
    pthread_t tid;

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, my_trial_mkdir_trd, args);

    pthread_join(tid, NULL);
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

    pthread_create(&tid, &attr, my_trial_mkdir_trd, args);


    pthread_join(tid, NULL);
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
        execl
        (
            "./mkdirCommand",
            "mkdirCommand",
            args[1],
            args[2],
            args[3],
            args[4],
            args[5],
            args[6],
            args[7],
            NULL

        );
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