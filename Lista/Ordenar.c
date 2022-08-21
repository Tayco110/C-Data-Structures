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
		printf("%d ", head->item);
		head = head->next;
	}
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

int main()
{
	int valor;
	node *list = create_linked_list();
	
	while(scanf("%d",&valor) != EOF)
	{
		list = add(list,valor);
	}

	ordenar(list);
	return 0;
}