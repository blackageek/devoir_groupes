

#include <sys/types.h>


#include <stdio.h>
#include <stdlib.h>

#include "md5.h"



int main(int argc , char *argv[]){
char data[512];
int i=1;
char file[1000];
FILE *resultat=NULL;
resultat=fopen("MD5_1000.txt","w+");
unsigned char *MD5=NULL;

while (i <1000{
    printf("saisie le nom du fichier (%d) :",i+1);
    scanf("%s",file);
    MD5= MD5File(file, data);
    if (MD5==NULL){
    printf("Impossible de trouver fichier (%s) \n", file);
    i=i-1;
    }
    else {
     fprintf(resultat, "%s %s \n", MD5, file);
    }
    
   
    i=i+1;
}
fclose(resultat);

return 0;
}
