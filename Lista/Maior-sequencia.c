#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct list node;
struct list
{
	int posi;
	char item; 
	node *next;
};

node* create_linked_list()
{
	return NULL;
}

node* add(node *head, char item, int pos)
{
	node *new_node = (node*)malloc(sizeof(node));
	new_node->posi = pos;
	new_node->item = item;
	new_node->next = head;
	return new_node;
}

void cont(node *head)
{
	int maiorseq = 0,position=0,contador=0;
	node *aux;
	while(head != NULL)
	{
		if(head->item == '0')
		{
			contador++;
		}
		else
		{
			if(contador>maiorseq)
			{
				maiorseq = contador;
				position = head->posi;
			}
			contador = 0;
		}
		if(head->next==NULL)
		{
			aux->posi=head->posi;
		}
		head=head->next;
	}
	if(contador>maiorseq)
	{
		maiorseq = contador;
		position = (aux->posi)+1;
	}
	printf("%d %d\n",(position - maiorseq),position-1);
}

int main()
{	
	
	int i,size;

	while(1)
	{
		char string[1000];
		scanf("%s",string);

		if(strcmp(string,"0") == 0)
		{
			break;
		}
		else
		{
			node *list = create_linked_list();
			size = strlen(string);
			for(i=size-1;i>=0;i--)
			{
				list = add(list,string[i],i);
			}
			cont(list);
			free(list);
		}	
	}
	return 0;
}