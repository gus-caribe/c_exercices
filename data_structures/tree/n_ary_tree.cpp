//Gustavo Cardoso Ribeiro
//833.588

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Tno {
	Tno *pai;
	int item;
	Tno *irmao_prox;
	Tno *filho;
} No;

No *inicializa(int valor) {
	No *novo = (No*)malloc(sizeof *novo);
	
	novo->filho = NULL;
	novo->pai = NULL;
	novo->irmao_prox = NULL;
	novo->item = valor;
	
	return novo;
}

void imprime(No *node, No *reference) {
	No *ref = node;
	int sons = 0, i;
	
	if(node == reference)
		printf("-(%i)\n", node->item);
	else
		printf("-%i\n", node->item);
	
	do {
		if(ref->filho != NULL) {//se o referencial tiver filho
			sons++;
			
			ref = ref->filho;
			
			for(i=0; i<sons; i++) {
				printf("\t");
			}
			
			if(ref == reference)
				printf("-(%i)\n", ref->item);
			else
				printf("-%i\n", ref->item);
		}
		else if(ref->irmao_prox != NULL) {//se o referencial tiver irmão
			ref = ref->irmao_prox;
			
			for(i=0; i<sons; i++) {
				printf("\t");
			}
			
			if(ref == reference)
				printf("-(%i)\n", ref->item);
			else
				printf("-%i\n", ref->item);
		}
		else {//se o referencial não tiver irmão nem filho
			sons--;
			
			while(ref != node) {//enquanto o referencial não for o primeiro nó
				ref = ref->pai;
				
				if(ref->irmao_prox != NULL) {//se o referencial tiver irmão
					ref = ref->irmao_prox;
					
					for(i=0; i<sons; i++) {
						printf("\t");
					}
					
					if(ref == reference)
						printf("-(%i)\n", ref->item);
					else
						printf("-%i\n", ref->item);
					
					break;
				}
			}
		}
	}while(ref != node);
}

No *insereFilho(No *IsItATree, int valor) {
	No *novo = (No*)malloc(sizeof *novo);
	No *aux;
	
	novo->filho = NULL;
	novo->pai = IsItATree;
	novo->irmao_prox = NULL;
	novo->item = valor;
	
	if(IsItATree->filho == NULL) {//se a referencia não tiver nenhum filho
		IsItATree->filho = novo;
	}
	else {//se tiver filho
		aux = IsItATree->filho;
		
		while(aux->irmao_prox != NULL) {
			aux = aux->irmao_prox;
		}
		
		aux->irmao_prox = novo;
	}
	
	return IsItATree;
}

No *insereIrmao(No *IsItATree, int valor) {
	No *novo = (No*)malloc(sizeof *novo);
	No *aux;
	
	novo->filho = NULL;
	novo->pai = IsItATree->pai;
	novo->irmao_prox = NULL;
	novo->item = valor;
	
	if(IsItATree->irmao_prox == NULL) {
		IsItATree->irmao_prox = novo;
	}
	else {
		aux = IsItATree;
		
		while(aux->irmao_prox != NULL) {
			aux = aux->irmao_prox;
		}
		
		aux->irmao_prox = novo;
	}
	
	return IsItATree;
}

void menu(No *node) {
	int opcao, opt, numero;
	No *aux;
	
	do {//enquanto a opção escolhida não for a 0
		system("cls");
		
		printf("MENU:\n\n");
		imprime(node, NULL);
		printf("\n\n1 - Adicionar Filho;\n");
		printf("2 - Adicionar Irmao;\n");
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
			
			case 1://Adicionar filho
				aux = node;
			
				do {
					system("cls");
					printf("ADICIONAR FILHO:\n\n");
					imprime(node, aux);
					printf("\n\n1- Escolher o selecionado;\n");
					printf("2- Avancar para o irmao seguinte;\n");
					printf("3- Avancar para o filho seguinte;\n\n");
					printf("0- CANCELAR;\n\n");
					printf("Opcao: ");
					scanf("%i", &opt);
					
					switch(opt) {
						default:
							system("cls");
							printf("OPCAO INVALIDA.\n\n");
							system("pause");
							break;
							
						case 0:
							break;
							
						case 1:
							system("cls");
							printf("Insira um valor para o filho: ");
							scanf("%i", &numero);
							
							aux = insereFilho(aux, numero);
							
							system("cls");
							printf("SUCESSO.\n\n");
							system("pause");
							
							opt = 0;
							break;
							
						case 2:
							if(aux->irmao_prox == NULL) {
								system("cls");
								printf("NAO E POSSIVEL.\n\n");
								system("pause");
							}
							else {
								aux = aux->irmao_prox;
							}
							break;
							
						case 3:
							if(aux->filho == NULL) {
								system("cls");
								printf("NAO E POSSIVEL.\n\n");
								system("pause");
							}
							else {
								aux = aux->filho;
							}
							break;
					}
				} while(opt);
				break;
			
			case 2://Adicionar Irmão
				aux = node;
			
				do {
					system("cls");
					printf("ADICIONAR IRMAO:\n\n");
					imprime(node, aux);
					printf("\n\n1- Escolher o selecionado;\n");
					printf("2- Passar para o irmao seguinte;\n");
					printf("3- Passar para o filho seguinte;\n\n");
					printf("0- CANCELAR;\n\n");
					scanf("%i", &opt);
					
					switch(opt) {
						default:
							system("cls");
							printf("OPCAO INVALIDA.\n\n");
							system("pause");
							break;
							
						case 0:
							break;
							
						case 1:
							system("cls");
							printf("Insira um valor para o irmao: ");
							scanf("%i", &numero);
							
							aux = insereIrmao(aux, numero);
							
							system("cls");
							printf("SUCESSO.\n\n");
							system("pause");
							
							opt = 0;
							break;
							
						case 2:
							if(aux->irmao_prox == NULL) {
								system("cls");
								printf("NAO E POSSIVEL.\n\n");
								system("pause");
							}
							else {
								aux = aux->irmao_prox;
							}
							break;
							
						case 3:
							if(aux->filho == NULL) {
								system("cls");
								printf("NAO E POSSIVEL.\n\n");
								system("pause");
							}
							else {
								aux = aux->filho;
							}
							break;
					}
				} while(opt);
				break;
		}
	}while(opcao);
}

int main() {
	No *tree;//criando referência para o primeiro nó
	int valor;
	
	printf("Escolha um numero inteiro para comecar: ");
	scanf("%i", &valor);
	
	tree = inicializa(valor);
	
	//chama o menu
	menu(tree);
	
	//caso o usuário pessione 0 para sair
	system("cls");
	printf("SISTEMA FINALIZADO.\n\n");
	system("pause");
	
	return 0;
}

