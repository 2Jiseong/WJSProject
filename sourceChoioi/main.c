#include <stdio.h>
#include "addToWord.h"
#include "delToWord.h"
#include "examToWord.h"

int main()
{
	int select_num;
	while (1)
	{
		printf("1. 단어추가   ::   2. 단어삭제   ::   3.시험  ::   4.종료\n");
		scanf("%d", &select_num);
		
		switch (select_num)
		{
			case 1:
			{
				addToWord();
				break;
			}
			case 2:
			{
				delToWord();
				break;
			}
			case 3:
			{
				examToWord();
				break;
			}
			case 4:
			{
				return 0;
			}
			default:
			{
				printf("Please select 1, 2, 3, 4\n");
				break;
			}
		}

	}
	return 0;
}

