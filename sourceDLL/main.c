#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct node text[100];
	char del_word[20];
	int M_num;
	int idx = 0;
	while (1)
	{
		printManual();
		scanf("%d", &M_num);
		
		switch (M_num)
		{
			case 1:
			{
				scanf("%s %s", text[idx].eng, text[idx].kor);
				addToDLL(text[idx].eng, text[idx].kor);
				idx++;
				break;
			}
			case 2:
			{
				scanf("%s", del_word);
				delFromDLL(del_word);
				idx--;
				break;
			}
			case 3:
			{
				showDLL();
				break;
			}
			case 4:
			{
				return 0;
			}
			default:
			{
				printf("1, 2, 3번 중에 하나를 입력하세요.\n");
				break;
			}
		}
	}
}
