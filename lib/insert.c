#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "insert.h"

typedef struct word{
	char eng[100];
        char kor[100];
}word;

void insert(FILE *fp)
{
   FILE *fp2 = fopen("words.txt","a");
   word word[1000];
   char buf[30];
   int idx = 0;
   while(fgets(buf,sizeof(buf),fp) != NULL)
   {
      char *ptr=strtok(buf," ");
      strcpy(word[idx].eng,ptr);
      ptr = strtok(NULL," ");
      strcpy(word[idx].kor,ptr);
      idx++;
   }
   for(int i = 0;i<idx;i++)
   {
      fwrite(word[i].eng,sizeof(word[i].eng),1,fp2);
      fwrite(" ",sizeof(char),1,fp2);
      fwrite(word[i].kor,sizeof(word[i].kor),1,fp2);
   }
   fclose(fp2);
   return;
}
