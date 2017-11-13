#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert(FILE *fp,FILE *fp2);

void main(int argc,char *argv[])
{

  if(strcmp(argv[1],"insert") == 0)
  {
     FILE *fp = fopen(argv[2],"r");
     FILE *fp2 = fopen("words.txt","w");
     if(fp == NULL || fp2 == NULL)
     {
         printf("File open error!");
         return;
     }

     insert(fp,fp2);
     fclose(fp);
     fclose(fp2);
   }

  return;
}
