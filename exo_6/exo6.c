

#include <sys/types.h>


#include <stdio.h>
#include <stdlib.h>

#include "md5.h"



int main(int argc , char *argv[]){
char buf[512];
int i=1;
char file[1000];
FILE *fich=NULL;
fich=fopen("MD5_1000.txt","w+");
unsigned char *MD5=NULL;

while (i <1000{
    printf("Saisie le nom du fichier (%d) \n :",i+1);
    scanf("%s",file);
    MD5= MD5File(file, buf);
    if (MD5==NULL){
    printf("Impossible de trouver le fichier (%s) \n", file);
    i=i-1;
    }
    else {
     fprintf(fich, "%s %s \n", MD5, file);
    }
    
   
    i=i+1;
}
fclose(fich);

return 0;
}
