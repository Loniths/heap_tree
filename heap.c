#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

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
        self->nos = malloc(10 * sizeof(int));
        if(self->nos == NULL) return false;
        self->capacidade = 10;
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
    if(self->n_nos == 0) return;
    for(int i = 0; i < self->n_nos; i++){
        printf("%d, ", self->nos[i]);
    }
    printf("\n");
}

void heap_destroi(Heap *self){
    if(self == NULL || *self == NULL) return;
    free(*(self)->nos);
    free(*self);
    *self = NULL;
}
