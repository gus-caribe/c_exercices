#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct Mensagem
{
    bool bitInfo[8];
    bool bitHamming[4];
} Mensagem;



int main()
{
    Mensagem remetente, destinatario;
    int i, j, k, bitEstragar, soma, ref, contraRef, referencia[12], resposta;
    bool estouro, matriz[4][12];
    char referenciaChar;

    //MONTA A MATRIZ
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == 0)
                matriz[j][i] = 0;
            else
                matriz[j][i] = matriz[j][i - 1];
        }

        for (j = 3; j >= 0; j--)
        {
            if (j == 3 || estouro)
            {
                estouro = matriz[j][i];

                matriz[j][i] = !matriz[j][i];
            }
        }
    }

    printf("Informe uma mensagem de 8 bits a ser enviada. \nMensagem: ");

    for (i = 0; i < 8; i++)
    {
        resposta = getche();

        if ((resposta - '0') == 0) {
            remetente.bitInfo[i] = false;
            destinatario.bitInfo[i] = false;
        }
        else if ((resposta - '0') == 1) {
            remetente.bitInfo[i] = true;
            destinatario.bitInfo[i] = true;
        }
    }

    printf("\n\n");

    ref = 7;

    //MONTA A REFERENCIA
    for (i = 0; i < 12; i++)
    {
        if (i == 0 || i == 1 || i == 3 || i == 7)
        {
            referencia[i] = -1;
        }
        else
        {
            if (remetente.bitInfo[ref--]) {
                referencia[i] = 1;
            }
            else {
                referencia[i] = 0;
            }
        }
    }

    //PRINTA A MATRIZ COM A REFERENCIA
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%i", matriz[j][i]);
        }

        switch (referencia[i])
        {
        case 1:
            referenciaChar = '1';
            break;
        case 0:
            referenciaChar = '0';
            break;
        case -1:
            referenciaChar = ' ';
            break;
        }

        printf("   %c\n", referenciaChar);
    }

    soma = 0;
    contraRef = 3;

    //CALCULA O HAMMING
    for (i = 0; i < 8; i++)
    {
        if (i == 0 || i == 1 || i == 3 || i == 7)
        {
            for (j = i; j < 12; j++)
            {
                if (j != 0 && j != 1 && j != 3 && j != 7 && matriz[contraRef][j] && referencia[j] == 1)
                {
                    soma++;
                }
            }

            remetente.bitHamming[contraRef--] = soma % 2 != 0;

            soma = 0;
        }
    }

    printf("\n\n");

    //PRINTA O HAMMING
    printf("Hamming: ");

    for (i = 0; i < 4; i++)
    {
        printf("%i", remetente.bitHamming[i]);
    }

    printf(".\n\n");

    printf("Escolha um dos bits para %cestragar%c: ", '"', '"');
    scanf("%i", &bitEstragar);

    //ESTRAGA O BIT
    destinatario.bitInfo[bitEstragar - 1] = !destinatario.bitInfo[bitEstragar - 1];

    ref = 7;

    //CALCULA A NOVA REFERENCIA
    for (i = 0; i < 12; i++)
    {
        if (i == 0 || i == 1 || i == 3 || i == 7)
        {
            referencia[i] = -1;
        }
        else
        {
            referencia[i] = destinatario.bitInfo[ref--];
        }
    }

    printf("\n\n");

    //PRINTA A MATRIZ COM A REFERENCIA
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%i", matriz[j][i]);
        }

        switch (referencia[i])
        {
        case 1:
            referenciaChar = '1';
            break;
        case 0:
            referenciaChar = '0';
            break;
        case -1:
            referenciaChar = ' ';
            break;
        }

        printf("   %c\n", referenciaChar);
    }

    soma = 0;
    contraRef = 3;

    //CALCULA O HAMMING
    for (i = 0; i < 8; i++)
    {
        if (i == 0 || i == 1 || i == 3 || i == 7)
        {
            for (j = i; j < 12; j++)
            {
                if (j != 0 && j != 1 && j != 3 && j != 7 && matriz[contraRef][j] && referencia[j] == 1)
                {
                    soma++;
                }
            }

            destinatario.bitHamming[contraRef--] = soma % 2 != 0;

            soma = 0;
        }
    }

    printf("\n\n");

    //PRINTA O HAMMING
    printf("Hamming: ");

    for (i = 0; i < 4; i++)
    {
        printf("%i", destinatario.bitHamming[i]);
    }

    soma = 0;

    for (i = 0; i < 4; i++)
    {
        if (remetente.bitHamming[i] ^ destinatario.bitHamming[i])
        {
            switch (i)
            {
            case 0:
                soma += 8;
                break;

            case 1:
                soma += 4;
                break;

            case 2:
                soma += 2;
                break;

            case 3:
                soma++;
                break;
            }
        }
    }

    resposta = 0;

    for (i = 12; i >= soma; i--) {
        if (i != 0 && i != 1 && i != 3 && i != 7) resposta++;
    }

    printf(".\n\n");

    printf("O bit estragado foi o de numero %i.", resposta);

    destinatario.bitInfo[resposta - 1] = !destinatario.bitInfo[resposta - 1];

    printf("\n\n\n\n");

    printf("Mensagem consertada: ");

    for (i = 0; i < 8; i++)
    {
        printf("%i", destinatario.bitInfo[i]);
    }

    printf(".\n\n");

    system("pause");

    return 0;
}
