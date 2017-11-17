#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "examToWord.h"

typedef struct word{
	char eng[15];
	char kor[10];
	int level;
}word;

void examToWord()
{
	while (1)
	{
		fscanf(of, "%s %s %d", &add_w[idx].eng, &add_w[idx].kor, &add_w[idx].level);
		if (add_w[idx].level <1 || add_w[idx].level > 3)
		{
			fclose(of);
			break;
		}
		if (add_w[idx].level == 1)
		{
			easy_arr[e_idx++] = idx;
		}
		else if (add_w[idx].level == 2)
		{
			normal_arr[n_idx++] = idx;
		}
		else if (add_w[idx].level == 3)
		{
			hard_arr[h_idx++] = idx;
		}
		idx++;
	}
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

	printf("1 :: easy   2 :: normal   3 :: hard  4 :: all\n");
	scanf("%d", &step);

	switch (step)
	{
		case 1:
		{
			char ans[15];
			int c_cnt = 0;
			for (int i = 0; i < e_idx; i++)
			{
				printf("%s ", add_w[easy_arr[i]].eng);
				scanf("%s", ans);
				if (strcmp(add_w[easy_arr[i]].kor, ans) == 0)
				{
					c_cnt++;
				}
				printf("answer_rate :: %d/%d\n", c_cnt, i + 1);
			}
			break;
		}
		case 2:
		{
			char ans[15];
			int c_cnt = 0;
			for (int i = 0; i < n_idx; i++)
			{
				printf("%s ", add_w[normal_arr[i]].eng);
				scanf("%s", ans);
				if (strcmp(add_w[normal_arr[i]].kor, ans) == 0)
				{
					c_cnt++;
				}
				printf("answer_rate :: %d/%d\n", c_cnt, i + 1);
			}
			break;
		}
		case 3:
		{
			char ans[15];
			int c_cnt = 0;
			for (int i = 0; i < h_idx; i++)
			{
				printf("%s ", add_w[hard_arr[i]].eng);
				scanf("%s", ans);
				if (strcmp(add_w[hard_arr[i]].kor, ans) == 0)
				{
					c_cnt++;
				}
				printf("answer_rate :: %d/%d\n", c_cnt, i + 1);
			}
			break;
		}
		case 4:
		{
			char ans[15];
			int c_cnt = 0;
			for (int i = 0; i < idx; i++)
			{
				printf("%s ", add_w[all_arr[i]].eng);
				scanf("%s", ans);
				if (strcmp(add_w[all_arr[i]].kor, ans) == 0)
				{
					c_cnt++;
				}
				printf("answer_rate :: %d/%d\n", c_cnt, i+1);
			}
			break;
		}
	}
	printf("finish test!\n");
}
