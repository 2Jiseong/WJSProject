#include<stdio.h>
#include<string.h>
void insert(FILE *fp,char eng[10][30],char kor[10][30])
{
   char buf[30];
   int idx=0;
   while(fgets(buf,sizeof(buf),fp) != NULL)
   {
      char *ptr=strtok(buf," ");
      strcpy(eng[idx],ptr);
      ptr = strtok(NULL," ");
      strcpy(kor[idx],ptr);
      idx++;
   }

   return; 
}
