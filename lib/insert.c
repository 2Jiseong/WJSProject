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
   FILE *fp2 = fopen("outputwords.txt","a");
   word word[1000];
   char buf[100];
   int idx=0;
   int level;
   //file read
   while(feof(fp) == 0)
   {
     fscanf(fp,"%s %s\n",word[idx].eng,word[idx].kor);
     idx++;
   }
   //level check
   for(int i = 0;i<idx;i++)
   {
    level = strlen(word[i].eng);
    if (level < 5)
    {
        level = 1;
    }
    else if (level >= 5 && level < 10)
    {
        level = 2;
    }
    else if (level>=10)
    {
        level = 3;
    }
    //file write
    fprintf(fp2,"%s %s %d\n",word[i].eng, word[i].kor,level);
   }
   fclose(fp2);
   return;
}
