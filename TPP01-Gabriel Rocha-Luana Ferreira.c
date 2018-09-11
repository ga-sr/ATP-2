#include <stdio.h>          //TTP01 :SISTEMA PARA MANIPULA��O POLINOMIAL
#include <stdlib.h>
#define MAX1 20      //maximo de grau
#include <locale.h>  //para o compilador ler acentos
#include <math.h>




int Leitura_Grau_Polinomio(void);
void Associando_Valores_Array(float *ptr,int Dim);
void Alocar_Polinomio (float *ptr, float x,int y);
void zerando_vetores (float *ptr,int dim);
void Imprimir_polinomio ( float *ptr,int Dim);
int Menu (void);
void Soma_Polinomio(float *ptr ,float *ptr2,float *ptr3,int dim1,int dim2);
void Multiplicacao_Polinomio(float *ptr,float *ptr2,float *ptr3,int dim1,int dim2);
float Calculo_Polinomio_x ( float *ptr, int Dim );
void Multiplicar_Polinomio_Const_K (float *ptr,int Dim,float *ptr2);
void Derivar_Polinomio (float *ptr,int Dim,float *ptr2);
void Integrar_Polinomio (float *ptr,int Dim,float *ptr2);


int Leitura_Grau_Polinomio(void) {
	int dim, continua;
	do {
		continua = 0;
		printf("\n\nInsira o  maior grau do polin�mio  (Entre 1 e 20): ");
		scanf("%d",&dim);

		if ( (dim <= 0) || (dim > MAX1) ) continua = 1;
	}
	while ( continua );

	return(dim);
}

void Associando_Valores_Array(float *ptr,int Dim)
{
    int continua,grau=1; // atribuindo um valor a grau para entrar no while embaixo
    float coef;
    zerando_vetores(ptr,Dim);

    do      // for�ando o usu�rio a digitar um valor diferente de zero para o maior grau
    {
    	continua=0;
    	printf("\n\nDigite o coeficiente diferente de zero para o grau %d: ",Dim);
    	scanf("%f",&coef);


    	if(coef==0)
    		continua=1;
    	else
    		Alocar_Polinomio(ptr,coef,Dim);

    }while(continua);


    while(grau !=0)
    {
    	printf("\n\nDigite o coeficiente e o grau separados por espa�o: ");
    	scanf("%f %d",&coef,&grau);

    	Alocar_Polinomio(ptr,coef,grau);
    }

    return;
}

void Alocar_Polinomio (float *ptr, float coef,int Dim)
{
	*(ptr+Dim)+=coef;
	return ;
}

void zerando_vetores (float *ptr,int dim)
{
	int i;

	for(i=0;i<=dim;i++)
		*(ptr+i)=0;

	return;

}

void Imprimir_polinomio ( float *ptr,int Dim)
{
	for(Dim;Dim>=1;Dim--)
	{

		if(*(ptr+Dim)!=0 )
			printf("(%.2f x^%d) + ", *(ptr+Dim),Dim);

	}
	if( Dim==0 )
		printf("(%.2f)", *(ptr+Dim));

	return;
}

int Menu (void)
{
	int op;

	printf("\n\n                 MENU\n\n");
	printf("[1] - Somar Polin�mios.\n\n");
	printf("[2] - Multiplicar Polin�mios.\n\n");
	printf("[3] - Dividir Polin�mios.\n\n");
	printf("[4] - Calcular o Polin�mio num ponto x espec�fico.\n\n");
	printf("[5] - Multiplicar o polin�mio por uma constante K.\n\n");
	printf("[6] - Derivar um polin�mio.\n\n");
	printf("[7] - Integrar um polin�mio.\n\n");
	printf("[8] - Determinar o grau e o n�mero de termos do polin�mio.\n\n");
	scanf("%d",&op);

	return(op);
}

