#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct list node;

struct list
{
	char item;
	int freq;
	int ascci; 
	node *next;
};

int search(node *head, char a)
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

node* create_linked_list()
{
	return NULL;
}

void print_linked_list(node *head)
{
	while (head != NULL) 
	{
		printf("%c %d\n", head->item,head->freq);
		head = head->next;
	}
}

void ordenar(node *head)
{
	node *aux1=head;
	node *aux2=head;
	int auxfreq,auxascci;
	char auxitem;
	
	while(aux1 != NULL)
	{
		while(aux2 != NULL)
		{
			if((aux2->ascci)>(aux1->ascci))
			{
				auxfreq = aux1->freq;
				aux1->freq = aux2->freq;
				aux2->freq = auxfreq;

				auxascci = aux1->ascci;
				aux1->ascci = aux2->ascci;
				aux2->ascci = auxascci;

				auxitem = aux1->item;
				aux1->item = aux2->item;
				aux2->item = auxitem;
			}
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
		aux2 = aux1;
	}
	print_linked_list(head);
	
}

node* add(node *head, int item, char letra)
{
	node *new_node = (node*)malloc(sizeof(node));
	new_node->item = letra;
	new_node->freq = item;
	new_node->ascci = letra;
	new_node->next = head;
	return new_node;
}

int main()
{
	char string[257],letra;
	gets(string);
	int i,j,size,contador = 0;
	size = strlen(string);
	node *list = create_linked_list();
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(string[j]==string[i])
			{
				contador++;
			}
		}
		if(search(list,string[i])==0)
		{
			list = add(list,contador,string[i]);
		}
		contador = 0;
	}
	ordenar(list);
	return 0;
}