#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 1000

typedef struct queue queue;

struct queue 
{
	int current_size;
	int head;
	int tail;
	int items[MAX_QUEUE_SIZE];
};

queue* create_queue()
{
	queue *new_queue = (queue*)malloc(sizeof(queue));
	new_queue->current_size=0;
	new_queue->head = 0;
	new_queue->tail = MAX_QUEUE_SIZE-1;
	return new_queue;
}

void enqueue(queue *queue, int item)
{
	queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;
	queue->items[queue->tail] = item;
	queue->current_size++;
}

int dequeue(queue *queue)
{
	int dequeued = queue->items[queue->head];
	queue->head = (queue->head + 1) % MAX_QUEUE_SIZE;
	queue->current_size--;
	return dequeued;
}

void organizar(queue *head,queue *head1)
{
	int controll,controll1,trocas=0,aux,maior,indice;

	for(controll=0;controll<(head->current_size);controll++)
	{
		maior = head->items[controll];
		for(controll1=controll+1;controll1<(head->current_size);controll1++)
		{
			if(head->items[controll1]>maior)
			{
				maior = head->items[controll1];
				indice = controll1;
			}
		}
		if(maior > head->items[controll])
		{
			aux = head->items[controll];
			head->items[controll] = maior;
			head->items[indice] = aux;
		}
	}
	for(controll=0;controll<(head->current_size);controll++)
	{
		if(head->items[controll] != head1->items[controll])
		{
			trocas++;
		}
	}
	printf("%d\n",(head->current_size)-trocas);	
}

int main() 
{
	int casos,controle;
	scanf("%d\n",&casos);
	
	for(controle=0;controle<casos;controle++)
	{
		queue* fila = create_queue();
		queue* fila1 = create_queue();
		int alunos,aluno,controle1;
		scanf("%d\n",&alunos);

		for(controle1=0;controle1<alunos;controle1++)
		{
			scanf("%d",&aluno);
			enqueue(fila,aluno);
			enqueue(fila1,aluno);
		}
	
		organizar(fila,fila1);
		free(fila);
		free(fila1);
	}
	return 0;
}