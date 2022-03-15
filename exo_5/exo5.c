#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "md5.h"

{
   erreur ( "fichier(fc2)" );
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
MD5_2 =  MD5File ( argv [ 2 ], buf2 );


if (strcmp(MD5_1, MD5_2)==0) {
    fprintf(stderr, "copie effectuer\n MD5 %s  : %s  = %s %s MD5 \n", argv[1],MD5_1  ,MD5_2, argv[2]);

  } else {
    fprintf(stderr, "%s: different de  %s\n", MD5_1, MD5_2);

  }
return 0;
}
