#include<stdio.h>

struct word{
    char eng[30];
    char kor[30];
    int level;
};


void show()
{
   word words[1000];
   FILE *fp = fopen("outputwords.txt","r");
   fscanf(fp,"%s %s %d",words[i].eng,words[i].kor,words[i].level);

}
