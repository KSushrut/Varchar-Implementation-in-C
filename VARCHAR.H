#include<stdlib.h>
#include<stdio.h>
typedef struct varchar
{
	char data;
	struct varchar *next;
}varchar;
varchar create()
{
	varchar *head;
	head=NULL;
	return *head;
}
int isEmpty(varchar **head)
{
	if(*head==NULL)
	return 1;
	else
	return 0;
}
int isFull()
{
	varchar *ptr;
	ptr=(varchar *)malloc(sizeof(varchar));
	if(ptr==NULL)
	return 1;
	else
	{
		free(ptr);
		return 0;
	}
}
void display(varchar *head)
{
	varchar *current;
	current=head;
	while(current!=NULL)
	{
		printf("%c",current->data);
		current=current->next;
	}
}
void insertend(varchar *head,char n)
{
	varchar *ptr,*current;
	ptr=(varchar *)malloc(sizeof(varchar));
	ptr->data=n;
	ptr->next=NULL;
	if(head==NULL)
	{
	       head=ptr;
	}
	else
	{
		current=head;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=ptr;
	}
}
char delend(varchar *head)
{       	char x;
	varchar *ptr,*last;
	ptr=head;
	while(ptr->next->next!=NULL)
	{
		ptr=ptr->next;
	}
	last=ptr->next;
	ptr->next=NULL;
	x=last->data;
	free(last);
	return x;
}
int len(varchar *head)
{
	int count=0;
	varchar *current=head;
	while(current!=NULL)
	{
		count++;
		current=current->next;
	}
	return count-1;
}

void somedisplay(varchar *head, int n)
{
	int count = 0;
	varchar *current;
	current = head;
	while(count<=n)
	{
		printf("%c",current->data);
		current=current->next;
		count++;
	}
}

int varlen(varchar *head)
{
 int length = len(head);
 return length-1;
}