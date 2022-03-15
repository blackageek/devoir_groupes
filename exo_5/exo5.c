
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
int fd1, fd2, r;
char buf;
char buf1[512];
char buf2[512];
unsigned char *MD51=NULL;
unsigned char *MD52=NULL;
if(argc != 3) {
fprintf(stderr, "Syntaxe: %s fichier_source fichier_destination\n", argv[0]);
exit(1);
}

   fd1 = open(argv[1], O_RDONLY);
   if(fd1 < 0) {
   perror("fichier(fd1)");
   exit(1);
}

fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
   if(fd2 < 0) {
   perror("fichier(fd2)");
   exit(1);
}

while(1) {
     r = read(fd1, &buf, 1);
if(r < 0) {
    perror("Lecture");
    exit(1);
}
if(r == 0)
break;
r = write(fd2, &buf, 1);
if(r < 0) {
perror("Ecriture");
exit(1);
}

if(r != 1) {
fprintf(stderr, "Erreur Ecriture ");
exit(1);
}
}



close(fd1);
close(fd2);
MD51= MD5File(argv[1], buf1);
MD52= MD5File(argv[2], buf2);


if (strcmp(MD51, MD52)==0) {
    printf("copie effectuer\n MD5 %s  : %s  = %s %s MD5 \n", argv[1],MD51  ,MD52, argv[2]);

  } else {
    printf("%s: different de  %s\n", MD51, MD52);

  }
return 0;
}














