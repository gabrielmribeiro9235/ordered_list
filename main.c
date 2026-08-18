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
CADA VEZ QUE O NÚMERO DE ELEMENTOS IGUALA O MÁXIMO, REALOCA O DOBRO DO MÁXIMO ATUAL E RESETA O MÁXIMO PARA 
O SEU DOBRO.
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    char line[] = "-------------------------------------\n";

    printf("%s", line);
    printf("Criando lista...\n");

    int max;
    t_ordered_list *main_list;
    
    printf("Insira o tamanho da lista: ");
    scanf("%d", &max);
    
    main_list = create_list(max);

    printf("\nLista criada com sucesso!\n");
    
    int option = 14;
    do {
        switch (option) {
        case 1: {
            int element;
            
            printf("Digite o elemento que quer inserir na lista:\n");
            scanf("%d", &element);
            
            if (insert(main_list, element)) {
                printf("\nElemento inserido com sucesso\n");
            } else {
                printf("\nErro ao inserir o elemento\n");
            }

            break;
        }
        case 2: {
            int index;
            
            printf("Digite o índice que deseja excluir:\n");
            scanf("%d", &index);
            
            if (remove_by_index(main_list, index)) {
                printf("\nRemoção feita com sucesso\n");
            } else {
                printf("\nÍndice não encontrado\n");
            }

            break;
        }
        case 3: {
            int element;
            
            printf("Digite o elemento que deseja excluir:\n");
            scanf("%d", &element);
            
            if (remove_by_element(main_list, element)) {
                printf("\nRemoção feita com sucesso\n");
            } else {
                printf("\nElemento não encontrado\n");
            }

            break;
        }
        case 4: {
            int element;
            
            printf("Digite o elemento que deseja buscar:\n");
            scanf("%d", &element);
            
            int index = search(main_list, element);
            if (index == NOT_FOUND) {
                printf("\nElemento não encontrado\n");
            } else {
                printf("\n%d está no índice: %d\n", element, index);
            }

            break;
        }
        case 5: {
            int element;
            
            printf("Digite o elemento que deseja buscar:\n");
            scanf("%d", &element);
            
            int index = index_of(main_list, element);
            if (index == NOT_FOUND) {
                printf("\nElemento não encontrado\n");
            } else {
                printf("\n%d está no índice: %d\n", element, index);
            }

            break;
        }
        case 6: {
            int index;

            printf("Insira o índice que deseja buscar (ATENÇÃO: SE INSERIR UM ÍNDICE INVÁLIDO, O PROGRAMA VAI PARAR):\n");
            scanf("%d", &index);

            printf("\nO elemento do índice %d é: %d\n", index, get(main_list, index));
            
            break;
        }
        case 7: {
            int element;

            printf("Insira o elemento que deseja saber o número de ocorrências:\n");
            scanf("%d", &element);

            printf("\nO elemento %d aparece na lista: %d vezes\n", element, count(main_list, element));
            
            break;
        }
        case 8:
            printf("O tamanho atual da lista é: %d\n", size(main_list));
        
            break;
        case 9: {
            int size1, size2;

            printf("Insira o tamanho da primeira lista: ");
            scanf("%d", &size1);
            printf("\n");

            if (size1 <= 0) {
                printf("Tamanho inválido, voltando ao menu...\n");
                break;
            }

            int flag = 0;
            t_ordered_list *l1 = create_list(size1);
            for (int i = 0; i < size1; i++) {
                int element;
                
                printf("Insira o elemento %d da lista 1: ", i);
                scanf("%d", &element);

                if (insert(l1, element) == ERROR) {
                    printf("Erro ao inserir elemento, voltando ao menu...\n");
                    flag = 1;
                    break;
                }
            }

            if (flag) {
                destroy(&l1);
                break;
            }
            
            printf("\nInsira o tamanho da segunda lista: ");
            scanf("%d", &size2);
            printf("\n");

            if (size2 <= 0) {
                printf("Tamanho inválido, voltando ao menu...\n");
                destroy(&l1);
                break;
            }

            t_ordered_list *l2 = create_list(size2);
            for (int i = 0; i < size2; i++) {
                int element;
                
                printf("Insira o elemento %d da lista 2: ", i);
                scanf("%d", &element);

                if (insert(l2, element) == ERROR) {
                    printf("Erro ao inserir elemento, voltando ao menu...\n");
                    flag = 1;
                    break;
                }
            }

            if (flag) {
                destroy(&l1);
                destroy(&l2);
                break;
            }

            destroy(&main_list);
            main_list = merge(l1, l2);

            destroy(&l1);
            destroy(&l2);

            break;
        }
        case 10: {
            int size1, size2;

            printf("Insira o tamanho da primeira lista: ");
            scanf("%d", &size1);
            printf("\n");

            if (size1 <= 0) {
                printf("Tamanho inválido, voltando ao menu...\n");
                break;
            }

            int flag = 0;
            t_ordered_list *l1 = create_list(size1);
            for (int i = 0; i < size1; i++) {
                int element;
                
                printf("Insira o elemento %d da lista 1: ", i);
                scanf("%d", &element);

                if (insert(l1, element) == ERROR) {
                    printf("Erro ao inserir elemento, voltando ao menu...\n");
                    flag = 1;
                    break;
                }
            }

            if (flag) {
                destroy(&l1);
                break;
            }

            printf("\nInsira o tamanho da segunda lista: ");
            scanf("%d", &size2);
            printf("\n");

            if (size2 <= 0) {
                printf("Tamanho inválido, voltando ao menu...\n");
                destroy(&l1);
                break;
            }
            
            t_ordered_list *l2 = create_list(size2);
            for (int i = 0; i < size2; i++) {
                int element;
                
                printf("Insira o elemento %d da lista 2: ", i);
                scanf("%d", &element);

                if (insert(l2, element) == ERROR) {
                    printf("Erro ao inserir elemento, voltando ao menu...\n");
                    flag = 1;
                    break;
                }
            }

            if (flag) {
                destroy(&l1);
                destroy(&l2);
                break;
            }

            if (equals(l1, l2)) {
                printf("\nAs duas listas criadas são iguais\n");
            } else {
                printf("\nAs duas listas criadas não são iguais\n");
            }

            destroy(&l1);
            destroy(&l2);

            break;
        }
        case 11:
            if (is_empty(main_list)) {
                printf("A lista está vazia\n");
            } else {
                printf("A lista não está vazia\n");
            }

            break;
        case 12:
            clear(main_list);
            printf("Lista esvaziada\n");

            break;
        case 13:
            print_list(main_list);

            break;
        default:
            if (option != 14) { 
                printf("Escolha inválida\n");
            }
            break;
        }
        printf("%s", line);
        printf(" 1 - Inserir elemento na lista\n");
        printf(" 2 - Remover elemento por índice\n");
        printf(" 3 - Remover um elemento dado\n");
        printf(" 4 - Buscar um elemento dado (busca binária)\n");
        printf(" 5 - Buscar um elemento dado (busca sequencial)\n");
        printf(" 6 - Buscar o elemento de um índice dado\n");
        printf(" 7 - Número de vezes que um dado elemento aparece na lista\n");
        printf(" 8 - Verificar tamanho atual da lista\n");
        printf(" 9 - Montar a lista a partir de um merge de outras duas novas listas (ATENÇÃO: isso destrói a lista atual)\n");
        printf("10 - Criar duas novas listas e verificar se elas são iguais\n");
        printf("11 - Verificar se a lista está vazia\n");
        printf("12 - Esvaziar uma lista\n");
        printf("13 - Exibir lista\n");
        printf("14 - Sair\n");
        printf("%s", line);
        printf("Sua escolha: ");
        scanf("%d", &option);
        printf("%s", line);
    } while (option != 14);

    printf("Liberando memória...\n");

    destroy(&main_list);

    printf("-----------FIM DO PROGRAMA-----------");
    
    return 0;
}
