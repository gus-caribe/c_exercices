#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int topo;
	float *item;
} pilha;

pilha principal;
pilha auxiliar;

void inicializa (pilha *p, pilha *a, int tamanho)
{
	p->topo = -1;
	p->item = (float*)malloc(tamanho*sizeof(p->item));
	a->topo = -1;
	a->item = (float*)malloc(tamanho*sizeof(a->item));
}

int cheia (pilha *p, int tamanho)
{
	return p->topo == tamanho-1;
}

int vazia (pilha *p)
{
	return p->topo == -1;
}

void push (pilha *p, float valor)
{
	p->topo++;
	p->item[p->topo] = valor;
}

float pop (pilha *p)
{
	float valor = p->item[p->topo];
	
	p->item[p->topo] = 0;
	p->topo--;
	
	return valor;
}

float check (pilha *p, int posicao)
{
	return p->item[posicao-1];
}

int topo (pilha *p)
{
	return p->topo+1;
}

void push_middle (pilha *p, int posicao, float valor)
{
	int i, count = p->topo - (posicao-1);
	
	for(i=0; i<=count; i++)
	{
		push(&auxiliar, pop(&principal));
	}
	
	push(&principal, valor);
	
	for(i=0; i<=count; i++)
	{
		push(&principal, pop(&auxiliar));
	}
}

void pop_middle (pilha *p, int posicao)
{
	int i, count = p->topo - (posicao-1);
	
	for(i=0; i<count; i++)
	{
		push(&auxiliar, pop(&principal));
	}
	
	pop(&principal);
	
	for(i=0; i<count; i++)
	{
		push(&principal, pop(&auxiliar));
	}
}

void change (pilha *p, int posicao, float valor)
{
	int i, count = p->topo - (posicao-1);
	
	for(i=0; i<count; i++)
	{
		push(&auxiliar, pop(&principal));
	}
	
	pop(&principal);
	push(&principal, valor);
	
	for(i=0; i<count; i++)
	{
		push(&principal, pop(&auxiliar));
	}
}

void trade (pilha *p, int posicao1, int posicao2)
{
	float aux = p->item[posicao1-1];
	
	change(&principal, posicao1, p->item[posicao2-1]);
	change(&principal, posicao2, aux);
}

void buscar (pilha *p, float valor)
{
	int i;
	
	for(i=0; i<=p->topo; i++)
	{
		if(p->item[i] == valor)
		printf("\t- %i\n", i+1);
	}
}

void listar (pilha *p)
{
	int i;
	
	for(i=0; i<=p->topo; i++)
	printf("Posicao %i: %f\n", i+1, p->item[i]);
}

