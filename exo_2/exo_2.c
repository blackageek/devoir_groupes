#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc , char *argv[]){
  pid_t pid = fork();
  if(pid < 0){

    printf("Erreur de création du processus (%d) \n", pid);
    return 1;
  }
  if(pid == 0){
   
     printf("je suis le fils (%d), mon père est (%d)\n", getpid(), getppid());
  }else{
    int status;
    pid_t pid2 = wait(&status);
    printf("Je suis le père (%d) mon fils  (%d)" , getpid(), pid);
  }

  return 0;
}
