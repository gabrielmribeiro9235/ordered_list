#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    // Cria lista
    t_ordered_list *teste = create_list(1000);

    // Insere elementos
    insert(teste, 10);
    insert(teste, 19);
    insert(teste, 1);
    insert(teste, -4);
    insert(teste, 10);
    insert(teste, 11);
    insert(teste, 20);
    // Verifica inserção
    printf("\n");
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }
    printf("\n");

    // Remove um elemento pelo índice
    remove_by_index(teste, 1);
    // Verifica remoção
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }
    printf("\n");

    // Remove um elemento dado
    remove_by_element(teste, 19);
    // Verifica remoção
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }
    printf("\n");
    printf("\n");

    // Busca binário
    printf("10 está no índice %d\n", search(teste, 10));
    // Busca sequencial
    printf("10 está no índice %d\n", index_of(teste, 10));
    // Busca o elemento de uma posição
    printf("O elemento da posição 3 é %d\n", get(teste, 3));
    // Conta o número de vezes que um elemento aparece
    printf("O 500 aparece %d\n", count(teste, 500));

    // Merge
    t_ordered_list *l1 = create_list(100), *l2 = create_list(100);
    insert(l1, 1);
    insert(l1, 2);
    insert(l1, 10);
    insert(l2, 1);
    insert(l2, 2);
    insert(l2, 10);
    t_ordered_list *merge_list = merge(l1, l2);
    // Verifica o merge
    printf("\n");
    for (int i = 0; i < merge_list->n; i++) {
        printf("%d\t", merge_list->items[i]);
    }
    printf("\n");

    // Verifica se duas listas são iguais
    if (equals(l1, l2)) {
        printf("LISTAS IGUAIS\n");
    } else {
        printf("LISTAS DIFERENTES\n");
    }
    printf("\n");

    // Verifica lista vazia
    t_ordered_list *lista_vazia = create_list(100);
    if (is_empty(lista_vazia)) {
        printf("LISTA VAZIA\n");
    } else {
        printf("LISTA NÃO VAZIA\n");
    }

    insert(lista_vazia, 1);
    insert(lista_vazia, 1);
    insert(lista_vazia, 1);
    // Torna lista vazia
    clear(lista_vazia);
    if (is_empty(lista_vazia)) {
        printf("LISTA VAZIA\n");
    } else {
        printf("LISTA NÃO VAZIA\n");
    }
    printf("\n");

    // Libera memórias
    destroy(teste);
    destroy(l1);
    destroy(l2);
    destroy(merge_list);
    destroy(lista_vazia);

    return 0;
}
