// header da nossa heap, contem as funções
// tanto as que o professor pediu, quanto as gerais
// se a função não estiver aqui, é porque o usuario
// não precisa usar ela para nada
// vao adicionando as que acharem necessario

#ifndef HEAP_H

#define HEAP_H

#include <stdbool.h>

// implementação de uma MAX_HEAP
// ou seja, o nó pai é sempre MAIOR
// que seus filhos

typedef struct heap *Heap;

Heap heap_inicia(void);

bool heap_insere(Heap self, int dado);

int heap_remove(Heap self);

int heap_busca(Heap self, int buscado);

void heap_print(Heap self);

#endif // HEAP_H
