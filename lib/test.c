#include <stdio.h>	

#include <stdlib.h>
#include <string.h>
#include "test.h"

typedef struct word{
        char eng[30];
        char kor[30];
        int level;
}word;

void test(FILE *fp,char *command)
{
        word words[10000];
        int all_arr[10000]; 
        int idx = 0;
	int score = 0;
	char answer[100] = {0,};

        while (feof(fp) == 0)
        {
	  if(command == 0)
	  {
            fscanf(fp, "%s %s %d", words[idx].eng, words[idx].kor, &words[idx].level);
   	    idx++;
  	  }
        }
        for (int i = 0; i < idx; i++)
        {
                all_arr[i] = rand() % idx;
                for (int j = 0; j < i; j++)
                {
                        if (all_arr[i] == all_arr[j])
                        {
                                i--;
                                break;
                        }
                }
        }
	while(1)
        {
	  if(idx == 0)
          {
	     printf("당신의 점수는 %d 입니다!\n",score);
             break;
	  }
          printf("%s: %s: ",words[all_arr[idx]].eng,words[all_arr[idx]].kor);
          scanf("%s",answer);
	  if(strcmp(words[all_arr[idx]].kor,answer) == 0)
          {
	   score++;
	   printf("정답입니다!\n");
          }
   	  else
	  {
	   printf("틀렸습니다\n");
   	  }
	  idx--;
        }
}
