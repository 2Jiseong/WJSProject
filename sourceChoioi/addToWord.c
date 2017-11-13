#include <stdio.h>
#include <string.h>
#include "addToWord.h"

void addToWord()
{
	FILE *f = fopen("word.txt", "w");
	int level = 0;
	word add_w;
	scanf("%s %s", add_w.eng, add_w.kor);
	level = strlen(add_w.eng);
	if (level < 5)
	{
		add_w.level = 1;
	}
	else if (level >= 5 && level < 10)
	{
		add_w.level = 2;
	}
	else if (level>=10)
	{
		add_w.level = 3;
	}
	fprintf(f,"%s %s %d\n", add_w.eng, add_w.kor, add_w.level);
	fclose(f);
	
}
