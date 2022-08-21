#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct list node;
struct list
{
	int item;
	node *next;
};

node* create_linked_list()
{
	return NULL;
}

node* add(node *head, int item)
{
	node *new_node = (node*)malloc(sizeof(node));
	new_node->item = item;
	new_node->next = head;
	return new_node;
}

void print_linked_list(node *head)
{
	while (head != NULL) 
	{
		printf("%d\n", head->item);
		head = head->next;
	}
}

int search(node *head, int a)
{
	while(head != NULL)
	{
		if((head->item)==a)
		{
			return 1;
		}
		head = head->next;
	}
	return 0;
}

void ordenar(node *head)
{
	node *aux1=head;
	node *aux2=head;
	int menor;
	while(aux1 != NULL)
	{
		while(aux2 != NULL)
		{
			if((aux2->item)<(aux1->item))
			{
				menor = aux1->item;
				aux1->item = aux2->item;
				aux2->item = menor;
			}
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
		aux2 = aux1;
	}
	print_linked_list(head);
	
}

void inter(node *head1, node *head2)
{
	int i,j;
	node *aux=head2;
	node *list3 = create_linked_list();

	while(head1 != NULL)
	{
		while(aux != NULL)
		{
			if((head1->item)==(aux->item) && (search(list3,aux->item)==0))
			{
				list3 = add(list3,head1->item);		
			}
			aux = aux->next;
		}
		aux = head2;
		head1 = head1->next;
	}

	if(list3 == NULL)
	{
		printf("VAZIO\n");
	}
	else
	{
		ordenar(list3);
	}

}

int main()
{
	int i,valor;
	node *list1 = create_linked_list();
	node *list2 = create_linked_list();

	for(i=0;i<20;i++)
	{
		scanf("%d",&valor);
		list1 = add(list1,valor);
	}

	for(i=0;i<20;i++)
	{
		scanf("%d",&valor);
		list2 = add(list2,valor);
	}

	inter(list1,list2);
	return 0;
}