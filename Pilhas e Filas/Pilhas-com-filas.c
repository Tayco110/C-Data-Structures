#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1000

typedef struct node node;
typedef struct stack stack;

struct node 
{
	int item;
	node *next;
};

struct stack 
{
	int current_size;
	node *items[MAX_STACK_SIZE]; 
};

node* create_linked_list()
{
	return NULL;
}

stack* create_stack()
{
	int controle;
	stack* new_stack = (stack*) malloc(sizeof(stack));
	new_stack->current_size = 0;
    
    for(controle=0;controle< MAX_STACK_SIZE;controle++)
    {
        new_stack->items[controle] = NULL;
    }
	
	return new_stack;
}

int is_empty(stack *head)
{
	if (head->current_size == 0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void print_linked_list(node *head)
{
	while (head != NULL) 
	{
		printf("%d", head->item);
		if(head->next != NULL)
		{
			printf(" ");
		}
		head = head->next;
	}
	printf("\n");
}

void push(stack *head, node *item)
{
	if (head->current_size == MAX_STACK_SIZE)
	{
		printf("Stack overflow\n");
	} 
	else 
	{
		head->items[++head->current_size] = item;
	}
}



node* add(node *head, int conteudo)
{
	node *aux = head;
	node *new_node = (node*)malloc(sizeof(node));
	
	new_node->item = conteudo;
	new_node->next = NULL;
	
	if (head == NULL)
	{
		return new_node;
	}
	while(aux->next != NULL)
	{
		aux = aux->next;
	}
	aux->next = new_node;
	return head;
}


void pop(stack* head)
{
	if (head->current_size == 0)
	{
		printf("EMPTY STACK\n");
	} 
	else
	{
	    print_linked_list(head->items[head->current_size]);
		head->current_size--;
	}
}



int main() 
{
	char comando[5],proxchar;
	stack *pilha = create_stack();
	int valor;

	while(scanf("%s",comando) != EOF)
	{
		node *lista = create_linked_list();

		if(strcmp(comando,"PUSH")==0)
		{
			lista = create_linked_list();
			while(scanf("%d%c",&valor,&proxchar))
			{
				lista = add(lista,valor);
				if(proxchar == '\n')
				{
					break;
				}
			}
			push(pilha,lista);

		}
		else if(strcmp(comando,"POP")==0)
		{
			pop(pilha);
		}
	}
	return 0;
}