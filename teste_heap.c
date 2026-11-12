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
    heap_remove(teste, NULL);
    heap_print(teste);
    heap_remove(teste, NULL);
    heap_print(teste);
    int topo;
    printf("%d\n", heap_topo(teste, &topo));
    printf("%d\n", topo);
    int pos;
    printf("%d\n", heap_busca(teste, 5, &pos));
    printf("%d\n", pos);
    printf("%d\n", heap_vazia(teste));
    heap_destroi(&teste);
    return 0;
}