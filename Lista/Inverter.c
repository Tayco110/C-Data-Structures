#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
	int item;
	node* next;
};

node* create_linked_list()
{
	return NULL;
}

node* add_tail(node *head, int item)
{
	node *new_node = (node*)malloc(sizeof(node));
	new_node->item = item;
	new_node->next = NULL;
	if(head == NULL)
	{
		head = new_node;
	}
	else
	{
		node* aux = head;
		while(aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = new_node;	
	}
	return head;
}

node* add_head(node* head,int item)
{
	node *new_node = (node*)malloc(sizeof(node));
	new_node->item = item;
	new_node->next = head;
	return new_node;
}

node* inverter(node* head)
{
	node* aux = create_linked_list();

	while(head != NULL)
	{
		aux = add_head(aux, head->item);
		head = head->next;
	}

	return aux;
}


void print_linked_list(node *head)
{
	while (head != NULL) 
	{
		printf("%d ", head->item);
		head = head->next;
	}
}

int main()
{
	int item;
	node* inteiros = create_linked_list();

	while(scanf("%d",&item) != EOF)
	{
		inteiros = add_tail(inteiros,item);
	}

	inteiros = inverter(inteiros);
	print_linked_list(inteiros);

	return 0;
}