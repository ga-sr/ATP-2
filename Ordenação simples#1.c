#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10

/*Substitua cada elemento na i-ésima posição do array pelo maior elemento entre as posições i+1 e n-1.
Admita que todos os elementos são inteiros estritamente positivos.
Exemplo: Considere o array A = {1,2,8,1,3,5,4}*/

void Imprimindo_Valores_Array(int *Ptr1,int lim);
void Gerador_numero_pseudoaleatorio (int*Ptr ,int lim);

int main (void){

 int elem[MAX], maior, LIM, i, j;
 Gerador_numero_pseudoaleatorio(elem,MAX);
 Imprimindo_Valores_Array(elem,MAX);

  LIM = MAX - 2;
  for (i=0; i <= LIM; i++) {
    maior = elem[i+1];
    for (j=i+1; j < MAX; j++)
      if (elem[j] > maior) maior = elem[j];
    elem[i]= maior;
  }
  elem[MAX-1]=0;
  printf("\n\n\n\n");
  Imprimindo_Valores_Array(elem,MAX);


}

void Gerador_numero_pseudoaleatorio (int *Ptr,int lim){

 int i;   // índice para percorrer o array
 clock_t semente;

 semente = clock();
 srand();  // inicializando o gerador
 for (i = 0; i < lim; i++)
     *(Ptr+i) = rand()%10 +1;        // observe que esta função associa valores somente ao vetor elem

 return;
}

void Imprimindo_Valores_Array(int *Ptr1,int lim) {
 int i;   // indice para percorrer o array
 for (i = 0; i < lim; i++)
     printf("\n [%d] = %d ",i,*(Ptr1+i));

}



