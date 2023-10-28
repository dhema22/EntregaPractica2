
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]){
    FILE *archivo;
    char *operacion=argv[1];
    if(strcmp(operacion,"crear")==0){
        char *crear=argv[2];
        char *nombre=argv[3];
        if(strcmp(crear,"d")==0){
            int directorio;
            directorio=mkdir(nombre);
        }else if(strcmp(crear,"t")==0){
            archivo=fopen(strcat(nombre,".txt"),"a");
            fclose(archivo);
        }
    } else if(strcmp(operacion,"escribir")==0){
        char ruta[1024];
        char *directorio=argv[2];
        char *nombreArchivo=argv[3];
        strcpy(ruta,directorio);
        strcat(ruta,"-");
        strcat(ruta,nombreArchivo);
        strcat(ruta,".txt");
        
        archivo=fopen(ruta,"a");
        char *texto=argv[4];
        fputs(strcat(texto,"\n"),archivo);
        fclose(archivo);
    }
    return 0;
} 