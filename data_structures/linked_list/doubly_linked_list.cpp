//Gustavo Cardoso Ribeiro
//833.588

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Nó
typedef struct Tno{
	Tno *ant;
	int item;
	Tno *prox;
} No;

//Controle das pontas
typedef struct Tcontrol {
	No *primeiro;
	int qnt;
	No *ultimo;
} Control;

//retorna uma struct de controle preenchida
Control *inicializaControl() {
	Control *c = (Control*)malloc(sizeof *c);
	
	c->qnt = 0;
	c->primeiro = NULL;
	c->ultimo = NULL;
	
	return c;
}

//Retorna endereço NULL para a referência do primeiro nó
No *inicializaNo() {
	No *l = NULL;
	
	return l;
}

//Retorna endereço do novo nó para a referência do primeiro nó
No *insereInicio(No *list, int valor, Control *c) {
	
	No *novo = (No*)malloc(sizeof *novo);
	
	novo->item = valor;
	novo->ant = NULL;
	novo->prox = list;
	
	c->qnt++;
	
	c->primeiro = novo;
	
	if(list == NULL)
		c->ultimo = novo;
	else
		list->ant = novo;
	
	return novo;
}

//Insere no fim
No *insereFim(No *list, int valor, Control *c) {
	No *novo = (No*)malloc(sizeof *novo);
	No *aux = c->ultimo;
	
	novo->item = valor;
	novo->ant = aux;
	novo->prox = NULL;
	
	if(list == NULL)
		list = novo;
	else
		aux->prox = novo;
		
	c->primeiro = list;
	c->qnt++;
	c->ultimo = novo;
	
	system("cls");
	printf("SUCESSO.\n\n");
	system("pause");
	
	return list;
}

//Retorna o endereço do segundo nó para a referência do primeiro nó
No *removeInicio(No *list, Control *c) {
	No *aux;
	
	if(list->prox == NULL) {
		aux = NULL;
		
		free(list);
		
		c->primeiro = NULL;
		c->qnt = 0;
		c->ultimo = NULL;
	}
	else {
		aux = list->prox;
		aux->ant = NULL;
		
		free(list);
		
		c->primeiro = aux;
		c->qnt--;
	}
	
	return aux;
}

//Remove no fim
No *removeFim(No *list, Control *c) {
	No *aux;
	
	if(list->prox == NULL) {
		
		aux = NULL;
		free(list);
		
		c->primeiro = NULL;
		c->qnt = 0;
		c->ultimo = NULL;
	}
	else {
		aux = c->ultimo;
		aux = aux->ant;
		aux->prox = NULL;
		
		free(c->ultimo);
		
		c->ultimo = aux;
		c->qnt--;
		
		aux = list;
	}
	
	return aux;
}

//Imprime
void imprime(No *list) {
	No *aux = list;
	int count=1;
	
	printf("IMPRIMIR:\n\n");
	
	//repete até chegar no "terra" (NULL)
	while(aux != NULL) {
		printf("Item %i: %i\n", count++, aux->item);
		
		aux = aux->prox;
	}
	
	printf("\n");
}

