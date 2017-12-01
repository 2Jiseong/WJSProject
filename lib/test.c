#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct word{
        char eng[30];
        char kor[30];
        int level;
}word;

typedef struct onIdx{
	int originIdx;
	int newIdx;
}onIdx;

void test(FILE *fp,char *command)
{
    word words[10000];
    word wrongWords[10000];
    word compWords[10000];
    onIdx compIdx[1000];
    compIdx[0].newIdx = -1;
    compIdx[0].originIdx = -1;

    int all_arr[10000];
    int idx = 0;
    int idx2 = 0;
    int level = 0;

    int total = 0;
    int score = 0;
    int fault = 0;
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
	else if(strcmp(command,"all")==0){
		level = 0;
	}
        else{
		printf("option error!");
		return;
	}
	//단어 읽기
        while (feof(fp) == 0)
        {
            fscanf(fp, "%s %s %d\n", words[idx].eng, words[idx].kor, &words[idx].level);
	 	if(level != words[idx].level && level != 0)
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
          if(idx == -1)//종료시 작업
          {
	     printf("총 %d개중 당신의 점수는 %d개 입니다!\n",total,score);
	     int l = 0;
	     //파일 확인
             int result = access("wrongwords.txt",0);
             if(result == 0)
             {
              FILE *fp3 = fopen("wrongwords.txt","r");
              while(feof(fp3) ==0)
              {
                  fscanf(fp3,"%s %s %d\n",compWords[l].eng,compWords[l].kor,&compWords[l].level); 
                  l++;
              }
              remove("wrongwords.txt");
	      fclose(fp3);
             }
             else
	     {
              FILE *fp3 = fopen("wrongwords.txt","w");
              fclose(fp3);
	     }
	     //기존에 있던 단어 확인
             for(int i = 0;i<fault;i++)
             {
                for(int j =0;j<l;j++)
                {
		    if(strlen(compWords[j].eng) == 0)
		    {
      			continue;
                    }
                    if(strcmp(wrongWords[i].eng,compWords[j].eng) == 0)
                    {
                        compIdx[idx2].newIdx = i;
                        compIdx[idx2].originIdx = j;
                        idx2++;
                    }
                }
             }
             //printf("l:%d fault:%d\n",l,fault );

             FILE *fp2 = fopen("wrongwords.txt","w");
	     idx2 = 0;
	     for(int i = 0;i<l;i++) //기존 데이터 저장
             {
		if(strlen(compWords[i].eng) == 0)
		{
			continue;
		}
		if(compIdx[idx2].originIdx == i)
		{
		   fprintf(fp2,"%s %s %d\n",compWords[i].eng,compWords[i].kor,compWords[i].level+1);
		   //printf("1 : %s %s %d\n",compWords[i].eng,compWords[i].kor,compWords[i].level+1);
		   idx2++;
		}
		else
		{
		   fprintf(fp2,"%s %s %d\n",compWords[i].eng,compWords[i].kor,compWords[i].level);
		   //printf("2 : %s %s %d\n",compWords[i].eng,compWords[i].kor,compWords[i].level);
		}
             }

	     idx2 = 0;
	     for(int i =0;i<fault;i++) //새로 틀린 데이터
	     {
		if(compIdx[idx2].newIdx == i)
		{
			idx2++;
			continue;
		}
		fprintf(fp2,"%s %s %d\n",wrongWords[i].eng,wrongWords[i].kor,1);
                //printf("3 : %s %s %d\n",wrongWords[i].eng,wrongWords[i].kor,1);
	     }
	    fclose(fp2);
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
           strcpy(wrongWords[fault].eng,words[all_arr[idx]].eng);
           strcpy(wrongWords[fault].kor,words[all_arr[idx]].kor);
           wrongWords[fault].level=words[all_arr[idx]].level;
           fault++;
           printf("틀렸습니다!\n");
          }
         idx--;
        }

}
