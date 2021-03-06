#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "show.h"

typedef struct word{
    char eng[30];
    char kor[30];
    int level;
}word;

int compare(const void *A,const void *B)
{
   word *a = (word*)A;
   word *b = (word*)B;
   return (strcmp(a->eng,b->eng));
}
int compare2(const void *A,const void *B)
{
   word *a = (word*)A;
   word *b = (word*)B;
   if(a->level > b->level) {return -1;}
   else if(a->level == b->level) {return 0;}
   else	{return 1;}
}

void show(FILE *fp ,char *option)
{
   word words[1000];
   word easy[1000];
   word normal[1000];
   word hard[1000];
   word wrongwords[1000];
   char eng[50];
   char kor[50];
   int level = 0;
   int idx = 0;

   if(strcmp(option,"all") == 0)
   {
     while(feof(fp)==0)                     //파일 읽고,
     {
       fscanf(fp,"%s %s %d\n",words[idx].eng, words[idx].kor, &words[idx].level);
       idx++;
     }
     qsort(words,idx,sizeof(word),compare);  //정렬
     for(int i = 0;i<idx;i++)
     {
       printf("%s %s\n",words[i].eng,words[i].kor); //출력
     }
   }
   else if(strcmp(option,"easy") == 0)
   {
     while(feof(fp)==0)
     {
       fscanf(fp,"%s %s %d\n",eng,kor,&level);
       if(level == 1)
       {
         strcpy(easy[idx].eng,eng);
         strcpy(easy[idx].kor,kor);
         idx++;
       }
     }
     qsort(easy,idx,sizeof(word),compare);
     for(int i = 0;i<idx;i++)
     {
       printf("%s %s\n",easy[i].eng,easy[i].kor);
     }
   }
   else if(strcmp(option,"normal") == 0)
   {
     while(feof(fp)==0)
     {
       fscanf(fp,"%s %s %d\n",eng,kor,&level);
       if(level == 2)
       {
         strcpy(normal[idx].eng,eng);
         strcpy(normal[idx].kor,kor);
         idx++;
       }
     }
     qsort(normal,idx,sizeof(word),compare); 
     for(int i = 0;i<idx;i++)
     {
       printf("%s %s\n",normal[i].eng,normal[i].kor);
     }
   }
   else if(strcmp(option,"hard") == 0)
   {
     while(feof(fp)==0)
     {
       fscanf(fp,"%s %s %d\n",eng,kor,&level);
       if(level == 3)
       {
         strcpy(hard[idx].eng,eng);
         strcpy(hard[idx].kor,kor);
         idx++;
       }
     }
     qsort(hard,idx,sizeof(word),compare);
     for(int i = 0;i<idx;i++)
     {
       printf("%s %s\n",hard[i].eng,hard[i].kor);
     }
   }
   else if(strcmp(option,"wrongwords") == 0)
   {
    FILE *fp2 = fopen("wrongwords.txt","r");
    if(fp2 == NULL)
    {
       printf("틀린 단어가 없습니다.\n");
       return;
    }
    while(feof(fp2)==0)
    {
	fscanf(fp2,"%s %s %d\n",eng,kor,&level);
	strcpy(wrongwords[idx].eng,eng);
	strcpy(wrongwords[idx].kor,kor);
        wrongwords[idx].level = level;
	idx++;
    }
    qsort(wrongwords,idx,sizeof(word),compare2);
    for(int i = 0;i<idx;i++)
    {
      printf("%s %s 틀린 횟수:%d\n",wrongwords[i].eng,wrongwords[i].kor,wrongwords[i].level);
    }
   }
  else
   {
     printf("'option' is error\n");
   }
}
