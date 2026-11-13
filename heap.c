#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACIDADE_INICIAL 10

struct heap{
    int n_nos;
    int *nos;
    int capacidade;
};

Heap heap_inicia(void){
    Heap temp = malloc(sizeof(struct heap));
    if(temp == NULL) return NULL;
    temp->n_nos = 0;
    temp->capacidade = 0;
    temp->nos = NULL;
    return temp;
}

static int retorna_pai(int filho){
    return (filho - 1) / 2;
}

static void troca(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

static void sift_up(Heap self){
    int pos = self->n_nos;
    int pai = retorna_pai(pos);
    while(pos > 0 && self->nos[pos] > self->nos[pai]){
        troca(&self->nos[pai], &self->nos[pos]);
        pos = pai;
        pai = retorna_pai(pos);
    }
}

bool heap_insere(Heap self, int dado){
    if(self == NULL) return false;
    if(self->n_nos == 0 && self->nos == NULL){
        self->nos = malloc(CAPACIDADE_INICIAL * sizeof(int));
        if(self->nos == NULL) return false;
        self->capacidade = CAPACIDADE_INICIAL;
    }
    if(self->capacidade == self->n_nos){
        int *temp = realloc(self->nos, (self->capacidade * 2) * sizeof(int));
        if(temp == NULL) return false;
        self->nos = temp;
        self->capacidade *= 2;
    }
    self->nos[self->n_nos] = dado;
    sift_up(self);
    self->n_nos++;
    return true;
}

void heap_print(Heap self){
    if(self == NULL || self->n_nos == 0) return;
    for(int i = 0; i < self->n_nos; i++){
        if(i != 0) printf(", ");
        printf("%d", self->nos[i]);
    }
    printf("\n");
}

void heap_destroi(Heap *self){
    if(self == NULL || *self == NULL) return;
    free((*self)->nos);
    free(*self);
    *self = NULL;
}

static void retorna_filhos(int pai, int *dir, int *esq){
    *dir = (2 * pai) + 2;
    *esq = (2 * pai) + 1;
}

static int maior_filho(Heap self, int pos){
    int dir, esq;
    retorna_filhos(pos, &dir, &esq);
    if(dir >= self->n_nos){
        if(esq >= self->n_nos) return -1;
        return esq;
    }
    else if(esq >= self->n_nos) return dir;
    else return (self->nos[dir] > self->nos[esq]) ? dir : esq;
}

static void sift_down(Heap self){
    int pos = 0;
    int maior = maior_filho(self, pos);
    while(maior != -1 && self->nos[pos] < self->nos[maior]){
        troca(&self->nos[pos], &self->nos[maior]);
        pos = maior;
        maior = maior_filho(self, pos);
    }
}

bool heap_remove(Heap self, int *dado){
    if(self == NULL || self->n_nos == 0) return false;
    if(dado != NULL) *dado = self->nos[0];
    self->n_nos--;
    self->nos[0] = self->nos[self->n_nos];
    sift_down(self);
    if(self->n_nos <= (self->capacidade / 4)){
        int nova_capacidade = self->capacidade / 2;
        if(nova_capacidade >= CAPACIDADE_INICIAL){
            int *temp = realloc(self->nos, nova_capacidade * sizeof(int));
            if(temp != NULL){
                self->nos = temp;
                self->capacidade = nova_capacidade;
            }
        }
    }
    return true;
}

bool heap_topo(Heap self, int *dado){
    if(self == NULL || self->n_nos == 0) return false;
    if(dado != NULL) *dado = self->nos[0];
    return true;
}

bool heap_busca(Heap self, int buscado, int *pos){
    if(self == NULL || self->n_nos == 0) return false;
    for(int i = 0; i < self->n_nos; i++){
        if(self->nos[i] == buscado){
            if(pos != NULL) *pos = i;
            return true;
        }
    }
    return false;
}

int heap_tamanho(Heap self){
    if(self == NULL) return 0;
    return self->n_nos;
}

bool heap_vazia(Heap self){
    if(self == NULL) return true;
    return self->n_nos == 0;
}
