//Gustavo Cardoso Ribeiro
//833.588

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//N�
typedef struct No{
	int item;
	No *prox;
};

//Retorna endere�o NULL para a refer�ncia do primeiro n�
No *inicializa() {
	No *l = NULL;
	
	return l;
}

//Retorna endere�o do novo n� para a refer�ncia do primeiro n�
No *insereInicio(No *list, int valor) {
	No *novo = (No*)malloc(sizeof *novo);
	
	novo->item = valor;
	//Aponta o endere�o que antes era o primeiro
	novo->prox = list;
	
	return novo;
}

//Insere no fim
No *insereFim(No *list, int valor) {
	No *aux = list;
	No *novo = (No*)malloc(sizeof *novo);
	
	//novo n� recebe o valor e aponta para NULL
	novo->item = valor;
	novo->prox = NULL;
	
	if(list == NULL) {
		list = novo;
	}
	else {
		//encontra o �ltimo n�
		while(aux->prox != NULL) {
			aux = aux->prox;
		}
		
		//faz o �ltimo n� apontar para o novo n�
		aux->prox = novo;
	}
	
	system("cls");
	printf("SUCESSO.\n\n");
	system("pause");
	
	return list;
}

//Retorna o endere�o do segundo n� para a refer�ncia do primeiro n�
No *removeInicio(No *list) {
	No *aux = list->prox;
	
	//limpa e libera o, at� ent�o, primeiro n�
	free(list);
	
	return aux;
}

//Remove no fim
No *removeFim(No *list) {
	No *aux = list->prox;
	No *aux2 = list;
	
	if(aux == NULL) {//se s� tiver um n�
		free(list);
		return NULL;
	}
	else {//se tiver mais de um n�
		//encontra o �ltimo e o pen�ltimo n�
		while(aux->prox != NULL) {
			aux2 = aux;
			aux = aux->prox;
		}
		
		//limpa e libera o �ltimo
		free(aux);
		//aponta o pen�ltimo, agora �ltimo, para NULL
		aux2->prox = NULL;
		
		return list;
	}
}

//Imprime
void imprime(No *list) {
	No *aux = list;
	int count=1;
	
	//system("cls");
	
	printf("IMPRIMIR:\n\n");
	
	//repete at� chegar no "terra" (NULL)
	while(aux != NULL) {
		printf("Item %i: %i\n", count++, aux->item);
		
		aux = aux->prox;
	}
	
	printf("\n");
	
	//system("pause");
}

//Retorna a refer�ncia do in�cio da lista j� ordenada
No *ordenar(No *list) {
	No *aInicio, *inicio, *aAtual, *atual, *aux;
	
	aAtual = list;
	atual = list->prox;
	
	while(atual != NULL) {//coloca o menor n�mero na primeira casa
		if(list->item > atual->item) {
			aAtual->prox = atual->prox;
			atual->prox = list;
			list = atual;
		}
		
		aAtual = atual;
		atual = atual->prox;
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
					aAtual->prox = atual->prox;
					inicio->prox = atual->prox;
					atual->prox = inicio;
					inicio = aInicio->prox;
					atual = inicio->prox;
				}
				else {
					aInicio->prox = atual;
					aAtual->prox = inicio;
					aux = inicio->prox;
					inicio->prox = atual->prox;
					atual->prox = aux;
					inicio = aInicio->prox;
					atual = aAtual->prox;
				}
			}
			
			aAtual = atual;
			atual = atual->prox;
		}
		
		aInicio = inicio;
		inicio = inicio->prox;
	}
	
	return list;
}

//Imprime o menu e chama as fun��es
void menu(No *list) {
	int opcao, numero;
	
	do {//enquanto a op��o escolhida n�o for a 0
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
			default://op��o inv�lida
				system("cls");
				printf("OPCAO INVALIDA.\n\n");
				system("pause");
			break;
			
			case 0://caso a op��o seja "Sair"
			break;
			
			case 1://Ordenar
				if(list == NULL){
					system("cls");
					printf("Nao ha o que ordenar.\n\n");
					system("pause");
				}
				else {
					list = ordenar(list);
					
					system("cls");
					printf("SUCESSO.\n\n");
					system("pause");
				}
			break;
			
			case 2://Inserir no in�cio
				system("cls");
				printf("Que numero deseja inserir?: ");
				scanf("%i", &numero);
				
				list = insereInicio(list, numero);
				
				system("cls");
				printf("SUCESSO.\n\n");
				system("pause");
			break;
			
			case 3://Insere no fim
				system("cls");
				printf("Que numero deseja inserir?: ");
				scanf("%i", &numero);
				
				list = insereFim(list, numero);
			break;
			
			case 4://Remove no in�cio
				if(list != NULL) {//se houver algum n� para remover
					list = removeInicio(list);
					
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
			
			case 5://Remove no fim
				if(list != NULL) {//se houver algum n� para remover
					list = removeFim(list);
					
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
			
			case 6://Imrime n�s
				system("cls");
				imprime(list);
				system("pause");
			break;
		}
	}while(opcao);
}





int main() {
	No *lista;//criando refer�ncia para o primeiro n�
	
	lista = inicializa();
	
	//chama o menu
	menu(lista);
	
	//caso o usu�rio pessione 0 para sair
	system("cls");
	printf("SISTEMA FINALIZADO.\n\n");
	system("pause");
	
	return 0;
}
