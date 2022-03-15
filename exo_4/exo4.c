#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "md5.h"





int main(int argc , char *argv[]){
char data[512];
if(argc != 2) {
fprintf(stderr, "Syntaxe: %s fichier\n", argv[0]);
exit(1);
}
unsigned char *md5=NULL;
md5= MD5File(argv[1], data);
printf(" le code md5 est %s %s", md5, argv[1]);
return 0;
}
