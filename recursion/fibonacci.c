#include<stdio.h>
#include<stdlib.h>

int limite;

void fibonacci (int ultimo, int penultimo)
{
	limite--;
	
	printf("%i  ", ultimo + penultimo);
	
	if(limite > 0)
	fibonacci(ultimo + penultimo, ultimo);
}

main()
{
	printf("Insira o maximo: ");
	scanf("%i", &limite);
	
	printf("\nOs numeros sao: ");
	
	fibonacci(0, 1);
	
	printf("\n\n");
	
	system("pause");
}

