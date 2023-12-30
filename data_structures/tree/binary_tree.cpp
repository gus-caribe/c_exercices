#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct No {
	int item;
	No *left;
	No *right;
};

typedef struct Arvore {
	No *raiz;
};

void criarArvore(Arvore *ab) {
	ab->raiz = NULL;
}

void criarRaiz(Arvore *ab, int valor) {
	ab->raiz = (No*)malloc(sizeof *ab->raiz);
	
	if(ab->raiz != NULL) {
		ab->raiz->item = valor;
		ab->raiz->left = NULL;
		ab->raiz->right = NULL;
	}
}

int criarNo(Arvore *tree, int valor) {
	No *aux = tree->raiz;
	No *novo = (No*)malloc(sizeof *novo);
	
	novo->item = valor;
	novo->left = NULL;
	novo->right = NULL;
	
	while(1) {
		if(valor > aux->item) {
			if(aux->right == NULL) {
				aux->right = novo;
				return 0;
				break;
			}
			else {
				aux = aux->right;
			}
		}
		else if(valor == aux->item) {
			return -1;
			break;
		}
		else {
			if(aux->left == NULL) {
				aux->left = novo;
				return 0;
				break;
			}
			else {
				aux = aux->left;
			}
		}
	}
}

void destruirNo(No *destroy) {
	if(destroy != NULL) {
		destruirNo(destroy->left);
		destruirNo(destroy->right);
		free(destroy);
	}
}

void destruirArvore(Arvore *destroy) {
	destruirNo(destroy->raiz);
	destroy->raiz = NULL;
}

void preOrdemRun(No *no) {
	if(no != NULL) {
		printf("%i\t", no->item);
		preOrdemRun(no->left);
		preOrdemRun(no->right);
	}
}

void preOrdem(Arvore *tree) {
	preOrdemRun(tree->raiz);
}

void emOrdemRun(No *no) {
	if(no != NULL) {
		emOrdemRun(no->left);
		printf("%i\t", no->item);
		emOrdemRun(no->right);
	}
}

void emOrdem(Arvore *tree) {
	emOrdemRun(tree->raiz);
}

void posOrdemRun(No *no) {
	if(no != NULL) {
		posOrdemRun(no->left);
		posOrdemRun(no->right);
		printf("%i\t", no->item);
	}
}

void posOrdem(Arvore *tree) {
	posOrdemRun(tree->raiz);
}

void menu(Arvore *tree) {
	int op, numero;
	
	do {
		system("cls");
		
		printf("MENU:\n\n");
		printf("1 - Inserir No;\n");
		printf("2 - Pre-ordem;\n");
		printf("3 - Em-ordem;\n");
		printf("4 - Pos-ordem;\n");
		printf("5 - Resetar Arvore;\n\n");
		printf("0 - SAIR;\n\n");
		printf("Opcao: ");
		scanf("%i", &op);
		
		switch(op) {
			default:
				system("cls");
				printf("Opcao invalida.\n\n");
				system("pause");
				break;
				
			case 0://sair
				destruirArvore(tree);
				system("cls");
				printf("Sistema Finalizado.\n\n");
				system("pause");
				break;
				
			case 1://inserir nó
				system("cls");
				printf("INSERIR NO:\n\n");
				printf("Digite o numero a ser inserido: ");
				scanf("%i", &numero);
				
				if(tree->raiz == NULL) {
					criarRaiz(tree, numero);
					
					system("cls");
					printf("Sucesso.\n\n");
					system("pause");
				}
				else {
					if(criarNo(tree, numero) == 0) {
						system("cls");
						printf("Sucesso.\n\n");
						system("pause");
					}
					else {
						system("cls");
						printf("O numero ja esta registrado.\n\n");
						system("pause");
					}
				}
				break;
				
			case 2://pre-ordem
				system("cls");
				printf("PRE-ORDEM:\n\n");
				preOrdem(tree);
				printf("\n\n");
				system("pause");
				break;
				
			case 3://em-ordem
				system("cls");
				printf("EM-ORDEM:\n\n");
				emOrdem(tree);
				printf("\n\n");
				system("pause");
				break;
				
			case 4://pos-ordem
				system("cls");
				printf("POS-ORDEM:\n\n");
				posOrdem(tree);
				printf("\n\n");
				system("pause");
				break;
				
			case 5:
				destruirArvore(tree);
				
				system("cls");
				printf("Sucesso.\n\n");
				system("pause");
				break;
		}
	}while(op);
}





int main(void) {
	Arvore *arvore = (Arvore*)malloc(sizeof *arvore);
	
	criarArvore(arvore);
	
	menu(arvore);
	
	return 0;
}
