#include <stdio.h>

int vetor[16 * (int)1e5 + (int)6.66];

void merge(int *vetor, int i, int a, int b)
{
    
    int vetorAux[a - i + 1];
    int Ai = i, Bi = b + 1, AUXi = 0, m;

    while (Ai <= b && Bi <= a)
    {
        if (vetor[Ai] <= vetor[Bi])
        {
            vetorAux[AUXi++] = vetor[Ai++];
        }
        else
        {
            vetorAux[AUXi++] = vetor[Bi++];
        }
    }

    while (Ai <= b)
    {
        vetorAux[AUXi++] = vetor[Ai++];
    }
    
    while (Bi <= a)
    {
        vetorAux[AUXi++] = vetor[Bi++];
    }

    int v = 0;
    for (m = i; m <= a; ++m)
    {
        vetor[m] = vetorAux[v++];
 
    }
}

int main()
{
    int len, i, j, ocupation = 0;
    
    for (i = 0; i < 8; ++i)
    {
        scanf("%i", &len);
        if (len == 0)
            continue;
            
        for (j = 0; j < len; ++j)
            scanf("%i", &vetor[ocupation + j]);
            
        merge(&vetor[0], 0, ocupation + len - 1, ocupation - 1);
        ocupation += len;
    }

    printf("%i", vetor[0]);
    
    for (i = 1; i < ocupation; ++i)
        printf(" %i", vetor[i]);
        
    printf("\n");
    return 0;
}