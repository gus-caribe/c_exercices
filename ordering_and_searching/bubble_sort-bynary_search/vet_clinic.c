#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int quantidadeAnimais;
int quantidadeProcedimentos;
int memoria;

//tem que usar bubble sort pra ordenar
//tem que usar busca binária pra ver se existe
//tem que ver se existe pra excluir
//listar com recursão
//incluir a opção de listar od dois juntos
//explicar por que usei malloc
//explicar por que modifiquei a busca binária pra retornar a posição
//não tinha a opção "buscar"
//tive que colocar o registro do animal no procedimento
//não deu pra entender o que tinha que listar


typedef struct {
	int registro;
	char raca[21];
	char cor[21];
	int idade;
	char apelido[21];
	char nomeDono[41];
} tAnimal;

typedef struct {
	int codigo;
	char descricao[101];
	char data[11];
	float valor;
	int registroAnimal;
} tProcedimento;




tProcedimento *procedimento;
tAnimal *animal;




void inicializa() {
	procedimento = (tProcedimento*)malloc(memoria*sizeof(procedimento));
	animal = (tAnimal*)malloc(memoria*sizeof(animal));
	quantidadeAnimais = -1;
	quantidadeProcedimentos = -1;
}

void ordenarAnimal() {
	int i, j;
	tAnimal auxAnimal;
	
	for(i=0; i<=quantidadeAnimais; i++) {
		for(j=0; j<quantidadeAnimais-i; j++) {
			if(animal[j].registro > animal[j+1].registro) {
				auxAnimal = animal[j];
				animal[j] = animal[j+1];
				animal[j+1] = auxAnimal;
			}
		}
	}
}

void ordenarProcedimento() {
	int i, j;
	tProcedimento auxProcedimento;
	
	for(i=0; i<=quantidadeProcedimentos; i++) {
		for(j=0; j<quantidadeProcedimentos-i; j++) {
			if(procedimento[j].codigo > procedimento[j+1].codigo) {
				auxProcedimento = procedimento[j];
				procedimento[j] = procedimento[j+1];
				procedimento[j+1] = auxProcedimento;
			}
		}
	}
}

void listarAnimais(int i) {
	if(quantidadeAnimais == -1) {
		printf("- Nao ha nenhum animal cadastrado.\n\n");
	}
	else {
		if(i <= quantidadeAnimais) {
			printf("Registro: %i", animal[i].registro);
			printf("\nRaca: %s", animal[i].raca);
			printf("Cor: %s", animal[i].cor);
			printf("Idade: %i", animal[i].idade);
			printf("\nApelido: %s", animal[i].apelido);
			printf("Nome do dono: %s\n\n\n", animal[i].nomeDono);
			
			listarAnimais(++i);
		}
	}
}

void listarProcedimentos(int i) {
	if(quantidadeProcedimentos == -1) {
		printf("- Nao ha nenhum procedimento incluido.\n\n");
	}
	else {
		if(i <= quantidadeProcedimentos) {
			printf("Codigo: %i", procedimento[i].codigo);
			printf("\nDescricao: %s", procedimento[i].descricao);
			printf("Data: %s", procedimento[i].data);
			printf("Valor: %.2f", procedimento[i].valor);
			printf("\nRegistro do animal: %i\n\n\n", procedimento[i].registroAnimal);
			
			listarProcedimentos(++i);
		}
	}
}

void listarProcedimentoPorAnimal(int valor) {
	int i, existe=0;
	
	for(i=0; i<=quantidadeProcedimentos; i++) {
		if(procedimento[i].registroAnimal == valor) {
			printf("Codigo: %i", procedimento[i].codigo);
			printf("\nDescricao: %s", procedimento[i].descricao);
			printf("Data: %s", procedimento[i].data);
			printf("Valor: %.2f", procedimento[i].valor);
			printf("\nRegistro do animal: %i\n\n\n", procedimento[i].registroAnimal);
			
			existe = 1;
		}
	}
	
	if(existe == 0) {
		printf("\n\n-Nao ha nenhum procedimento para esse animal.\n\n");
	}
}

void incluirProcedimento(tProcedimento valor) {
	procedimento[++quantidadeProcedimentos] = valor;
}

