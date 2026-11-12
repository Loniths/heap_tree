// arquivo nosso de testes
// quando forem adicionando funções
// vão também testando elas afinal
// estamos codando em C

#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    Heap teste = heap_inicia();
    heap_insere(teste, 10);
    heap_insere(teste, 20);
    heap_insere(teste, 5);
    heap_insere(teste, 30);
    heap_print(teste);
    heap_destroi(&teste);
    return 0;
}
