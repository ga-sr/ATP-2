#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX 10000

int Leitura_Dimensao_Array(void);
void Associa_Valores_Array(int *Ptr, int Dim);
void Imprimindo_Valores_Array(int *Ptr, int Dim);
void Troca(int *S,int Ind1, int Ind2);

int main (void){
int V1[MAX],n,i,j;

    n = Leitura_Dimensao_Array();
    Associa_Valores_Array(V1,n);
    Imprimindo_Valores_Array(V1,n);

    for (i=0;i<n;i++){
        for(j=i;j<n;j++)
            if(V1[i]==0)
                Troca(V1,j,i);
    }

    puts("\n\n");
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
  for ( ; i < Dim; i++) *(Ptr+i) = rand()%2;

return;
} // Associando_Valores_Array

void Imprimindo_Valores_Array(int *Ptr, int Dim) {
int i = 0;   // indice para percorrer o array

 for (; i < Dim; i++)
   printf("\n [%d] = %d ",i,*(Ptr+i));
} // Associando_Valores_Array

void Troca(int *S,int Ind1, int Ind2) {
int aux;
  aux =  *(S +Ind1);
  *(S+Ind1) =  *(S+Ind2);
  *(S+Ind2) = aux;
} // Troca
