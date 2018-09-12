#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX1 5000

typedef enum boleano {falso, verdadeiro} Boleano;

// Não esqueçam de comentar todas funções que fizerem, a exemplo do que já fiz em
// exercícios anteriores. Façam isto como exercício.


/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
short Busca_Linear(int *Ptr, int Dim, int Chave) {
int i=0;   // indice para percorrer o array

 for (; i < Dim; i++)
      if ( *(Ptr+i) == Chave ) return(1);  // elemento localizado

 return(0);  // elemento nao pertence ao array
}  // Busca_Linear

/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
int Leitura_Dimensao_Array(void) {
int dim, continua;
  do
   {
     continua = 0;
     printf("Insira o numero de componentes do array (>= 1 && <= 100000): ");
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX1) ) continua = 1;
   }
  while ( continua );

return(dim);
} // Leitura_Dimensao_Array

/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
void Associa_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array
time_t t;

  srand((unsigned) time(&t));
  for ( ; i < Dim; i++) *(Ptr+i) = rand();

return;
} // Associando_Valores_Array

/*--------------------------------------------------------*/
/*--------------------------------------------------------*/
void Imprimindo_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array

 for (; i < Dim; i++)
   printf("\n [%d] = %d ",i,*(Ptr+i));
} // Associando_Valores_Array

/*--------------------------------------------------------*/
/*--------------------------------------------------------*/

int Maior_Elemento_Vetor(int *Ptr, int Dim) {
int i = 1, maior1;

  maior1 = *(Ptr);  // inicializando maior1 com o primeiro elemento do vetor

  for ( ; i < Dim; i++)	// a partir do segundo elemento - posição 1
    if ( *(Ptr+i) > maior1 )
	   maior1 = *(Ptr+i);

return(maior1);
}   // Maior_Elemento_Vetor
/*--------------------------------------------------------*/
/*--------------------------------------------------------*/

int main(void) {

int 	i,              // indice para percorrer o array
	    n1,             // tamanho real do array vetor1
	    n2,             // tamanho real do array vetor2
	    n3,             // tamanho real do array vetor3
	    vetor1[MAX1];   // array vetor1 para armazenar os elementos
        //vetor2[2*MAX1],   // array vetor2 para armazenar os elementos
        //vetor3[3*MAX1],   // array vetor3 para armazenar os elementos
  int    	maior1,         // maior elemento do vetor
      	chave;          // chave a ser pesquisada


  n1 = Leitura_Dimensao_Array();
  Associa_Valores_Array(vetor1,n1);

  //n2 = Leitura_Dimensao_Array();
  //Associa_Valores_Array(vetor2,n2);

 // n3 = Leitura_Dimensao_Array();
  //Associa_Valores_Array(vetor3,n3);

// imprimindo os valores associados aos diferentes arrays

  printf("\n\n VETOR1\n");
  //Imprimindo_Valores_Array(vetor1,n1);

  printf("\n\n VETOR2\n");
  //Imprimindo_Valores_Array(vetor2,n2);

  printf("\n\n VETOR3\n");
  //Imprimindo_Valores_Array(vetor3,n3);


// Encontrando o maior elemento de vários vetores com a mesma função

 //printf("\n\nO maior elemento do vetor1 e o valor: << %d >> ", Maior_Elemento_Vetor(vetor1,n1) );
 //printf("\n\nO maior elemento do vetor2 e o valor: << %d >> ", Maior_Elemento_Vetor(vetor2,n2) );
 //printf("\n\nO maior elemento do vetor3 e o valor: << %d >> ", Maior_Elemento_Vetor(vetor3,n3) );

   chave = rand();
  //chave = vetor1[0];
  // O valor associado a chave também poderia ser lido


  if ( Busca_Linear(&vetor1[0],n1,chave) )
  printf("\n\n O elemento %d PERTENCE ao vetor1.\n\n ",chave);
  else printf("\n\n O elemento %d NAO PERTENCE ao vetor1.\n\n",chave);


  system("Pause");
  return(0);
}

//EXERCÍCIOS: Refazer todos os exercícios da LISTA envolvendo sequencias;
// Elaborar uma função genérica para introduzir uma sequenca de valores a partir do teclado
// e associá-la a qualquer array.