void listar_crescente (pilha *p)
{
	int i, j;
	float aux, vetor[p->topo+1];
	
	for(i=0; i<=p->topo; i++)
	{
		vetor[i] = p->item[i];
	}
	
	for(i=0; i<=p->topo; i++)
	{
		for(j=i; j<=p->topo; j++)
		{
			if(vetor[i]>vetor[j])
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
		
		printf("%f\n", vetor[i]);
	}
}

void listar_decrescente (pilha *p)
{
	int i, j;
	float aux, vetor[p->topo+1];
	
	for(i=0; i<=p->topo; i++)
	{
		vetor[i] = p->item[i];
	}
	
	for(i=0; i<=p->topo; i++)
	{
		for(j=i; j<=p->topo; j++)
		{
			if(vetor[i]<vetor[j])
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
		
		printf("%f\n", vetor[i]);
	}
}

int main()
{
	int tamanho, menu=1, choice=1, posicao, novaposicao, posicao1, posicao2;
	float valor, novovalor;
		
	printf("Qual tamanho de pilha deseja criar?: ");
	scanf("%i", &tamanho);
	
	inicializa(&principal, &auxiliar, tamanho);
	
	while(menu)
	{
		int escolha;
		
		system("cls");
		
		printf("MENU");
		printf("\n\n1- Push");
		printf("\n2- Pop");
		printf("\n3- Push no meio da pilha");
		printf("\n4- Pop no meio da pilha");
		printf("\n5- Checar valor na posicao");
		printf("\n6- Checar posicoes para um valor");
		printf("\n7- Checar topo da pilha");
		printf("\n8- Mudar valor de uma posicao");
		printf("\n9- Trocar valores de duas posicoes");
		printf("\n10- Listar normalmente");
		printf("\n11- Listar em ordem crescente");
		printf("\n12- Listar em ordem decrescente");
		printf("\n\n13- SAIR");
		printf("\n\nEscolha: ");
		scanf("%i", &escolha);
		
		switch(escolha)
		{
			case 1:
				if(cheia(&principal, tamanho))
				{
					system("cls");
					printf("Infelizmente, a pilha ja esta cheia.\n\n");
					system("pause");
				}
				else
				{
					float valor;
					system("cls");
					printf("Insira o valor a ser empilhado: ");
					scanf("%f", &valor);
					push(&principal, valor);
					system("cls");
					printf("Sucesso!\n\n");
					system("pause");
				}	
			break;
			
			case 2:
				if(vazia(&principal))
				{
					system("cls");
					printf("Infelizmente, a pilha ja esta vazia.\n\n");
					system("pause");
				}
				else
				{
					pop(&principal);
					system("cls");
					printf("Sucesso!\n\n");
					system("pause");
				}	
			break;
			
			case 3:
				if(cheia(&principal, tamanho))
				{
					system("cls");
					printf("Infelizmente, a pilha ja esta cheia.\n\n");
					system("pause");
				}
				else
				{
					float valor;
					int posicao;
					
					while(1)
					{
						system("cls");
						printf("Insira a posicao a ser empilhada: ");
						scanf("%i", &posicao);
						printf("\nInsira o valor a ser empilhado: ");
						scanf("%f", &valor);
						
						if(posicao > topo(&principal) && posicao < 0)
						{
							system("cls");
							printf("Posicao inexistente\n\n");
							system("pause");
							system("cls");
						}
						else
						{
							push_middle(&principal, posicao, valor);
							system("cls");
							printf("Sucesso!\n\n");
							system("pause");
							break;
						}
					}
				}	
			break;
			
			case 4:
				if(vazia(&principal))
				{
					system("cls");
					printf("Infelizmente, a pilha ja esta vazia.\n\n");
					system("pause");
				}
				else
				{
					int posicao;
					
					while(1)
					{
						system("cls");
						printf("Insira a posicao a ser excluida: ");
						scanf("%i", &posicao);
						if(posicao > topo(&principal) && posicao < 0)
						{
							system("cls");
							printf("Posicao inexistente\n\n");
							system("pause");
						}
						else
						{
							pop_middle(&principal, posicao);
							system("cls");
							printf("Sucesso!\n\n");
							system("pause");
							break;
						}
					}
				}	
			break;
			
			case 5:
				system("cls");
				printf("Favor inserir posicao a ser checada: ");
				scanf("%i", &posicao);
				
				if(posicao > topo(&principal) && posicao < 0)
				{
					system("cls");
					printf("Posicao inexistente\n\n");
					system("pause");
				}
				else
				{
					system("cls");
					printf("O valor na posicao %i e: %f", posicao, check(&principal, posicao));
					printf("\n\n");
					system("pause");
				}
			break;
			
			case 6:
				system("cls");
				printf("Favor inserir valor a ser checado: ");
				scanf("%f", &valor);
				
				system("cls");
				printf("As posicoes com o valor %f sao: \n\n", valor);
				buscar(&principal, valor);
				printf("\n\n");
				system("pause");
			break;
			
			case 7:
				system("cls");
				printf("O topo da pilha e: %i de %i\n\n", topo(&principal), tamanho);
				system("pause");
			break;
			
			case 8:
				while(1)
				{
					system("cls");
					printf("Favor inserir posicao a ser mudada: ");
					scanf("%i", &novaposicao);
					printf("Agora insira o novo valor: ");
					scanf("%f", &novovalor);
					
					if(novaposicao > topo(&principal) && novaposicao < 0)
					{
						system("cls");
						printf("Posicao inexistente\n\n");
						system("pause");
					}
					else
					{
						system("cls");
						change(&principal, novaposicao, novovalor);
						printf("Sucesso.");
						printf("\n\n");
						system("pause");
						break;
					}
				}
			break;
			
			case 9:
				while(choice)
				{
					system("cls");
					printf("Favor inserir a primeira posicao: ");
					scanf("%i", &posicao1);
					printf("Agora insira a segunda posicao: ");
					scanf("%i", &posicao2);
					
					if(((posicao1 || posicao2) > topo(&principal)) && ((posicao1 || posicao2) < 0))
					{
						system("cls");
						printf("Posicoes inexistentes\n\n");
						system("pause");
					}
					else
					{
						system("cls");
						trade(&principal, posicao1, posicao2);
						printf("Sucesso.");
						printf("\n\n");
						system("pause");
						choice=0;
					}
				}
			break;
			
			case 10:
				system("cls");
				printf("Listagem comum:\n\n");
				listar(&principal);
				printf("\n\n");
				system("pause");
			break;
			
			case 11:
				system("cls");
				printf("Listagem crescente:\n\n");
				listar_crescente(&principal);
				printf("\n\n");
				system("pause");
			break;
			
			case 12:
				system("cls");
				printf("Listagem decrescente:\n\n");
				listar_decrescente(&principal);
				printf("\n\n");
				system("pause");
			break;
			
			case 13:
				system("cls");
				printf("Finalizado.\n\n");
				menu = 0;
			break;
			
			default:
				system("cls");
				printf("Escolha invalida.\n\n");
				system("pause");
			break;
		}
	}
	
	system("pause");
	return 0;
}
