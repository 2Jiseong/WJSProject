#include <stdio.h>
#include <string.h>
#include "delToWord.h"

typedef struct word{
	char eng[15];
	char kor[10];
	int level;
}word;

void delToWord()
{
	FILE *of = fopen("word.txt", "r");
	int level = 0;
	int idx = 0;
	int flag = 0;
	word add_w[100];
	char search[25];
	char *tmp;
	getchar();
	gets(search);
	tmp = strtok(search," ");

	while (1)
	{
		fscanf(of, "%s %s %d", &add_w[idx].eng, &add_w[idx].kor, &add_w[idx].level);
		if (add_w[idx].level <1 || add_w[idx].level > 3)
		{
			fclose(of);
			break;
		}
		if (strcmp(add_w[idx].eng, tmp) == 0)
		{
			strcpy(add_w[idx].eng, " ");
			strcpy(add_w[idx].kor, " ");
			add_w[idx].level = 0;
		}
		idx++;
	}

	FILE *pf = fopen("word.txt", "w");
	for (int i = 0; i < idx ; i++)
	{
		if (add_w[i].level == 0)
		{

		}
		else
		{
			fprintf(pf, "%s %s %d\n", add_w[i].eng, add_w[i].kor, add_w[i].level);
		}
	}
	fclose(pf);
}
