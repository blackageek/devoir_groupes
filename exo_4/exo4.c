#include <sys/types.h>


#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


#include "md5.h"






int main(int argc , char *argv[]){
char buf[512];
if(argc != 2) {
fprintf(stderr, "Syntaxe: ./%s fichier_a_calculer\n", argv[0]);
exit(1);
}
unsigned char *MD5=NULL;
MD5= MD5File(argv[1], buf);
fprintf(stderr," Code MD5 : %s %s", MD5, argv[1]);
return 0;
}