void Soma_Polinomio(float *ptr ,float *ptr2,float *ptr3,int dim1,int dim2)
{
	int i;

        if(dim1<=dim2)      //se o primeiro vetor � menor que o segundo
        {

        	zerando_vetores(ptr3,dim1);
        	for(i=0;i<=dim1;i++)
                *(ptr3+i)= *(ptr+i) + *(ptr2+i);    // percorremos ele inteiro fazendo a soma com a outro vetor

            for(i;i<=dim2;i++)      // quando esse vetor menor acaba,atribuimos as posi��es restantes do maior vetor para o vetor soma
            	*(ptr3+i)= *(ptr2+i);
        }

        else
        {
        	zerando_vetores(ptr3,dim2);
        	for(i=0;i<=dim2;i++)
                *(ptr3+i)= *(ptr+i) + *(ptr2+i);    // mesmo procedimento, por�m aqui dim1 > dim2

            for(i;i<=dim1;i++)   // preencher o restante do vetor
            	*(ptr3+i)= *(ptr+i);
        }

        return;
    }

    void Multiplicacao_Polinomio(float *ptr,float *ptr2,float *ptr3,int dim1,int dim2)
    {
    int Dim_final=dim1 + dim2, aux; //Dim final= dimens�o do vetor multiplicado

    for(Dim_final;Dim_final >=0;Dim_final--)
    	*(ptr3+Dim_final)=0;

    aux=dim2;       // guardando valor inicial de dim2

    for(dim1;dim1>=0;dim1--)
    {
    	if(*ptr+dim1!=0)
    		for(dim2=aux;dim2>=0;dim2--)
    			*(ptr3+dim1+dim2)+= *(ptr+dim1) * *(ptr2+dim2);

            dim2=aux;   //recuperando valor original de dim2
        }
        return;
    }

    void Divisao_Polinomio(float *ptr,float *ptr2,float *ptr3,int dim1,int dim2)
    {
    	int aux;

    	for(dim2;dim2>=0;dim2--)
    	{
    		for(dim1;dim1>=0;dim1--)
            *(ptr3+dim1-dim2)= *(ptr+dim1) / *(ptr2+dim2);  // criando o primeiro elemento do quociente
    }
}

float Calculo_Polinomio_x ( float *ptr, int Dim )  // c�lculo de um polin�mio num ponto x espec�fico
{
	int i=0;
	float ponto,soma=0.0;

	printf("\n\nDigite o ponto (x) espec�fico para o c�lculo do polin�mio:");
	scanf("%f",&ponto);

	for(i=0;i<=Dim;i++)
		soma=soma + pow(ponto,i) * ptr[i] ;

    return (soma);      // retornando o valor total da opera��o
}

void Multiplicar_Polinomio_Const_K (float *ptr,int Dim,float *ptr2)   //case 5
{
	float K;

	zerando_vetores(ptr2,Dim);
	printf("\n\nDigite a constante K para multiplicar o polin�mio: ");
	scanf("%f",&K);

	for(Dim;Dim>=0;Dim--)
	{
        *(ptr2+Dim)= *(ptr+Dim) *K;     //multiplicando cada elemento por uma constante K
    }

    return;
}

void Derivar_Polinomio (float *ptr,int Dim,float *ptr2)
{
	int i;

	zerando_vetores(ptr2,Dim);

	for(Dim;Dim>=0;Dim--)
	{
        if( Dim !=0)  // evitando fazer a opera��o em valores nulos
        	*(ptr2+Dim-1)= Dim *  *(ptr+Dim);

        else
        	*(ptr2+Dim)= *(ptr+Dim+1);
    }

    return;
}

void Integrar_Polinomio (float *ptr,int Dim,float *ptr2)        // integral de x^n = x^(n+1)/n+1  + c
{
	zerando_vetores(ptr2,Dim);

	for(Dim;Dim>=0;Dim--)
		*(ptr2+Dim+1)= *(ptr+Dim)/(Dim + 1);

	return;
}

