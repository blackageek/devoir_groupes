#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
  
int main()
{

  
    int fd1[2];  
    int fd2[2];  
  
 
    char input_str[100];
    pid_t p;
  
    if (pipe(fd1)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }
    if (pipe(fd2)==-1)
    {
        fprintf(stderr, "Pipe Failed" );
        return 1;
    }
  
    scanf("%s", input_str);
    p = fork();
  
    if (p < 0)
    {
        fprintf(stderr, "fork Failed" );
        return 1;
    }
  
    // Parent process
    else if (p > 0)
    {
        char concat_str[100];
  
        close(fd1[0]);  
  
        
        write(fd1[1], input_str, strlen(input_str)+1);
        close(fd1[1]);
  
        
        wait(NULL);
  
        close(fd2[1]); 
  
        
        read(fd2[0], concat_str, 100);
        printf(" je suis enfant j'ais reçu : Code(%s) de mon père", concat_str);
        close(fd2[0]);
    }
  
    
    else
    {
        close(fd1[1]);  
  
        
        char concat_str[100];
        read(fd1[0], concat_str, 100);
  
        
  
  
        
        close(fd1[0]);
        close(fd2[0]);
  
        
        write(fd2[1], concat_str, strlen(concat_str)+1);
        close(fd2[1]);
  
        exit(0);
    }
}
