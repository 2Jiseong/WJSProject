#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert(FILE *fp);
void addToWord(char *eng,char *kor);

void main(int argc,char *argv[])
{

   if(strcmp(argv[1],"insert") == 0)
   {
     FILE *fp = fopen(argv[2],"r");
     if(fp == NULL)
     {
         printf("File open error!");
         return;
     }

     insert(fp);
     fclose(fp);
   }
   if(strcmp(argv[1],"add") == 0)
   {
     addToWord(argv[2],argv[3]);
   }
   if(strcmp(argv[1],"del") == 0)
   {
     //del
   }
   if(strcmp(argv[1],"show") == 0)
   {
      if(strcmp(argv[2],"easy")        //1
      else if(strcmp(argv[2],"normal") //2
      else if(strcmp(argv[2],"hard")   //3
      else if(strcmp(argv[2],"wrong")  // after testing, show wrong word
      else
      {
      //error
      } 
   }
   if(strcmp(argv[1],"test")==0)
   {
      //test
   }
   
  return;
}