void cadastrarAnimal() {
	int registro;
	
	quantidadeAnimais++;
	
	while(1) {
		system("cls");
		printf("CADASTRAR ANIMAL");
		printf("\n\nRegistro: ");
		scanf("%i", &registro);
		
		if(animalExiste(registro) != -1) {
			system("cls");
			printf("Esse animal ja esta cadastrado.");
			fflush(stdin);
			printf("\n\nPressione qualquer tecla para ver a lista de animais cadastrados.");
			getche();
			system("cls");
			printf("LISTAR ANIMAIS\n\n\n");
			listarAnimais(0);
			system("pause");
		}
		else {
			animal[quantidadeAnimais].registro = registro;
			break;
		}
	}
	
	fflush(stdin);
	printf("Raca: ");
	fgets(animal[quantidadeAnimais].raca, sizeof(animal[quantidadeAnimais].raca), stdin);
	fflush(stdin);
	printf("Cor: ");
	fgets(animal[quantidadeAnimais].cor, sizeof(animal[quantidadeAnimais].cor), stdin);
	printf("Idade: ");
	scanf("%i", &animal[quantidadeAnimais].idade);
	fflush(stdin);
	printf("Apelido: ");
	fgets(animal[quantidadeAnimais].apelido, sizeof(animal[quantidadeAnimais].apelido), stdin);
	fflush(stdin);
	printf("Nome do dono: ");
	fgets(animal[quantidadeAnimais].nomeDono, sizeof(animal[quantidadeAnimais].nomeDono), stdin);
}

tProcedimento getProcedimento() {
	tProcedimento thisProcedimento;
	
	while(1) {
		system("cls");
		printf("CADASTRAR PROCEDIMENTO");
		printf("\n\nCodigo: ");
		scanf("%i", &thisProcedimento.codigo);
		
		if(procedimentoExiste(thisProcedimento.codigo) != -1) {
			system("cls");
			printf("Esse procedimento ja esta incluido.");
			fflush(stdin);
			printf("\n\nPressione qualquer tecla para ver a lista de procedimentos incluidos.");
			getche();
			system("cls");
			printf("LISTAR PROCEDIMENTOS\n\n\n");
			listarProcedimentos(0);
			system("pause");
		}
		else 
			break;
	}
	
	fflush(stdin);
	printf("Descricao: ");
	fgets(thisProcedimento.descricao, sizeof(thisProcedimento.descricao), stdin);
	fflush(stdin);
	printf("Data (DD/MM/AAAA): ");
	fgets(thisProcedimento.data, sizeof(thisProcedimento.data), stdin);
	printf("Valor: R$");
	scanf("%f", &thisProcedimento.valor);
	
	while(1) {
		system("cls");
		printf("CADASTRAR PROCEDIMENTO");
		printf("\n\nCodigo: %i", thisProcedimento.codigo);
		printf("\nDescricao: %s", thisProcedimento.descricao);
		printf("Data (DD/MM/AAAA): %s", thisProcedimento.data);
		printf("Valor: R$%.2f", thisProcedimento.valor);
		printf("\nRegistro do animal: ");
		scanf("%i", &thisProcedimento.registroAnimal);
		
		if(procedimentoExiste(thisProcedimento.codigo) == -1) {
			system("cls");
			printf("Esse animal nao esta cadastrado.");
			printf("\n\nPressione qualquer tecla para ver a lista de animais cadastrados.");
			getche();
			system("cls");
			printf("LISTAR ANIMAIS\n\n\n");
			listarAnimais(0);
			system("pause");
		}
		else 
			break;
	}
	
	return thisProcedimento;
}

void removerAnimal(int posicao) {
	int i;
	
	for(i=posicao; i < quantidadeAnimais; i++) //começando da posicão, pega o da frente e passa pra trás
		animal[i] = animal[i+1];
	
	fgets(animal[quantidadeAnimais].apelido, sizeof(animal[quantidadeAnimais].apelido), 0);
	fgets(animal[quantidadeAnimais].cor, sizeof(animal[quantidadeAnimais].cor), 0);
	animal[quantidadeAnimais].idade = 0;
	fgets(animal[quantidadeAnimais].nomeDono, sizeof(animal[quantidadeAnimais].nomeDono), 0);
	fgets(animal[quantidadeAnimais].raca, sizeof(animal[quantidadeAnimais].raca), 0);
	animal[quantidadeAnimais].registro = 0;
	
	quantidadeAnimais--;
}

int removerProcedimento(int posicao) {
	int i;
	
		for(i=posicao-1; i < quantidadeProcedimentos; i++) //começando da posicão, pega o da frente e passa pra trás
			procedimento[i] = procedimento[i+1];
}

int animalExiste(int valor) {
	int menor=0, meio, maior=quantidadeAnimais, posicao;
	
	if(quantidadeAnimais == -1) { //se não tiver nenhum cadastrado ainda
		return -1;
	}
	else { //se não
		while(1) { //busca binária
			meio = (menor+maior)/2;
			
			if(animal[meio].registro == valor) { //se for o do meio
				posicao = meio;
				break;
			}
			else { //se não
				if(meio == maior || meio == menor) { //se o indice do meio for irredutível ou inexpansível
					posicao = -1;
					break;
				}
				else { //se não, realoque o meio
					if(animal[meio].registro > valor) {
						maior = --meio;
					}
					else {
						menor = ++meio;
					}
				}
			}
		}
		
		return posicao;
	}
}

