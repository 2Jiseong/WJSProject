#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert(FILE *fp,char eng[1000][100],char kor[1000][100]);

void main(int argc,char *argv[])
{
  char eng[1000][100];
  char kor[1000][100];

  if(strcmp(argv[1],"insert") == 0)
  {
     FILE *fp = fopen(argv[2],"r");
     FILE *fp2 = fopen("newWords.txt","w");
     if(fp == NULL)
     {
         printf("File open error!");
         return;
     }

     insert(fp,fp2,eng,kor);
     fclose(fp);
     fclose(fp2);
   }
   if(strcmp(argv[1],"add") == 0)
   {

     //wj
   }

  return;
}
