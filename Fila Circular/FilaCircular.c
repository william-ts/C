#include <stdio.h>
#include <stdlib.h>

/*Definição dos Dados*/

//Const
    #define FILA_TAM 5

//Type
    typedef int tipoDADO;

    typedef struct{
        tipoDADO Dados[FILA_TAM];
        int Inicio, Fim;
        int Qtde;
    }tipoFILA;



/*Definição das Rotinas*/

void Fila_Inicializa(tipoFILA *F)
{
    F->Inicio = 0;
    F->Fim = -1;
    F->Qtde = 0;
}

int Fila_Insere(tipoFILA *F, tipoDADO D)
{

    if( F->Qtde == FILA_TAM )
    {
        return(0); //Fila_Insere = False;
    }
    else
    {
        if( F->Fim == FILA_TAM-1 )  //{ Faz índice circular }
        {
            F->Fim = 0;
        }
        else
        {
            F->Fim = F->Fim+1;
        }

        F->Dados[F->Fim] = D;
        F->Qtde = F->Qtde+1;

        return(1);  //Fila_Insere = True;
    }

}


void Fila_Exibe(tipoFILA F)
{
	int cont, i;

	if(F.Qtde != 0)
	{
		i = F.Inicio;
		for(cont=1; cont <= F.Qtde; cont++)
		{
			printf("%d ", F.Dados[i]);

			if(i == FILA_TAM-1)   //{ Faz índice circular }
			{
				i=0;
			}
			else
			{
				i++;
			}
		}
	}

}


int Fila_Retira(tipoFILA *F, tipoDADO *D)
{

    if(F->Qtde == 0)
    {
        return(0); //Fila_Retira = False
    }
    else
    {
        *D = F->Dados[F->Inicio];

        if(F->Inicio == FILA_TAM-1)	//{ Faz índice circular }
        {
            F->Inicio=0;
        }
        else
        {
            F->Inicio = F->Inicio+1;
        }

        F->Qtde = F->Qtde-1;

        return(1); //Fila_Retira = True
    }
}







int main()
{

//Var
    int op;
    tipoFILA Fila;
    tipoDADO Dado;



    Fila_Inicializa(&Fila);

    while(1)
    {
        printf("Fila: ");
        Fila_Exibe(Fila);



        printf("\n\n");
        printf("1 - Inserir dado na fila\n");
        printf("2 - Retirar dado na fila\n");
        printf("3 - Mostrar fila\n");			//Desabilitado
        printf("0 - Sair\n\n");
        printf("Opcao: ");
        scanf("%d",&op);
        printf("\n");

        switch(op)
        {
            case 1:
                Dado = rand() % 100;
                if( Fila_Insere(&Fila,Dado) == 0)
                    printf("Fila cheia!");
                else
                    printf("Inserido: %d\n",Dado);
                break;

            case 2:
                if( Fila_Retira(&Fila,&Dado) == 0)
                    printf("Fila vazia!");
                else
                    printf("Retirado: %d\n",Dado);
                break;

            //case 3:
                //Fila_Exibe(Fila);
                //break;

            case 0:
                printf("0 - Saindo...\n");
                exit(0);
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
        getch();
        system("cls");
    }






return 0;
}
