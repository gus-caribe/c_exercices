//Listar numeros de 1 a 20

#include<stdio.h>
#include<stdlib.h>

void numeros (int numero)
{
	printf("%i  ", numero);
	
	if(numero < 20)
	numeros(numero+1);
}

main()
{
	printf("Os numeros sao: ");
	numeros(1);
	
	printf("\n\n");
	
	system("pause");
}