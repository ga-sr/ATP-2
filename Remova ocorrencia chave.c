#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX 10

int BuscaVetor(int* vetor, int key, int n);
int Leitura_Dimensao_Array(void);
void Associa_Valores_Array(int *Ptr, int Dim);
void Imprimindo_Valores_Array(int *Ptr, int Dim);

int main(void){
 int i, j = 0,
 vetor[MAX],vetor2[MAX],
 n,chave;

 n = Leitura_Dimensao_Array();
 Associa_Valores_Array(vetor,n);
 Imprimindo_Valores_Array(vetor,n);
 puts("\n\n");

 printf("Digite uma chave: ");
 scanf("%d",&chave);

 for(i=0;i<n;i++){
    if(vetor[i]!= chave)
    {
        vetor2[j] = vetor[i];
        j++;
    }
 }
 Imprimindo_Valores_Array(vetor2, j);
}

int Leitura_Dimensao_Array(void) {
int dim, continua;
  do
   {
     continua = 0;
     printf("Insira o numero de componentes do array (>= 1 && <= 10): ");
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX) ) continua = 1;
   }
  while ( continua );

return(dim);
} // Leitura_Dimensao_Array

void Associa_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array
time_t t;

  srand((unsigned) time(&t));
  for ( ; i < Dim; i++) *(Ptr+i) = rand()%10+1;

return;
} // Associando_Valores_Array

void Imprimindo_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array

 for (; i < Dim; i++)
   printf("\n [%d] = %d ",i,*(Ptr+i));
} // Associando_Valores_Array
