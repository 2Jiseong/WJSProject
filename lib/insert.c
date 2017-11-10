#include<stdio.h>
#include<string.h>
void insert(FILE *fp,char eng[1000][100],char kor[1000][100])
{
   char buf[30];
   int idx = 0;
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
