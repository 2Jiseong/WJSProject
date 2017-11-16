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
}
