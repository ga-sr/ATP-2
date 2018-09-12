#include <stdio.h>
#include <time.h>
#include <math.h>
#include <locale.h>

#define MAX 10000

int elem[MAX];


int Leitura_Dimensao_Array(void);
int medias(int LIM, double *MA, double *MG, double *MQ, double *MH, double *DP);
void Imprimindo_Valores_Array(int lim);
void Gerador_numero_pseudoaleatorio (int lim);

int main(void){

    setlocale(LC_ALL,"Portuguese");

    int n;
    double ma,mg,mh,dp,mq;


    ma=mh=mq=mh=0.0;
    mg=1.0;

    setlocale(LC_ALL,"Portugeuse");

    n = Leitura_Dimensao_Array();
    Gerador_numero_pseudoaleatorio(n);
    Imprimindo_Valores_Array(n);
    medias(n, &ma, &mg , &mq, &mh, &dp);

    printf("\na media aritimetica: %lf\n", ma);
    printf("a media geometrica : %lf\n", mg);
    printf("a media quadrada   : %lf\n", mq);
    printf("a media harmonica  : %lf\n", mh);
    //printf("o desvio padrao    : %lf\n", dp);

}

int Leitura_Dimensao_Array(void) {
  int dim, continua;
  do {
     continua = 0;
     printf("Insira o número de componentes do array (>= 1 && <= 1000): ");
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
     elem[i]= rand();        // observe que esta função associa valores somente ao vetor elem

 return;
}

void Imprimindo_Valores_Array(int lim) {
 int i;   // indice para percorrer o array
 for (i = 0; i < lim; i++)
     printf("\n [%d] = %d ",i,elem[i]);

}

int medias(int LIM, double *MA, double *MG, double *MQ, double *MH, double *DP){
    int i;

    for(i=0; i<LIM; i++)
    {

        *MA += elem[i];
        *MG *= elem[i];
        *MQ += pow(elem[i],2);
        *MH += (1.0/elem[i]);

    }

    *MA= *MA/LIM;
    *MG= pow(*MG,1.0/(double)LIM);
    *MQ= sqrt(*MQ/LIM);
    *MH= LIM/ *MH;

    //*DP = sqrt((*MQ *(double)(LIM) - ((*MA) * (*MA)))/(double)(LIM * (LIM-1)));
    return;
}