int main()
{
    int n1,n2,n3,opcao,alternativa,continua=1; // vari�veis auxiliares
    float poli1[MAX1],poli2[MAX1],poli3[MAX1],poli_final[MAX1];
    setlocale (LC_ALL,"Portuguese");

    printf("      TTP01 - Sistema de manipula��o de polin�mios");

    printf("\n\n\n\nINSTRU��ES:     Primeiro digite o maior grau de seu polin�mio.");
    printf("\n\n    Depois digite o coeficiente real para esse respectivo grau.");
    printf("\n\n    Ent�o ap�s esse procedimento,digite um valor para o coeficiente real, aperte espa�o e digite o grau correspondente a esse coeficiente real.");
    printf("\n\n    Lembrando que a inser��o p�ra quando voc� digita zero na posi��o do grau.");
    printf("\n\n    Ex: Para o polin�mio 3x^2 + 5,digito 2 para o maior grau, 3 para o coeficiente real associado a esse maior grau, e 5 0 para o coeficiente 5 na posi��o zero.");
    printf("\n\n    Repita o mesmo procedimento para os outros dois polin�mios.\n\n");
    printf("-------------------------------------------------------------------------------\n\n\n");
    system("pause");
    system("cls");

    printf("\n\nPolin�mio 1:");
    n1=Leitura_Grau_Polinomio();
    Associando_Valores_Array(poli1,n1);
    printf("\n\n");
    Imprimir_polinomio(poli1,n1);

    printf("\n\n Polin�mio 2:");
    n2=Leitura_Grau_Polinomio();
    Associando_Valores_Array(poli2,n2);
    printf("\n\n");
    Imprimir_polinomio(poli2,n2);

    printf("\n\n Polin�mio 3:");
    n3=Leitura_Grau_Polinomio();
    Associando_Valores_Array(poli3,n3);
    printf("\n\n");
    Imprimir_polinomio(poli3,n3);

    printf("\n\n");
    system("pause");
    system("cls");

    while(continua)
    {

    	opcao=Menu();

    	system("cls");

    	printf("\n\n Polin�mio 1:");
    	printf("\n\n");
    	Imprimir_polinomio(poli1,n1);
    	printf("\n\n Polin�mio 2:");
    	printf("\n\n");
    	Imprimir_polinomio(poli2,n2);
    	printf("\n\n Polin�mio 3:");
    	printf("\n\n");
    	Imprimir_polinomio(poli3,n3);

    	switch(opcao)
    	{
            case 1:     // soma polin�mio

            printf("\n\n[1] - Se deseja somar o polin�mio 1 com o 2.");
            printf("\n\n[2] - Se deseja somar o polin�mio 1 com o 3.");
            printf("\n\n[3] - Se deseja somar o polin�mio 2 com o 3.");
            printf("\n\n[4] - Se deseja somar o polin�mio 1 com ele mesmo.");
            printf("\n\n[5] - Se deseja somar o polin�mio 2 com ele mesmo.");
            printf("\n\n[6] - Se deseja somar o polin�mio 3 com ele mesmo.\n");
            scanf("%d",&alternativa);


                if(alternativa==1)// 1 com 2
                {
                	Soma_Polinomio(poli1,poli2,poli_final,n1,n2);
                	if(n1<=n2)
                	{
                		printf("\n\n");
                		Imprimir_polinomio(poli_final,n2);
                	}

                	else
                	{
                		printf("\n\n");
                		Imprimir_polinomio(poli_final,n1);
                	}
                }

                if(alternativa==2)   // 1 com 3
                {
                	Soma_Polinomio(poli1,poli3,poli_final,n1,n3);
                	if(n1<=n3)
                	{
                		printf("\n\n");
                		Imprimir_polinomio(poli_final,n3);
                	}

                	else
                	{
                		printf("\n\n");
                		Imprimir_polinomio(poli_final,n1);
                	}
                }

                if(alternativa==3)   // 2 com 3
                {
                	Soma_Polinomio(poli2,poli3,poli_final,n2,n3);
                	if(n2<=n3)
                	{
                		printf("\n\n");
                		Imprimir_polinomio(poli_final,n3);
                	}

                	else
                	{
                		printf("\n\n");
                		Imprimir_polinomio(poli_final,n2);
                	}
                }

                if(alternativa==4)   // 1 com 1
                {
                	Soma_Polinomio(poli1,poli1,poli_final,n1,n1);

                	printf("\n\n");
                	Imprimir_polinomio(poli_final,n1);
                }

                if(alternativa==5)   // 2 com 2
                {
                	Soma_Polinomio(poli2,poli2,poli_final,n2,n2);

                	printf("\n\n");
                	Imprimir_polinomio(poli_final,n2);
                }

                if(alternativa==6)   // 3 com 3
                {
                	Soma_Polinomio(poli3,poli3,poli_final,n3,n3);

                	printf("\n\n");
                	Imprimir_polinomio(poli_final,n3);
                }


                break;

            case 2:     // multiplicar o polin�mio

            printf("\n\n[1] - Se deseja multiplicar o polin�mio 1 com o 2.");
            printf("\n\n[2] - Se deseja multiplicar o polin�mio 1 com o 3.");
            printf("\n\n[3] - Se deseja multiplicar o polin�mio 2 com o 3.");
            printf("\n\n[4] - Se deseja multiplicar o polin�mio 1 com ele mesmo.");
            printf("\n\n[5] - Se deseja multiplicar o polin�mio 2 com ele mesmo.");
            printf("\n\n[6] - Se deseja multiplicar o polin�mio 3 com ele mesmo.\n");
            scanf("%d",&alternativa);

                if(alternativa==1)   // 1 com 2
                {
                	Multiplicacao_Polinomio(poli1,poli2,poli_final,n1,n2);
                	printf("\n\n");
                	Imprimir_polinomio(poli_final,n1+n2);
                }

                if(alternativa==2)   // 1 com 3
                {
                	Multiplicacao_Polinomio(poli1,poli3,poli_final,n1,n3);
                	printf("\n\n");
                	Imprimir_polinomio(poli_final,n1+n3);
                }

                if(alternativa==3)   // 2 com 3
                {
                	Multiplicacao_Polinomio(poli2,poli3,poli_final,n2,n3);
                	printf("\n\n");
                	Imprimir_polinomio(poli_final,n2+n3);
                }

                if(alternativa==4)   // 1 com 1
                {
                	Multiplicacao_Polinomio(poli1,poli1,poli_final,n1,n1);
                	printf("\n\n");
                	Imprimir_polinomio(poli_final,n1+n1);
                }

                if(alternativa==5)   // 2 com 2
                {
                	Multiplicacao_Polinomio(poli2,poli2,poli_final,n2,n2);
                	printf("\n\n");
                	Imprimir_polinomio(poli_final,n2+n2);
                }

                if(alternativa==6)   // 3 com 3
                {
                	Multiplicacao_Polinomio(poli3,poli3,poli_final,n3,n3);
                	printf("\n\n");
                	Imprimir_polinomio(poli_final,n3+n3);
                }

                break;

                case 3:

                printf("\n\n Esta opera��o n�o foi implementada!!!");

                break;


            case 4: // c�lculo num ponto x espec�fico

            printf("\n\nQual polin�mio voc� quer calcular num ponto x espec�fico? 1,2 ou 3? ");
            scanf("%d",&alternativa);

            if(alternativa==1)
            	printf("\n\nO valor do polin�mio num ponto  espec�fico �: %.2f",Calculo_Polinomio_x(poli1,n1) );

            if(alternativa==2)
            	printf("\n\nO valor do polin�mio num ponto  espec�fico �: %.2f",Calculo_Polinomio_x(poli2,n2) );

            if(alternativa==3)
            	printf("\n\nO valor do polin�mio num ponto  espec�fico �: %.2f",Calculo_Polinomio_x(poli3,n3) );

            break;

            case 5: // multiplica��o por uma constante K

            printf("\n\nQual polin�mio voc� quer multiplicar por uma constante K? 1,2 ou 3? ");
            scanf("%d",&alternativa);

            if(alternativa==1)
            {
            	Multiplicar_Polinomio_Const_K(poli1,n1,poli_final);
            	printf("\nO polin�mio multiplicado pela constante escolhida �:\n\n");
            	Imprimir_polinomio(poli_final,n1);
            }

            if(alternativa==2)
            {
            	Multiplicar_Polinomio_Const_K(poli2,n2,poli_final);
            	printf("\nO polin�mio multiplicado pela constante escolhida �:\n\n");
            	Imprimir_polinomio(poli_final,n2);
            }

            if(alternativa==3)
            {
            	Multiplicar_Polinomio_Const_K(poli3,n3,poli_final);
            	printf("\nO polin�mio multiplicado pela constante escolhida �:\n\n");
            	Imprimir_polinomio(poli_final,n3);
            }

            break;

            case 6: // derivar polin�mios

            printf("\n\n Qual polin�mio voc� deseja derivar? 1,2 ou 3? ");
            scanf("%d",&alternativa);

            if(alternativa==1)
            {
            	Derivar_Polinomio(poli1,n1,poli_final);
            	printf("\nO polin�mio derivado �:\n");
            	printf("\n");
            	Imprimir_polinomio(poli_final,n1-1);

            }

            if(alternativa==2)
            {
            	Derivar_Polinomio(poli2,n2,poli_final);
            	printf("\nO polin�mio derivado �:\n");
            	printf("\n");
                    Imprimir_polinomio(poli_final,n2-1);    // pois o maior grau na derivada ser� n2-1

                }

                if(alternativa==3)
                {
                	Derivar_Polinomio(poli3,n3,poli_final);
                	printf("\nO polin�mio derivado �:\n");
                	printf("\n");
                	Imprimir_polinomio(poli_final,n3-1);

                }

                break;

            case 7:     // integrar polin�mio

            printf("\n\nQual polin�mio voc� deseja integrar?  1,2 ou 3? ");
            scanf("%d",&alternativa);

            if(alternativa==1)
            {
            	Integrar_Polinomio(poli1,n1,poli_final);
            	printf("\nO polin�mio integrado �:\n\n");
            	Imprimir_polinomio(poli_final,n1+1);
            	printf(" + constante c");

            }

            if(alternativa==2)
            {
            	Integrar_Polinomio(poli2,n2,poli_final);
            	printf("\nO polin�mio integrado �:\n\n");
            	Imprimir_polinomio(poli_final,n2+1);
            	printf(" + constante c");
            }

            if(alternativa==3)
            {
            	Integrar_Polinomio(poli3,n3,poli_final);
            	printf("\nO polin�mio integrado �:\n\n");
            	Imprimir_polinomio(poli_final,n3+1);
            	printf(" + constante c");
            }

            break;

            case 8: // quantidade de termos

            printf("\n\nQual polin�mio voc� quer saber o grau?\n 1,2 ou 3? ");
            scanf("%d",&alternativa);

            if(alternativa==1)
            {
            	printf("\n\nO grau do polin�mio � %d",n1);
            }

            if(alternativa==2)
            {
            	printf("\n\nO grau do polin�mio � %d",n2);
            }

            if(alternativa==3)
            {
            	printf("\n\nO grau do polin�mio � %d",n3);
            }

            break;

        }// switch

        printf("\n\n\n Digite 1 para executar o programa novamente ou zero para sair");
        printf("\n\n(Se voc� escolher a op��o 1,os polin�mios digitados continuam salvos.): ");
        scanf("%d",&continua);
        system("cls");
    }//while

    printf("\n\nObrigado por utilizar o programa!!!\n\n");
    printf("Feito por: Gabriel Rocha e Luana Ferreira.\n\n\n");

    system("pause");
}
