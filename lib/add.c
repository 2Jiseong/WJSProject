#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "add.h"
void addToWord(char *eng,char *kor)
{ 
        int level = 0;
        FILE *fp = fopen("outputwords.txt", "a");
        
        //level check
        level = strlen(eng);
        if (level < 5)
        {
                level = 1;
        }
        else if (level >= 5 && level < 10)
        {
                level = 2;
        }
        else if (level>=10)
        {
                level = 3;
        }
        
        //file write
        fprintf(fp,"%s %s %d \n",eng,kor,level);
        fclose(fp);
}

