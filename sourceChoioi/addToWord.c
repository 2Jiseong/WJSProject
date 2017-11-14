#include <stdio.h>
#include <string.h>
#include "addToWord.h"

void addToWord()
{
	FILE *of = fopen("word.txt", "r");
	int level = 0;
	int idx = 0;
	word add_w[100];

	
	while (1)
	{
		fscanf(of,"%s %s %d", &add_w[idx].eng, &add_w[idx].kor, &add_w[idx].level);
		if (add_w[idx].level <1 || add_w[idx].level > 3)
		{
			fclose(of);
			break;
		}
		idx++;
	}
	
	FILE *pf = fopen("word.txt", "w");
	scanf("%s %s", &add_w[idx].eng, &add_w[idx].kor);
	level = strlen(add_w[idx].eng);

	if (level < 5)
	{
		add_w[idx].level = 1;
	}
	else if (level >= 5 && level < 10)
	{
		add_w[idx].level = 2;
	}
	else if (level>=10)
	{
		add_w[idx].level = 3;
	}


	for (int i = 0; i < idx + 1; i++)
	{
		fprintf(pf, "%s %s %d\n", add_w[i].eng, add_w[i].kor, add_w[i].level);
	}
	fclose(pf);
	
	
}
