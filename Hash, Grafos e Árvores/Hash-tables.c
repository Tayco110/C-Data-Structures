#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 101

typedef struct node node;
typedef struct hash_table hash_table;

struct node
{
	int key;
	int item;
	node* next;
};

struct hash_table
{
	node* table[MAX_STACK_SIZE];
};

void add_tail(node* head,node* element)
{
	node* aux = head;

	while(aux->next != NULL)
	{
		aux = aux->next;
	}
	aux->next = element;
}

hash_table* create_hash_table()
{
	hash_table* new_table = (hash_table*)malloc(sizeof(hash_table));

	int i;
	for(i=0;i<MAX_STACK_SIZE;i++)
	{
		new_table->table[i] = NULL;
	}

	return new_table;
}

void put(hash_table* ht,int key,int value)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->item = value;
	new_node->key = key;
	new_node->next = NULL;

	if(ht->table[key] == NULL)
	{
		ht->table[key] = new_node;
	}
	else
	{
		add_tail(ht->table[key],new_node);
	}
}

void print_linked_list(node *head)
{
	char a = 92;

	if(head == NULL)
	{
		printf(" -> %c\n",a);
	}
	else
	{
		while (head != NULL) 
		{
			printf(" -> %d", head->item);
		
			if(head->next == NULL)
			{
				printf(" -> %c\n",a);
			}
			head = head->next;
		}
	}
}

void print_hash(hash_table* ht,int address)
{
	int i;
	for(i=0;i<address;i++)
	{
		printf("%d",i);
		print_linked_list(ht->table[i]);
	}
}


int main()
{
	int casos,controle;
	scanf("%d",&casos);

	for(controle=0;controle<casos;controle++)
	{
		int address,keys,element,chave;
		int i;
		char space;
		scanf("%d%c%d",&address,&space,&keys);

		hash_table* tabela_hash = create_hash_table();

		for(i=0;i<keys;i++)
		{
			scanf("%d",&element);
			chave = (element%address);

			put(tabela_hash,chave,element);
		}

		print_hash(tabela_hash,address);
        printf("\n");
	}
	return 0;
}



