#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//VERIFICA QUANTAS "P�GINAS" FORAM VISITADAS E DEPOIS EM QUAL PAROU E NO FIM IMPRIME O N�MERO DE ELEMENTOS NAS PILHAS DE BACKS E FORWARDS 

#define MAX_STACK_SIZE 1000

typedef struct stack stack;

struct stack 
{
	int current_size;
	char items[MAX_STACK_SIZE];
};

stack* create_stack()
{
	stack *new_stack = (stack*) malloc(sizeof(stack));
	new_stack->current_size = 0;
	return new_stack;
};

void push(stack *stack,char item)
{
	if (stack->current_size == MAX_STACK_SIZE) 
	{
		printf("Stack overflow");
	} 
	else 
	{
		stack->items[stack->current_size] = item;
		stack->current_size++;
	}
}

void pop(stack *stack)
{
	if (stack->current_size != 0) 
	{
		stack->current_size--; 
	} 
}

void print_stack(stack *head,stack *head1)
{
	printf("BACK: %d\n",head->current_size-1);
	printf("FORWARD: %d\n",head1->current_size);
}

int main() 
{
	char comando[20];

	stack *back = create_stack();
	stack *forward = create_stack();
	
	while(scanf("%s",comando) != EOF)
	{
		if(strcmp(comando,"ENTER")==0)
		{
			push(back,'b');
			pop(forward);
		}
		else if(strcmp(comando,"BACK")==0)
		{	
			push(forward,'f');
			pop(back);
		}
		else if(strcmp(comando,"FORWARD")==0)
		{
			push(back,'b');
			pop(forward);
		}
	}
	print_stack(back,forward);

	return 0;
}