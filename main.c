#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char eng[15];
	char kor[10];
	struct node *next;
	struct node *prev;
};
struct node* head;

int main()
{
	char e[20];
	char k[10];
	for (int i = 0; i < 3; i++)
	{
		scanf("%s %s", e, k);
		addToDLL(e, k);
	}
	showDLL();
}
