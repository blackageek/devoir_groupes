/* md5hl.c
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <phk@login.dkuug.dk> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 *
 * $Id: md5hl.c.html,v 1.2 2009-06-26 16:35:53 wagner Exp $
 *
 */

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "md5.h"



char * MD5File ( char *filename, char *buf)
{
    unsigned char c[BUFSIZ];
    int i;
    FILE *inFile = fopen (filename, "rb");
    MD5_CTX mdContext;
    int bytes;
    unsigned char data[1024];
    unsigned char *dat=NULL;
    unsigned char digest[16];
    static const char hex[]="0123456789abcdef";
    if (!buf)
        buf = malloc(33);

    if (inFile == NULL) {
        printf ("%s fichier non ouvert.\n", filename);
        return 0;
    }

    MD5Init (&mdContext);
    while ((bytes = fread (data, 1, 1024, inFile)) != 0)
        MD5Update (&mdContext, data, bytes);
    MD5Final (digest,&mdContext);

    for (i=0;i<16;i++) {
	buf[i+i] = hex[digest[i] >> 4];
	buf[i+i+1] = hex[digest[i] & 0x0f];
    }
    buf[i+i] = '\0';

    fclose (inFile);

    return buf;
}

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
