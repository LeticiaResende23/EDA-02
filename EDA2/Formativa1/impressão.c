#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le){
    celula *elem = le->prox;

    while (elem != NULL)
    {
        printf("%d -> ", elem->dado);
        elem = elem->prox;
    }

    printf("NULL\n");
}

void imprime_rec(celula *le){
    le = le->prox;

    if (le == NULL){
        printf("NULL\n");
        return;
    }


    printf("%d -> ", le->dado);
    imprime_rec(le);
}