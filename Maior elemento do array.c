#include <stdio.h>
#include <time.h>
#include <locale.h>

#define MAX 50000

int elem[MAX];

int Maior_elemento(int *Pos ,int lim);
int Leitura_Dimensao_Array(void);
void Gerador_numero_pseudoaleatorio (int lim);
void Imprimindo_Valores_Array(int lim);
short Busca_Linear(int maior, int Dim);

int main(void){

    setlocale(LC_ALL,"Portuguese");
    int n, m, position=0;

    n = Leitura_Dimensao_Array();
    Gerador_numero_pseudoaleatorio(n);
    Imprimindo_Valores_Array(n);
    m = Maior_elemento(&position, n);
    Busca_Linear(m,n);

    printf("\n\nA posi��o e o maior elemento respectivamente � : [%d] = %d",position,m);
    printf("\n\nO n�mero se repete %d vezes\n\n",Busca_Linear(m,n));


}

int Maior_elemento(int *Pos, int lim){

    int i=1, maior;
    maior = elem[0];

    for(;i<=lim;i++){
        if(elem[i]>maior){
            maior = elem[i];
            *Pos = i;
        }
    }

    return(maior);
}

int Leitura_Dimensao_Array(void) {
  int dim, continua;
  do {
     continua = 0;
     printf("Insira o n�mero de componentes do array (>= 1 && <= 50000): ");
     scanf("%d",&dim);
     if ( (dim <= 0) || (dim > MAX) ) continua = 1;
     }
  while ( continua );

  return(dim);
}

short Busca_Linear(int maior, int Dim) {

     int i, cont=0;   // indice para percorrer o array

     // Observem que a vari�vel elem � global
     for (i = 0; i < Dim; i++)
          if ( elem[i] == maior ) {
                cont++;
          }

     return(cont);
}  // Busca_Linear

void Gerador_numero_pseudoaleatorio (int lim){

 int i;   // �ndice para percorrer o array
 clock_t semente;

 semente = clock();
 srand((unsigned) semente);  // inicializando o gerador
 for (i = 0; i < lim; i++)
     elem[i]= rand();        // observe que esta fun��o associa valores somente ao vetor elem

 return;
}

void Imprimindo_Valores_Array(int lim) {
 int i;   // indice para percorrer o array
 for (i = 0; i < lim; i++)
     printf("\n [%d] = %d ",i,elem[i]);

}
