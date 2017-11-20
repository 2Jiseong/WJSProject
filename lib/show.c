#include<stdio.h>
#include<string.h>
#include "show.h"

typedef struct word{
    char eng[30];
    char kor[30];
    int level;
}word;

void show(FILE *fp, char *option)
{
   word words[1000];
   int idx = 0;
   if(strcmp(option,"all") == 0)
   {
     while(feof(fp)==0)
     {
       fscanf(fp,"%s %s %d\n",words[idx].eng,words[idx].kor,&words[idx].level);
       printf("%s %s\n",words[idx].eng,words[idx].kor);
       idx++;
     }
   }
   else if(strcmp(option,"easy") == 0)
   {
     while(feof(fp)==0)
     {
       fscanf(fp,"%s %s %d\n",words[idx].eng,words[idx].kor,&words[idx].level);
       if(words[idx].level == 1)
       {
         printf("%s %s\n",words[idx].eng,words[idx].kor);
       } 
       idx++;
     }
   }
   else if(strcmp(option,"normal") == 0)
   {
     while(feof(fp)==0)
     {
       fscanf(fp,"%s %s %d\n",words[idx].eng,words[idx].kor,&words[idx].level);
       if(words[idx].level == 2)
       {
         printf("%s %s\n",words[idx].eng,words[idx].kor);
       } 
       idx++;
     }
   }
   else if(strcmp(option,"hard") == 0)
   {
     while(feof(fp)==0)
     {
       fscanf(fp,"%s %s %d\n",words[idx].eng,words[idx].kor,&words[idx].level);
       if(words[idx].level == 3)
       {
         printf("%s %s\n",words[idx].eng,words[idx].kor);
       } 
       idx++;
     }
   }
   else 
   {
     printf("'option' is error\n");
   }
}
