#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define MAX 10

int Leitura_Dimensao_Array(void);
void Associa_Valores_Array(int *Ptr, int Dim);
void Imprimindo_Valores_Array(int *Ptr, int Dim);
void rotacionar(int *Ptr, int dim, int k);

int main (void){
int V1[MAX],n,i,k;

    n = Leitura_Dimensao_Array();
    Associa_Valores_Array(V1,n);
    Imprimindo_Valores_Array(V1,n);
    puts("\n\n");

    printf("Digite quantos elementos deseja rotacionar: ");
    scanf("%d",&k);

    rotacionar(V1,n,k);
    Imprimindo_Valores_Array(V1,n);

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
  for ( ; i < Dim; i++) *(Ptr+i) = rand()%10;

return;
} // Associando_Valores_Array

void Imprimindo_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array

 for (; i < Dim; i++)
   printf("\n [%d] = %d ",i,*(Ptr+i));
} // Associando_Valores_Array

void rotacionar(int *Ptr, int dim, int k){
int aux,i;
    while(k>0){
        aux = Ptr[dim-1];
        for(i=dim-1;i>0;i--)
            Ptr[i] = Ptr[i-1];
        Ptr[0] = aux;
        k--;
    }
}
