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
	FILE *fp = fopen("outputwords.txt","r");
        word words[100];
        int delIdx = 0;
        int idx = 0;
        while (feof(fp)==0)
        {
             fscanf(fp, "%s %s %d\n", words[idx].eng,words[idx].kor,&words[idx].level);
             if(strcmp(eng,words[idx].eng) == 0)
             {
	       delIdx = idx;
             }
	     idx++;
        }
	remove("outputwords.txt");
 	fclose(fp);
        FILE *fp2 = fopen("outputwords.txt","w");
        // null을 넣어버리면 파일이 전부 삭제 되기 때문에, 파일 삭제 후 재생성
        for(int i = 0;i<idx;i++)
        {
          if(delIdx==i){
          continue;
          }
          fprintf(fp2,"%s %s %d\n",words[i].eng,words[i].kor,words[i].level);
        }
        fclose(fp2);
}

