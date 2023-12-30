//Gustavo Cardoso Ribeiro
//833.588

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Nó
typedef struct No{
	int item;
	No *prox;
};

//Retorna endereço NULL para a referência do primeiro nó
No *inicializa() {
	No *l = NULL;
	
	return l;
}

//Retorna endereço do novo nó para a referência do primeiro nó
No *insere(No *list, int valor) {
	No *novo = (No*)malloc(sizeof *novo);
	No *aux, *aux1;
	int ocorreu = 0;
	
	novo->item = valor;
	
	if(list == NULL || list->item >= valor) {
		novo->prox = list;//ponteiro dentro de ponteiro
		list = novo;
	}
	else {
		aux = list;
		aux1 = list->prox;
		
		while(aux1 != NULL) {
			if(valor <= aux1->item && valor > aux->item) {
				aux->prox = novo;
				novo->prox = aux1;
				
				ocorreu = 1;
				
				break;
			}
			
			aux = aux->prox;
			aux1 = aux1->prox;
		}
		
		if(!ocorreu) {
			aux->prox = novo;
			novo->prox = NULL;	
		}
	}
	
	return list;
}

//Retorna o endereço do segundo nó para a referência do primeiro nó
No *removeInicio(No *list) {
	No *aux = list->prox;
	
	//limpa e libera o, até então, primeiro nó
	free(list);
	
	return aux;
}

//Remove no fim
No *removeFim(No *list) {
	No *aux = list->prox;
	No *aux2 = list;
	
	if(aux == NULL) {//se só tiver um nó
		free(list);
		return NULL;
	}
	else {//se tiver mais de um nó
		//encontra o último e o penúltimo nó
		while(aux->prox != NULL) {
			aux2 = aux;
			aux = aux->prox;
		}
		
		//limpa e libera o último
		free(aux);
		//aponta o penúltimo, agora último, para NULL
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
	
	//repete até chegar no "terra" (NULL)
	while(aux != NULL) {
		printf("Item %i: %i\n", count++, aux->item);
		
		aux = aux->prox;
	}
	
	printf("\n");
	
	//system("pause");
}

//Imprime o menu e chama as funções
void menu(No *list) {
	int opcao, numero;
	
	do {//enquanto a opção escolhida não for a 0
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
			default://opção inválida
				system("cls");
				printf("OPCAO INVALIDA.\n\n");
				system("pause");
			break;
			
			case 0://caso a opção seja "Sair"
			break;
			
			case 1://Inserir
				system("cls");
				printf("Que numero deseja inserir?: ");
				scanf("%i", &numero);
				
				list = insere(list, numero);
				
				system("cls");
				printf("SUCESSO.\n\n");
				system("pause");
			break;
			
			case 2://Remove no início
				if(list != NULL) {//se houver algum nó para remover
					list = removeInicio(list);
					
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
			
			case 3://Remove no fim
				if(list != NULL) {//se houver algum nó para remover
					list = removeFim(list);
					
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
			
			case 4://Imrime nós
				system("cls");
				imprime(list);
				system("pause");
			break;
		}
	}while(opcao);
}





int main() {
	No *lista;//criando referência para o primeiro nó
	
	lista = inicializa();
	
	//chama o menu
	menu(lista);
	
	//caso o usuário pessione 0 para sair
	system("cls");
	printf("SISTEMA FINALIZADO.\n\n");
	system("pause");
	
	return 0;
}
