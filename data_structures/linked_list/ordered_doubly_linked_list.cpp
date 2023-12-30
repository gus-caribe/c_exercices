//Gustavo Cardoso Ribeiro
//833.588

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//N�
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

//Retorna endere�o NULL para a refer�ncia do primeiro n�
No *inicializaNo() {
	No *l = NULL;
	
	return l;
}

//Retorna endere�o do novo n� para a refer�ncia do primeiro n�
No *insere(No *list, int valor, Control *c) {
	No *novo = (No*)malloc(sizeof *novo);
	No *aux, *aux1;
	int ocorreu = 0;
	
	novo->item = valor;
	
	if(list == NULL || list->item >= valor) {
		novo->ant = NULL;
		novo->prox = list;
		
		list = novo;
		
		c->primeiro = list;
	}
	else {
		aux = list;
		aux1 = list->prox;
		
		while(aux1 != NULL) {
			if(valor <= aux1->item && valor > aux->item) {
				aux->prox = novo;
				novo->ant = aux;
				novo->prox = aux1;
				aux1->ant = novo;
				
				ocorreu = 1;
				
				break;
			}
			
			aux = aux->prox;
			aux1 = aux1->prox;
		}
		
		if(!ocorreu) {
			aux->prox = novo;
			novo->ant = aux;
			novo->prox = NULL;
			
			c->ultimo = novo;	
		}
	}
	
	c->qnt++;
	
	return list;
}

//Retorna o endere�o do segundo n� para a refer�ncia do primeiro n�
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
	
	//repete at� chegar no "terra" (NULL)
	while(aux != NULL) {
		printf("Item %i: %i\n", count++, aux->item);
		
		aux = aux->prox;
	}
	
	printf("\n");
}

//Imprime o menu e chama as fun��es
void menu(No *list, Control *c) {
	int opcao, numero;
	
	do {//enquanto a op��o escolhida n�o for a 0
		system("cls");
		
		printf("MENU:\n\n");
		printf("1 - Inserir;\n");
		printf("2 - Remover do inicio;\n");
		printf("3 - Remover do final;\n");
		printf("4 - Listar;\n");
		printf("0 - SAIR;\n\n");
		printf("Opcao: ");
		scanf("%i", &opcao);
		
		switch(opcao) {
			default://op��o inv�lida
				system("cls");
				printf("OPCAO INVALIDA.\n\n");
				system("pause");
			break;
			
			case 0://caso a op��o seja "Sair"
			break;
			
			case 1://Inserir
				system("cls");
				printf("Que numero deseja inserir?: ");
				scanf("%i", &numero);
				
				list = insere(list, numero, c);
				
				system("cls");
				printf("SUCESSO.\n\n");
				system("pause");
			break;
			
			case 2://Remove no in�cio
				if(list != NULL) {//se houver algum n� para remover
					list = removeInicio(list, c);
					
					system("cls");
					printf("SUCESSO.\n\n");
					system("pause");
				}
				else {//se n�o houver nenhum n�
					system("cls");
					printf("NAO E POSSIVEL REMOVER MAIS.\n\n");
					system("pause");
				}
			break;
			
			case 3://Remove no fim
				if(list != NULL) {//se houver algum n� para remover
					list = removeFim(list, c);
					
					system("cls");
					printf("SUCESSO.\n\n");
					system("pause");
				}
				else {//se n�o houver nenhum n�
					system("cls");
					printf("NAO E POSSIVEL REMOVER MAIS.\n\n");
					system("pause");
				}
			break;
			
			case 4://Imrime n�s
				system("cls");
				imprime(list);
				system("pause");
			break;
		}
	}while(opcao);
}





int main() {
	No *lista;//criando refer�ncia para o primeiro n�
	Control *controle;//criando referencia para o primeiro, ultimo e quantidade
	
	lista = inicializaNo();
	controle = inicializaControl();
	
	//chama o menu
	menu(lista, controle);
	
	//caso o usu�rio pessione 0 para sair
	system("cls");
	printf("SISTEMA FINALIZADO.\n\n");
	system("pause");
	
	return 0;
}
