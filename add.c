void addToDLL(char* a,char* b)
{
	struct node *cur;
	cur = (struct node *)malloc(sizeof(struct node));
	cur->next = cur->prev = 0;
	strcpy(cur->eng, a);
	strcpy(cur->kor, b);

	// check if there is no node
	if (head == 0)
	{
		head = cur;
		return;
	}

	// find the last node
	{
		struct node *temp = head;
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = cur;
		cur->prev = temp;
		return;
	}
}
