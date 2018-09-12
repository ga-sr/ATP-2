#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX 10

int Leitura_Dimensao_Array(void);
void Associa_Valores_Array(int *Ptr, int Dim);
void Imprimindo_Valores_Array(int *Ptr, int Dim);
void Troca(int *S,int Ind1, int Ind2);

int main (void){
int V1[MAX],n,i,j,liminf,limsup;

    n = Leitura_Dimensao_Array();
    Associa_Valores_Array(V1,n);
    Imprimindo_Valores_Array(V1,n);
    puts("\n\n");

    printf("Digite o limite inferior: ");
    scanf("%d",&liminf);
    puts("\n");
    printf("Digite o limite superior: ");
    scanf("%d",&limsup);

    i = liminf;
    j = limsup;

    for (;i<j;i++){
        Troca(V1,i,j);
        j--;
    }

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

void Troca(int *S,int Ind1, int Ind2) {
int aux;
  aux =  *(S +Ind1);
  *(S+Ind1) =  *(S+Ind2);
  *(S+Ind2) = aux;
} // Troca
