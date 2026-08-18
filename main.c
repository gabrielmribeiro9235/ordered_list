/*
CAUÃ HABERMANN PEREIRA
GABRIEL MELO RIBEIRO
GUILHERME LEONARDO GREGÓRIO

1) PONTOS FORTES: BUSCA RÁPIDA (BUSCA BINÁRIA É O(LOG N)) E NÃO NECESSITA FAZER ORDENAÇÃO;
PONTOS FRACOS: INSERÇÃO MAIS DEVAGAR (O(N)), REMOÇÃO MAIS DEVAGAR (O(N)) E NO GET(LISTA, INDEX), CASO O USUÁRIO PASSE UM NÚMERO 
INVÁLIDO, É NECESSÁRIO SAIR DO PROGRAMA E NÃO DÁ PARA RETORNAR UM INTEIRO QUE FAÇA O USUÁRIO ENTENDER O ERRO,
POIS QUALQUER CÓDIGO DE ERRO INTEIRO PODE SER CONFUNDIDO COM O INTEIRO DA POSIÇÃO INDEX.

2) ESTRATÉGIA PARA AUMENTAR A MEMÓRIA, QUANDO O USUÁRIO QUER INSERIR MAIS ITENS
DO QUE O ALOCADO PREVIAMENTE:
CADA VEZ QUE O NÚMERO DE ELEMENTOS IGUALA O MÁXIMO, REALOCA O DOBRO DO MÁXIMO INICIAL E RESETA O MÁXIMO PARA 
O SEU DOBRO.
*/

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
    printf("Verifica inserção\n");
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }

    // Remove um elemento pelo índice
    remove_by_index(teste, 1);
    printf("\n\nVerifica remoção pelo índice\n");
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }
    
    // Remove um elemento dado
    remove_by_element(teste, 19);
    printf("\n\nVerifica remoção de um elemento dado\n");
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }

    printf("\n\nBusca binário:\n");
    printf("10 está no índice %d\n\n", search(teste, 10));

    printf("Busca sequencial:\n");
    printf("10 está no índice %d\n\n", index_of(teste, 10));

    printf("Busca o elemento de um índice dado:\n");
    printf("O elemento da posição 3 é %d\n\n", get(teste, 3));

    printf("Conta o número de vezes que um elemento aparece:\n");
    printf("O 500 aparece %d\n\n", count(teste, 500));

    // Merge
    t_ordered_list *l1 = create_list(100), *l2 = create_list(100);
    insert(l1, 1);
    insert(l1, 2);
    insert(l1, 10);
    insert(l2, 1);
    insert(l2, 2);
    insert(l2, 10);
    printf("Lista l1:\n");
    for (int i = 0; i < l1->n; i++) {
        printf("%d\t", l1->items[i]);
    }
    printf("\nLista l2:\n");
    for (int i = 0; i < l2->n; i++) {
        printf("%d\t", l2->items[i]);
    }
    t_ordered_list *merge_list = merge(l1, l2);
    printf("\n\nVerifica o merge\n");
    for (int i = 0; i < merge_list->n; i++) {
        printf("%d\t", merge_list->items[i]);
    }

    printf("\n\nVerifica se l1 e l2 são iguais\n");
    if (equals(l1, l2)) {
        printf("LISTAS IGUAIS\n");
    } else {
        printf("LISTAS DIFERENTES\n");
    }

    printf("\n\nVerifica lista vazia\n");
    t_ordered_list *lista_vazia = create_list(100);
    if (is_empty(lista_vazia)) {
        printf("LISTA VAZIA\n");
    } else {
        printf("LISTA NÃO VAZIA\n");
    }

    insert(lista_vazia, 1);
    insert(lista_vazia, 1);
    insert(lista_vazia, 1);

    printf("\nTorna lista vazia\n");
    clear(lista_vazia);
    if (is_empty(lista_vazia)) {
        printf("LISTA VAZIA\n");
    } else {
        printf("LISTA NÃO VAZIA\n");
    }

    printf("\n\nLibera memórias\n");
    destroy(&teste);
    destroy(&l1);
    destroy(&l2);
    destroy(&merge_list);
    destroy(&lista_vazia);

    printf("\nFIM\n");

    return 0;
}
