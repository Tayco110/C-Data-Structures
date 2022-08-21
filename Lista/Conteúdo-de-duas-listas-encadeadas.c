#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct list node;

struct list
{
	int valor;
	node *next;
};

node* create_linked_list()
{
	return NULL;
}

node* add(node *head, int item)
{
	node *new_node = (node*)malloc(sizeof(node));
	new_node->valor = item;
	new_node->next = head;
	return new_node;
}

void print_linked_list(node *head)
{
	while (head != NULL) 
	{
		printf("%d\n", head->valor);
		head = head->next;
	}
}

int comparar(node *head1,node *head2, int tamm, int tamn)
{
	int controle = 0,i,j;
	node *aux = head1;
	for(i=0;i<tamn;i++)
	{
		for(j=0;j<tamm;j++)
		{
			if((head2->valor)==(aux->valor))
			{
				controle = 1;
			}
			aux = aux->next;
		}
		if(controle == 0)
		{
			return 0;
		}
		aux = head1;
		head2 = head2->next;
		controle = 0;
	}
	return 1;
}

int main()
{
	node* list1 = create_linked_list();
	node* list2 = create_linked_list();
	
	int m,n,i,conteudo,j;
	
	scanf("%d",&m);	
	for(i=0;i<m;i++)
	{
		scanf("%d",&conteudo);
		list1 = add(list1,conteudo);
	}
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&conteudo);
		list2 = add(list2,conteudo);
	}

	j = comparar(list1,list2,m,n);

	printf("%d\n",j);

	return 0;
}