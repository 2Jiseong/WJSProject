#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert(FILE *fp);
void addToWord(char *eng,char *kor);
void show(FILE *fp,char *command);
void delToWord(char *eng);
void test(FILE *fp,FILE *fp2,char *command);
void help();

void main(int argc,char *argv[])
{

   if(strcmp(argv[1],"insert") == 0)
   {
     FILE *fp = fopen(argv[2],"r");
     if(fp == NULL)
     {
         printf("File open error!\n");
         return;
     }
     insert(fp);
     fclose(fp);
   }
   if(strcmp(argv[1],"add") == 0)
   {
     addToWord(argv[2],argv[3]);
   }
   if(strcmp(argv[1],"delete") == 0)
   {
     delToWord(argv[2]);
   }
   if(strcmp(argv[1],"show") == 0)
   {
     FILE *fp = fopen("outputwords.txt","r");
     if(fp == NULL)
     {
         printf("File open error!\n");
         return;
     }
     show(fp,argv[2]);
     fclose(fp);
   }
   if(strcmp(argv[1],"test")==0)
   {
      FILE *fp = fopen("outputwords.txt","r");
      FILE *fp2 = fopen("wrongwords.txt","w+");
      if(fp == NULL)
      {
         printf("File open error!\n");
      }
      test(fp,fp2,argv[2]);
      fclose(fp);
      fclose(fp2);
   }
   if(strcmp(argv[1],"help")==0)
   {
     help();
   }
   
  return;
}


