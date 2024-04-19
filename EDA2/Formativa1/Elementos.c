#include <stdio.h>
#include <stdlib.h>

// Leitura do número de elementos e dos valores, calcula a média
int leitura_e_media(int *v, int entrada) {
    long int soma = 0;

    for (int i = 0; i < entrada; i++) {
        scanf("%d", &v[i]);
        soma += v[i];
    }

    return soma / entrada;
}

// Imprime os valores maiores que a média
void imprime_maiores_que_media(int *v, int entrada, int media) {
    int confere = 0;

    for (int j = 0; j < entrada; j++) {
        if (v[j] > media) {
            if (confere != 0) {
                printf(" ");
            }
            printf("%d", v[j]);
            confere = 1;
        }
    }

    if (confere == 0) {
        printf("0");
    }

    printf("\n");
}

int main() {
    int entrada;
    scanf("%d", &entrada); // Quantos elementos vamos ler

    int *v = (int *)malloc(entrada * sizeof(int)); // Vetor com o número de entradas que vamos ler

    int media = leitura_e_media(v, entrada);

    imprime_maiores_que_media(v, entrada, media);

    free(v);

    return 0;
}
