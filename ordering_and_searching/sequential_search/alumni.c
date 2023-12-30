#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct
{
	char nome[61];
	int ra, faltas;
	float parcial, exame;
} cadastro[30];

int quantidade = 0;

void cadastrar()
{
	system("cls");
	printf("CADASTRO");
	fflush(stdin);
	printf("\n\nInsira o nome do aluno: ");
	fgets(cadastro[quantidade].nome, sizeof(cadastro[quantidade].nome), stdin);
	printf("Insira o RA do aluno: ");
	scanf("%i", &cadastro[quantidade].ra);
	printf("Insira a nota parcial do aluno: ");
	scanf("%f", &cadastro[quantidade].parcial);
	printf("Insira a nota do exame do aluno: ");
	scanf("%f", &cadastro[quantidade].exame);
	printf("Agora, insira o numero de faltas do aluno: ");
	scanf("%i", &cadastro[quantidade].faltas);
	system("cls");
	printf("Cadastro concluido com sucesso!\n\n");
	system("pause");
}

void exibir()
{
	int i;
	float final;
	
	system("cls");
	printf("EXIBIR\n\n");
	
	for (i=0; i<quantidade; i++)
	{
		final = cadastro[i].parcial*0.4+cadastro[i].exame*0.6;
		
		printf("Nome: %s", cadastro[i].nome);
		printf("RA: %i", cadastro[i].ra);
		printf("\nParcial: %.2f", cadastro[i].parcial);
		printf("\nExame: %.2f", cadastro[i].exame);
		printf("\nFinal: %.2f", final);
		printf("\nFaltas: %i", cadastro[i].faltas);
		
		if (final >= 5 && cadastro[i].faltas <= 10)
		printf("\nStatus: A\n\n");
		else
		printf("\nStatus: R\n\n");
	}
	
	system("pause");
}

void buscar()
{
	int i, escolha, posicao;
	float final;
	
	system("cls");
	printf("BUSCAR");
	printf("\n\nInsira o RA do aluno: ");
	scanf("%i", &escolha);
	
	for (i=0; i<quantidade; i++)
	{
		if (cadastro[i].ra == escolha)
		{
			posicao = i;
			i = quantidade;
		}
	}
	
	final = cadastro[posicao].parcial*0.4+cadastro[posicao].exame*0.6;
	
	printf("\nDADOS:");
	printf("\n\nNome: %s", cadastro[posicao].nome);
	printf("RA: %i", cadastro[posicao].ra);
	printf("\nParcial: %.2f", cadastro[posicao].parcial);
	printf("\nExame: %.2f", cadastro[posicao].exame);
	printf("\nFinal: %.2f", final);
	printf("\nFaltas: %i", cadastro[posicao].faltas);
	
	if (final >= 5 && cadastro[posicao].faltas <= 10)
	printf("\nStatus: A\n\n");
	else
	printf("\nStatus: R\n\n");
	
	system("pause");
}

void excluir()
{
	int i, escolha, excluir, posicao;
	float final;
	
	system("cls");
	printf("EXCLUIR");
	printf("\n\nInsira o RA do aluno: ");
	scanf("%i", &escolha);
	
	for (i=0; i<quantidade; i++)
	{
		if (cadastro[i].ra == escolha)
		{
			posicao = i;
			i = quantidade;
		}
	}
	
	final = cadastro[posicao].parcial*0.4+cadastro[posicao].exame*0.6;
	
	printf("\nConfira:");
	printf("\n\nNome: %s", cadastro[posicao].nome);
	printf("RA: %i", cadastro[posicao].ra);
	printf("\nParcial: %.2f", cadastro[posicao].parcial);
	printf("\nExame: %.2f", cadastro[posicao].exame);
	printf("\nFinal: %.2f", final);
	printf("\nFaltas: %i\n\n", cadastro[posicao].faltas);
	
	printf("Certeza que deseja excluir? (1- Sim, 2- Nao): ");
	scanf("%i", &excluir);
	
	if (excluir == 2)
	{
		system("cls");
		printf("Operação cancelada.\n\n");
		system("pause");
	}
	else
	{
		for(i=posicao; i<quantidade-1; i++)
		{
			strcpy(cadastro[i].nome, cadastro[i+1].nome);
			cadastro[i].ra = cadastro[i+1].ra;
			cadastro[i].parcial = cadastro[i+1].parcial;
			cadastro[i].exame = cadastro[i+1].exame;
			cadastro[i].faltas = cadastro[i+1].faltas;
		}
		
		memset(cadastro[quantidade-1].nome, 0, 61);
		cadastro[quantidade-1].ra = 0;
		cadastro[quantidade-1].parcial = 0;
		cadastro[quantidade-1].exame = 0;
		cadastro[quantidade-1].faltas = 0;
		
		quantidade--;
		
		system("cls");
		printf("Cancelado com sucesso!\n\n");
		system("pause");
	}
}

main()
{
	bool finalizar = 0;
	int opcao;
	
	while (finalizar == 0)
	{
		system("cls");
		printf("Escolha uma opcao:");
		printf("\n\n1- Cadastro;");
		printf("\n2- Exibir;");
		printf("\n3- Buscar (pelo RA);");
		printf("\n4- Excluir (pelo RA);");
		printf("\n5- Sair;");
		printf("\n\nOpcao: ");
		scanf("%i", &opcao);
		
		switch (opcao)
		{
			case 1:
				if (quantidade >= 30)
				{
					system("cls");
					printf("Numero maximo atingido.\n\n");
					system("pause");
					finalizar = 0;
				}
				else
				{
					cadastrar();
					quantidade++;
					finalizar = 0;
				}
			break;
			
			case 2:
				exibir();
				finalizar = 0;
			break;
			
			case 3:
				buscar();
				finalizar = 0;
			break;
			
			case 4:
				excluir();
				finalizar = 0;
			break;
			
			case 5:
				system("cls");
				printf("Sistema finalizado.\n\n");
				finalizar = 1;
			break;
		}
	}
	
	system("pause");
}
