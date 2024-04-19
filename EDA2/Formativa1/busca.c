#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca_rec(celula *le, int x){
    if( le->prox == NULL || le->prox->dado == x){
        return le->prox;
    } else {
        return busca_rec(le->prox, x);

    }
}

celula *busca(celula *le, int x){
    celula *a = le->prox;
    while(a != NULL && a->dado != x){
            a = a->prox;
        }
    return a;
    
}


