#ifndef HEAP_H

#define HEAP_H

#include <stdbool.h>

// implementação de uma MAX_HEAP
// ou seja, o nó pai é sempre MAIOR
// que seus filhos

// todas as func com int *dado tem duas opções
// ou o ponteiro é NULL, e o dado é perdido
// ou ele aponta para algo e o dado é colocado ali
// as funções usam mto bool para evitar erros do usario
// como chamar as funções para uma heap invalida,
// posição invalida e etc

typedef struct heap *Heap;

// inicialização da heap
// o vetor só começa quando é
// inserido o primeiro elemento
Heap heap_inicia(void);

// inserção de elementos na heap
// ela também já faz a própria organização
// a primeira inserção já inicializa o vetor de dados
bool heap_insere(Heap self, int dado);

// remove a raiz da heap (maior elemento), alem disso
// caso o usuario queira, pode colocar um ponteiro válido,
// ou seja, diferente de NULL para receber o valor da antiga raiz
bool heap_remove(Heap self, int *dado);

// acessa o valor da raiz, mas sem remover ela
// só é bool para evitar erros do usuario, como tentar acessar heap invalida
// no geral gera uma segurança amais
bool heap_topo(Heap self, int *dado);

// busca um valor na heap, e retorna se encontrou ele ou não, caso
// o usuario deseje, ele pode guardar a primeira posição encontrada
// a principio a mais próxima a raiz, desde que o ponteiro pos seja valido
bool heap_busca(Heap self, int buscado, int *pos);

// retorna o tamanho da heap, se for uma heap invalida retorna zero
int heap_tamanho(Heap self);

// retorna se a heap é vazia, se a heap for invalida, é considerada vazia
bool heap_vazia(Heap self);

// printa os elementos da heap, usada para testes e etc.
void heap_print(Heap self);

// libera toda a memoria ocupada pela heap, também coloca o ponteiro como NULL
// evitando erros possiveis do usuario ao tentar reutilizar o ponteiro
void heap_destroi(Heap *self);

#endif // HEAP_H