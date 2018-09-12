#include <stdio.h>
#include <time.h>
#include <locale.h>

#define MAX 10000

void Gerador_numero_pseudoaleatorio (int *Ptr);
void Imprimindo_Valores_Array(int *Ptr,int *X1, int *X2, int *X3, int *X4, int *X5, int *X6);

int main (void){

    setlocale(LC_ALL,"Portuguese");
    int elem[MAX];

    Gerador_numero_pseudoaleatorio(elem);

}

void Gerador_numero_pseudoaleatorio (int *Ptr){

 int i,a1,a2,a3,a4,a5,a6;   // índice para percorrer o array
 a1=a2=a3=a4=a5=a6=0;

 for (i = 0; i < 10000; i++){
     *(Ptr+i) = (rand()%6)+1;      // observe que esta função associa valores somente ao vetor elem
      if (*(Ptr+i) == 1 ) a1++;
      else if (*(Ptr+i) == 2) a2++;
      else if (*(Ptr+i) == 3) a3++;
      else if (*(Ptr+i) == 4) a4++;
      else if (*(Ptr+i) == 5) a5++;
      else if  (*(Ptr+i) == 6) a6++;
 }
 Imprimindo_Valores_Array(Ptr,&a1,&a2,&a3,&a4,&a5,&a6);

                                // observe que a função rand varia de 0 a 6, então somamos um para obedecer o intervalo [1,6]
 return;
}

void Imprimindo_Valores_Array(int *Ptr,int *X1, int *X2, int *X3, int *X4, int *X5, int *X6 ) {
 int i;   // indice para percorrer o array

 for (i = 0; i < MAX; i++)
     printf("\n [%d] = %d ",i,*(Ptr+i));
     printf("\nO número 1 ocorreu %d de 10000 vezes\n",*X1);
     printf("O número 2 ocorreu %d de 10000 vezes\n",*X2);
     printf("O número 3 ocorreu %d de 10000 vezes\n",*X3);
     printf("O número 4 ocorreu %d de 10000 vezes\n",*X4);
     printf("O número 5 ocorreu %d de 10000 vezes\n",*X5);
     printf("O número 6 ocorreu %d de 10000 vezes\n",*X6);
}