//Retorna a referência do início da lista já ordenada
No *ordenar(No *list, Control *c) {
	No *aInicio, *inicio, *aAtual, *atual, *aux, *aux1;
	
	aAtual = list;
	atual = list->prox;
	
	while(atual != NULL) {//coloca o menor número na primeira casa
		if(list->item > atual->item) {
			aux = atual->prox;
			list->ant = atual;
			atual->prox = list;
			list = atual;
			list->ant = NULL;
			
			if(aux != NULL) {//isso é o mesmo que nada
				aAtual->prox = aux;
				aux->ant = aAtual;
			}
			else {
				aAtual->prox = NULL;
			}
			
			atual = aux;
		}
		else {
			aAtual = aAtual->prox;
			atual = atual->prox;
		}
	}
	
	aInicio = list;
	inicio = list->prox;
	
	while(inicio != NULL) {//ordena o resto
		aAtual = inicio;
		atual = inicio->prox;
		
		while(atual != NULL) {
			if(inicio->item > atual->item) {
				if(inicio->prox == atual) {
					aInicio->prox = atual;
					atual->ant = aInicio;
					aux = atual->prox;
					atual->prox = inicio;
					inicio->ant = atual;
					
					if(aux != NULL) {
						aux->ant = inicio;
						inicio->prox = aux;
					}
					else
						inicio->prox = NULL;
					
					inicio = atual;
					atual = atual->prox;
					aAtual = inicio;
				}
				else {
					aux = inicio->prox;
					aux1 = atual->prox;
					
					aux->ant = atual;
					atual->prox = aux;
					
					if(aux1 != NULL){
						aux1->ant = inicio;
						inicio->prox = aux1;
					}
					else
						inicio->prox = NULL;
					
					aInicio->prox = atual;
					atual->ant = aInicio;
					aAtual->prox = inicio;
					inicio->ant = aAtual;
					
					inicio = atual;
					atual = aAtual->prox;
				}
			}
			
			aAtual = atual;
			atual = atual->prox;
		}
		
		aInicio = inicio;
		inicio = inicio->prox;
	}
	
	c->primeiro = list;
	c->ultimo = aInicio;
	
	return list;
}

//Imprime o menu e chama as funções
void menu(No *list, Control *c) {
	int opcao, numero;
	
	do {//enquanto a opção escolhida não for a 0
		system("cls");
		
		printf("MENU:\n\n");
		printf("1 - Ordenar;\n");
		printf("2 - Inserir no inicio;\n");
		printf("3 - Inserir no final;\n");
		printf("4 - Remover do inicio;\n");
		printf("5 - Remover do final;\n");
		printf("6 - Listar;\n");
		printf("0 - SAIR;\n\n");
		printf("Opcao: ");
		scanf("%i", &opcao);
		
		switch(opcao) {
			default://opção inválida
				system("cls");
				printf("OPCAO INVALIDA.\n\n");
				system("pause");
			break;
			
			case 0://caso a opção seja "Sair"
			break;
			
			case 1://Ordenar
				if(list == NULL){
					system("cls");
					printf("Nao ha o que ordenar.\n\n");
					system("pause");
				}
				else {
					list = ordenar(list, c);
					
					system("cls");
					printf("SUCESSO.\n\n");
					system("pause");
				}
			break;
			
			case 2://Inserir no início
				system("cls");
				printf("Que numero deseja inserir?: ");
				scanf("%i", &numero);
				
				list = insereInicio(list, numero, c);
				
				system("cls");
				printf("SUCESSO.\n\n");
				system("pause");
			break;
			
			case 3://Insere no fim
				system("cls");
				printf("Que numero deseja inserir?: ");
				scanf("%i", &numero);
				
				list = insereFim(list, numero, c);
			break;
			
			case 4://Remove no início
				if(list != NULL) {//se houver algum nó para remover
					list = removeInicio(list, c);
					
					system("cls");
					printf("SUCESSO.\n\n");
					system("pause");
				}
				else {//se não houver nenhum nó
					system("cls");
					printf("NAO E POSSIVEL REMOVER MAIS.\n\n");
					system("pause");
				}
			break;
			
			case 5://Remove no fim
				if(list != NULL) {//se houver algum nó para remover
					list = removeFim(list, c);
					
					system("cls");
					printf("SUCESSO.\n\n");
					system("pause");
				}
				else {//se não houver nenhum nó
					system("cls");
					printf("NAO E POSSIVEL REMOVER MAIS.\n\n");
					system("pause");
				}
			break;
			
			case 6://Imrime nós
				system("cls");
				imprime(list);
				system("pause");
			break;
		}
	}while(opcao);
}





int main() {
	No *lista;//criando referência para o primeiro nó
	Control *controle;//criando referencia para o primeiro, ultimo e quantidade
	
	lista = inicializaNo();
	controle = inicializaControl();
	
	//chama o menu
	menu(lista, controle);
	
	//caso o usuário pessione 0 para sair
	system("cls");
	printf("SISTEMA FINALIZADO.\n\n");
	system("pause");
	
	return 0;
}
