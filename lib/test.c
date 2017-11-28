#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include <time.h>

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
    int level = 0;
    int total = 0;
    int score = 0;
    char answer[100] = {0,};

	//level 판별
	if(strcmp(command,"easy") == 0){
		level = 1;
	}
	else if(strcmp(command,"normal")==0){
		level = 2;
	}
	else if(strcmp(command,"hard")==0){
		level = 3;
	}
	else{
		level = 0;
	}
	//단어 읽기
        while (feof(fp) == 0)
        {
            fscanf(fp, "%s %s %d", words[idx].eng, words[idx].kor, &words[idx].level);
	        if(level != words[idx].level)
		{
			words[idx].eng[0] = 0;
			words[idx].kor[0] = 0;
			words[idx].level = 0;
			continue;
		}
		idx++;
        }
	//난수 발생
	srand(time(0));
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
	total = idx;
	idx--;
	//문제제출 및 정답확인
	while(1)
        {
 	  if(idx == -1)
	  {
            printf("총 %d 개중 정답개수는 %d개 입니다!\n",total,score);
	    break;
 	  }
          printf("%s: ",words[all_arr[idx]].eng);
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
