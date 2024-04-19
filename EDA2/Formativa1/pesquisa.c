#include <stdio.h>
#include <stdlib.h>

typedef struct instrucao {
    int id;
    char palavra_chave[16];
} instrucao;

struct arvore {
    struct instrucao *instrucao;
    struct arvore *esquerda;
    struct arvore *direita;
};

struct arvore *cria_arvore(instrucao *instrucao) {
    struct arvore *nova_arvore = (struct arvore *)malloc(sizeof(struct arvore));
    nova_arvore->instrucao = instrucao;
    nova_arvore->esquerda = NULL;
    nova_arvore->direita = NULL;
    return nova_arvore;
}

struct arvore *inserir(struct arvore *arvore, instrucao *instrucao) {
    if (arvore == NULL) {
        return cria_arvore(instrucao);
    }

    if (instrucao->id < arvore->instrucao->id) {
        arvore->esquerda = inserir(arvore->esquerda, instrucao);
    } else {
        arvore->direita = inserir(arvore->direita, instrucao);
    }

    return arvore;
}

instrucao *buscar(struct arvore *arvore, int id) {
    if (arvore == NULL) {
        return NULL;
    }

    if (arvore->instrucao->id == id) {
        return arvore->instrucao;
    } else if (id < arvore->instrucao->id) {
        return buscar(arvore->esquerda, id);
    } else {
        return buscar(arvore->direita, id);
    }
}

int main() {
    int n, dado;

    scanf("%d", &n);

    instrucao *instrucoes = (instrucao *)malloc(sizeof(instrucao) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &instrucoes[i].id, instrucoes[i].palavra_chave);
    }

    struct arvore *arvore = NULL;

    for (int i = 0; i < n; i++) {
        arvore = inserir(arvore, &instrucoes[i]);
    }

    while (scanf("%d", &dado) != EOF) {
        instrucao *instrucao = buscar(arvore, dado);

        if (instrucao == NULL) {
            printf("undefined\n");
        } else {
            printf("%s\n", instrucao->palavra_chave);
        }
    }

    free(instrucoes);
    return 0;
}
