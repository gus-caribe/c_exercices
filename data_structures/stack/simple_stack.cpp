#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	int item;
	struct no *prox;
}tNo;

typedef struct// pilha
{
	tNo *primeiro;
	tNo *topo;
}tPilha;

tPilha *inicializa()
{
	tPilha *p = (tPilha*)malloc(sizeof(tPilha));
	p->primeiro = NULL;
	p->topo = NULL;

	return p;
}


void push (int valor, tPilha *p)
{
	tNo *n = (tNo*)malloc(sizeof(tNo));

	n->item = valor;
	n->prox = NULL;

	if(p->primeiro == NULL)
		p->primeiro = n;
	
	else
	{
		n->prox = p->primeiro;
		p->primeiro = n; 
	}
	
	system("cls");
	printf("Operacao realizada com sucesso.\n\n");
	system("pause");
}

void pop (tPilha *p)
{
	tNo *excluded;	
	
	excluded = p->primeiro;
	p->primeiro = p->primeiro->prox; 
	
	free(excluded);
	
	if(p->primeiro ==  NULL)
		p->topo = NULL;
		
	system("cls");
	printf("Operacao realizada com sucesso.\n\n");
	system("pause");
}


void free_space(int size, tPilha *p)
{
	while(size)
	{
		tNo *excluded;
		excluded = p->primeiro;
		p->primeiro = p->primeiro->prox;
		size--;
		
		free(excluded);
	}
	
	if(p->primeiro ==  NULL)
		p->topo = NULL;
}


int tamanho(tPilha *p)
{ 
	tNo *aux = p->primeiro;
	int ultimo = 0;

	while(aux != NULL) {
		aux = aux->prox; 
		ultimo++;
	}

	return ultimo;
}

void listar(tPilha *p)
{
    tNo *atual = p->primeiro;
    
    system("cls");
    printf("LISTAR\n\n");
    
    while(atual != NULL){
	    printf("%d\n",atual->item);
	    atual = atual->prox;
    }
    
    printf("\n");
    system("pause");
}

int main()
{
	int menu = 1, opcao, item;
	tPilha *p = inicializa();

	while(menu)
	{
		system("cls");
		
		printf("MENU");
		
		printf("\n\n1 - Push\n");
		printf("2 - Pop\n");
		printf("3 - Listar\n");
		printf("4 - Sair\n\n");
		printf("Opcao: ");
		scanf("%i", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				printf("Insira o valor do item: ");
				scanf("%i", &item);
				push(item, p);
				break;
				
			case 2:
				pop(p);
				break;
				
			case 3:
				listar(p);
				break;
				
			case 4:
				free_space(tamanho(p), p);
				menu = 0;
				system("cls");
				printf("Sistema finalizado.\n\n");
				system("pause");
				break;
				
			default:
				system("cls");
				printf("Opcao invalida.\n\n");
				system("pause");
				break;
		}
	}

	return 0;
}
