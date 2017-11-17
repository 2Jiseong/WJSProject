#include <stdio.h>
#include <string.h>
#include "del.h"

typedef struct word{
        char eng[15];
        char kor[10];
        int level;
}word;

void delToWord(char eng[100])
{
        FILE *fp = fopen("words.txt", "r");
        word words[100];
        char *rmEng;
        int level = 0;
        int idx = 0;
        rmEng = strtok(eng," ");

        while (1)
        {
                fscanf(fp, "%s %s %d", &words[idx].eng, &words[idx].kor, &words[idx].level);
                if (words[idx].level <1 || words[idx].level > 3)
                {
                        fclose(fp);
                        break;
                }
                if (strcmp(words[idx].eng, rmEng) == 0)
                {
                        strcpy(words[idx].eng, " ");
                        strcpy(words[idx].kor, " ");
                        words[idx].level = 0;
                }
                idx++;
        }

        FILE *fp2 = fopen("words.txt", "w");
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

