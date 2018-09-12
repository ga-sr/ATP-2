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

 int i,a1,a2,a3,a4,a5,a6;   // �ndice para percorrer o array
 a1=a2=a3=a4=a5=a6=0;

 for (i = 0; i < 10000; i++){
     *(Ptr+i) = (rand()%6)+1;      // observe que esta fun��o associa valores somente ao vetor elem
      if (*(Ptr+i) == 1 ) a1++;
      else if (*(Ptr+i) == 2) a2++;
      else if (*(Ptr+i) == 3) a3++;
      else if (*(Ptr+i) == 4) a4++;
      else if (*(Ptr+i) == 5) a5++;
      else if  (*(Ptr+i) == 6) a6++;
 }
 Imprimindo_Valores_Array(Ptr,&a1,&a2,&a3,&a4,&a5,&a6);

                                // observe que a fun��o rand varia de 0 a 6, ent�o somamos um para obedecer o intervalo [1,6]
 return;
}

void Imprimindo_Valores_Array(int *Ptr,int *X1, int *X2, int *X3, int *X4, int *X5, int *X6 ) {
 int i;   // indice para percorrer o array

 for (i = 0; i < MAX; i++)
     printf("\n [%d] = %d ",i,*(Ptr+i));
     printf("\nO n�mero 1 ocorreu %d de 10000 vezes\n",*X1);
     printf("O n�mero 2 ocorreu %d de 10000 vezes\n",*X2);
     printf("O n�mero 3 ocorreu %d de 10000 vezes\n",*X3);
     printf("O n�mero 4 ocorreu %d de 10000 vezes\n",*X4);
     printf("O n�mero 5 ocorreu %d de 10000 vezes\n",*X5);
     printf("O n�mero 6 ocorreu %d de 10000 vezes\n",*X6);
}
