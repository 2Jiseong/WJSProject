#include <stdio.h>
#include <string.h>
#include "del.h"
typedef struct word{
	char eng[30];
	char kor[30];
	int level;
}word;
void delToWord(char *eng)
{
        word words[100];
        int delIdx = 0;
        int idx = 0;

        FILE *fp = fopen("outputwords.txt","r");
        while (feof(fp)==0)
        {
             fscanf(fp, "%s %s %d\n", words[idx].eng,words[idx].kor,&words[idx].level);
             if(strcmp(eng,words[idx].eng) == 0)
             {
	       delIdx = idx;
               break;
             }
	     idx++;
        }
	fclose(fp);

        FILE *fp2 = fopen("outputwords.txt","w");
	fprintf(fp,"%d",'\0');
        for(int i = 0;i<idx;i++)
        {
          if(delIdx==i){
          continue;
          }
          fprintf(fp,"%s %s %d \n",words[i].eng,words[i].kor,words[i].level);
        }
        fclose(fp2);
}

