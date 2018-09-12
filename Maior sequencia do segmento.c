#include <stdio.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define MAX 10

int n,
    elem[MAX];

void Imprimindo_Valores_Array(int lim);
int Leitura_Dimensao_Array(void);
int MaiorSS (int *Ptr, int lim);
void Gerador_numero_pseudoaleatorio (int lim);

int main (void){
    setlocale(LC_ALL,"Portuguese");
    int maior=0;

    n = Leitura_Dimensao_Array();
    Gerador_numero_pseudoaleatorio(n);
    Imprimindo_Valores_Array(n);
    maior = MaiorSS(elem, n);

    printf("\n\nMaior segmento é = %d",maior);
}

int Leitura_Dimensao_Array(void) {
  int dim, continua;
  do {
     continua = 0;
     printf("Insira o número de componentes do array (>= 1 && <= 10): ");
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX) ) continua = 1;
     }
  while ( continua );

  return(dim);
}

void Gerador_numero_pseudoaleatorio (int lim){

 int i;   // índice para percorrer o array
 clock_t semente;

 semente = clock();
 srand((unsigned) semente);  // inicializando o gerador
 for (i = 0; i < lim; i++)
     elem[i]= rand()%5;        // observe que esta função associa valores somente ao vetor elem

 return;
}

void Imprimindo_Valores_Array(int lim) {
 int i;   // indice para percorrer o array
 for (i = 0; i < lim; i++)
     printf("\n [%d] = %d ",i,elem[i]);

}

int MaiorSS (int *Ptr, int lim){

    int i=0,seg, segmax, dim;
    seg=segmax=1;
    dim = lim-2;

    for(;i<=dim;i++){
        if (*(Ptr+i+1) > *(Ptr+i)){
            seg++;
            if(seg>segmax) segmax = seg;
        }
        else seg=1;
    }
    return(segmax);
}
