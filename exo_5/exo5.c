#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "md5.h"


int main(int argc, char **argv)
{
int fd1, fd2, rc;
char buf;
char buf1[512];
char buf2[512];
unsigned char *MD5_1=NULL;
unsigned char *MD5_2=NULL;
if(argc != 3) {
fprintf(stderr, "Syntaxe: %s fichier_source fichier_destination\n", argv[0]);
exit(1);
}

   fd1 = open(argv[1], O_RDONLY);
   if(fd1 < 0) {
   perror("fichier(fc1)");
   exit(1);
}

fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
   if(fd2 < 0) {
   perror("fichier(fc2)");
   exit(1);
}

while(1) {
     rc = read(fd1, &buf, 1);
if(rc < 0) {
    perror("lecture");
    exit(1);
}
if(rc == 0)
break;
rc = write(fd2, &buf, 1);
if(rc < 0) {
perror("ecriture");
exit(1);
}

if(rc != 1) {
fprintf(stderr, "Erreur Ecriture ");
exit(1);
}
}



close(fd1);
close(fd2);
MD5_1= MD5File(argv[1], buf1);
MD5_2= MD5File(argv[2], buf2);


if (strcmp(MD5_1, MD5_2)==0) {
    fprintf(stderr, "copie effectuer\n MD5 %s  : %s  = %s %s MD5 \n", argv[1],MD5_1  ,MD5_2, argv[2]);

  } else {
    fprintf(stderr, "%s: different de  %s\n", MD5_1, MD5_2);

  }
return 0;
}