int procedimentoExiste(int valor) {
	int menor=0, meio, maior=quantidadeProcedimentos, posicao;
	
	if(quantidadeProcedimentos == -1) { //se não tiver nenhum incluído ainda
		return -1;//não existe
	}
	else { //se não
		while(1) { //busca binária
			meio = (menor+maior)/2;
			
			if(procedimento[meio].codigo == valor) { //se for o do meio
				posicao = meio;
				break;
			}
			else { //se não
				if(meio == maior || meio == menor) { //se o indice do meio for irredutível ou inexpansível
					posicao = -1;
					break;
				}
				else { //se não, realoque o meio
					if(animal[meio].registro > valor) {
						maior = --meio;
					}
					else {
						menor = ++meio;
					}
				}
			}
		}
		
		return posicao;
	}
}

void acoes(int opcao) {
	int registro, codigo, posicao;
	
	switch(opcao) {
		default:
			system("cls");
			printf("Opcao invalida.\n\n");
			system("pause");
			break;
		
		case 1:
			if(quantidadeAnimais < memoria) {
				cadastrarAnimal(),
				ordenarAnimal();
				system("cls");
				printf("Sucesso.\n\n");
				system("pause");
			}
			else {
				system("cls");
				printf("Memoria cheia.\n\n");
				system("pause");
			}
			break;
			
		case 2:
			if(quantidadeProcedimentos < memoria) {
				if(quantidadeAnimais == -1){
					system("cls");
					printf("Nao ha animais para atrelar ao procedimento.\n\n");
					system("pause");
				}
				else {
					incluirProcedimento(getProcedimento());
					ordenarProcedimento();
					system("cls");
					printf("Sucesso.\n\n");
					system("pause");
				}
			}
			else {
				system("cls");
				printf("Memoria cheia.\n\n");
				system("pause");
			}
			break;
			
		case 3:
			system("cls");
			printf("LISTAR ANIMAIS\n\n\n");
			listarAnimais(0);
			system("pause");
			break;
			
		case 4:
			system("cls");
			printf("LISTAR PROCEDIMENTOS\n\n\n");
			listarProcedimentos(0);
			system("pause");
			break;
			
		case 5:
			system("cls");
			printf("LISTAR ANIMAIS E PROCEDIMENTOS\n\n");
			printf("ANIMAIS\n\n\n");
			listarAnimais(0);
			printf("PROCEDIMENTOS\n\n\n");
			listarProcedimentos(0);
			system("pause");
			break;
			
		case 6:
			system("cls");
			printf("Insira o registro do animal: ");
			scanf("%i", &registro);
			system("cls");
			printf("LISTAR PROCEDIMENTOS PARA O ANIMAL DE REGISTRO: %i\n", registro);
			listarProcedimentoPorAnimal(registro);
			system("pause");
			break;
			
		case 7:
			if(quantidadeProcedimentos == -1) {
				system("cls");
				printf("Nao ha procedimentos para remover.\n\n");
				system("pause");
			}
			else {
				system("cls");
				printf("Insira o codigo do procedimento: ");
				scanf("%i", &codigo);
			
				posicao = procedimentoExiste(codigo);
			
				if(posicao == -1) {
					system("cls");
					printf("Codigo invalido.\n\n");
					system("pause");
				}
				else {
					removerProcedimento(posicao);
					system("cls");
					printf("Sucesso.\n\n");
					system("pause");
				}
			}
			break;
			
		case 8:
			if(quantidadeAnimais == -1) {
				system("cls");
				printf("Nao ha animais para remover.\n\n");
				system("pause");
			}
			else {
				system("cls");
				printf("Insira o registro do animal: ");
				scanf("%i", &registro);
			
				posicao = animalExiste(registro);
			
				if(posicao == -1) {
					system("cls");
					printf("Registro invalido.\n\n");
					system("pause");
				}
				else {
					removerAnimal(posicao);
					system("cls");
					printf("Sucesso.\n\n");
					system("pause");
				}
			}
			break;
	}
}

int menu() {
	int opcao;
	
	system("cls");
	printf("MENU");
	printf("\n\n1- Cadastrar animal");
	printf("\n2- Incluir procedimento");
	printf("\n3- Listar animais");
	printf("\n4- Listar procedimentos");
	printf("\n5- Listar animais e procedimentos juntos");
	printf("\n6- Listar procedimentos por animal");
	printf("\n7- Remover procedimento");
	printf("\n8- Remover animal");
	printf("\n\n9- SAIR");
	printf("\n\nOpcao: ");
	scanf("%i", &opcao);
	
	if(opcao != 9) {
		acoes(opcao);
		return 1;
	}
	else
		return 0;
}



int main() {
	system("cls");
	printf("Quantos animais e procedimentos voce deseja colocar como limite no sistema?: ");
	scanf("%i", &memoria);
	
	inicializa();
	memoria--;
	
	system("cls");
	printf("Sucesso.\n\n");
	system("pause");
	
	while(menu());
	
	system("cls");
	printf("Finalizado\n\n");
	system("pause");
	
	return 0;
}
