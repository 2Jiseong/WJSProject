#include<stdio.h>
#include<stdlib.h>

void insert(FILE *fp,char eng[10][30],char kor[10][30]);

void main(int argc,char *argv[])
{
  char eng[10][30];
  char kor[10][30];
  FILE *fp = fopen("word.txt","r");
  if(fp == NULL)
  {
	printf("error!");
	return;
  }

  insert(fp,eng,kor);

  for(int i=0;i<5;i++)
  {
    printf("%s ",eng[i]);
    printf("%s ",kor[i]);
  }

  fclose(fp);
  return;
}
