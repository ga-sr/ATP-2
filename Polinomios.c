#include <stdio.h>
#include "Polinomios.h"

#define MAX 25

void ImprimeVetor(int* vetor, int dim)
{
    int i;
    for(i=0; i <)
}

void SomaPoli(int* poli1, int dim1, int* poli2, int dim2)
{
    int i, poli3[dim1+dim2], dim3;

    if(dim1 > dim2)
    {
        for(i = 0; i <= dim1; i++)
        {
            while (i <= dim2)
            {
                poli3[i] = poli1[i] + poli2[i];
                i++;
                dim3++;
            }
            poli3[i] = poli1[i];
            dim3++;
        }
    }

    if(dim1 < dim2)
    {
        for(i = 0; i <= dim2; i++)
        {
            while (i <= dim1)
            {
                poli3[i] = poli1[i] + poli2[i];
                i++;
                dim3++;
            }
            poli3[i] = poli2[i];
            dim3++;
        }
    }

    if(dim1 == dim2)
    {
        for(i=0; i<dim1)
    }
}

int* MultPoli(int* poli1, int dim1, int* poli2, int dim2)
