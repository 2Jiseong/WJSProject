#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wchar.h>
#include "word.h"
void addToWord(char *eng,char *kor)
{ 
        FILE *fp = fopen("words.txt", "wt");
        fwrite(eng,strlen(eng),1,fp);
        fwrite(" ",sizeof(char),1,fp);
        fwrite(kor,strlen(kor),1,fp);
        fwrite("\n",sizeof(char),1,fp);
        fclose(fp);
}

