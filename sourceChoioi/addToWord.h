#ifndef _ADDTOWORD_H_
#define _ADDTOWORD_H_

typedef struct word{
	char eng[15];
	char kor[10];
	int level;
	int admin_flag;
}word;

void addToWord();

#endif 
