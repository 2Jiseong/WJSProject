void showDLL()
{
	struct node *cur = head;
	while (cur != 0)
	{
		printf("%s %s\n", cur->eng,cur->kor);
		cur = cur->next;
	}
}
