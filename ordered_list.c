#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define FALSE 0
#define SUCESS 1
#define TRUE 1
#define NOT_FOUND -1

typedef struct {
    int max;
    int n;
    int *items;
} t_ordered_list;

t_ordered_list* create_list(int max) {
    t_ordered_list *list = malloc(sizeof(t_ordered_list));

    if (list == NULL) {
        exit(1);
    }
    
    list->items = malloc(sizeof(int) * max);

    if (list->items == NULL) {
        exit(1);
    }

    list->max = max;
    list->n = 0;

    return list;
}

int insert(t_ordered_list *list, int number) {
    if (list->n + 1 > list->max) {
        return ERROR;
    }

    int index = 0;
    for (int i = 0; i < list->n; i++) {
        if (number < list->items[i]) {
            index = i;
            break;
        }

        if (i == list->n-1) {
            index = i + 1;
        }
    }

    for (int i = list->n + 1; i > index; i--) {
        list->items[i] = list->items[i-1];
    }

    list->items[index] = number;
    
    list->n++;

    return SUCESS;
}

int remove_by_index(t_ordered_list *list, int index) {
    if (index < 0 || index >= list->n) {
        return ERROR;
    }

    for (int i = index; i < list->n-1; i++) {
        list->items[i] = list->items[i+1];
    }

    list->n--;
    return SUCESS;    
}

int remove_by_element(t_ordered_list *list, int element) {
    for (int i = 0; i < list->n; i++) {
        if (list->items[i] == element) {
            remove_by_index(list, i);
            return SUCESS;
        }
    }
    
    return ERROR;
}

int search(t_ordered_list *list, int element) {
    int esquerda = 0;
    int direita = list->n-1;
    int meio = (esquerda + direita) / 2;
    while (esquerda <= direita) {
        if(list->items[meio] == element) {
            return meio;
        } else if (list->items[meio] > element) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
        meio = (direita + esquerda) / 2;
    }
    
    return NOT_FOUND;
}

int index_of(t_ordered_list *list, int element) {
    for (int i = 0; i < list->n; i++) {
        if (list->items[i] == element) {
            return i;
        }
    }

    return NOT_FOUND;
}

int get(t_ordered_list *list, int index) {
    if (index < 0 || index >= list->n) {
        return NOT_FOUND;
    }

    return list->items[index];
}

int count(t_ordered_list *list, int element) {
    int counter = 0;

    for (int i = 0; i < list->n; i++) {
        if (list->items[i] == element) {
            counter++;
        }
    }

    return counter;
}

int size(t_ordered_list *list) {
    return list->n;
}

t_ordered_list* merge(t_ordered_list *l1, t_ordered_list *l2) {
    t_ordered_list *result = create_list((l1->n + l2->n) * 10);
    int i = 0, j = 0;

    while (i < l1->n && j < l2->n) {
        if (l1->items[i] < l2->items[j]) {
            insert(result, l1->items[i++]);
        } else {
            insert(result, l2->items[j++]);
        }
    }

    while (i < l1->n) {
        insert(result, l1->items[i++]);
    }

    while (j < l2->n) {
        insert(result, l2->items[j++]);
    }
    
    return result;
}

int equals(t_ordered_list *l1, t_ordered_list *l2) {
    if (l1->n != l2->n) {
        return FALSE;
    }

    for (int i = 0; i < l1->n; i++) {
        if (l1->items[i] != l2->items[i]) {
            return FALSE;
        }
    }
    
    return TRUE;
}

int is_empty(t_ordered_list *list) {
    return list->n == 0 ? TRUE : FALSE;
}

void clear(t_ordered_list *list) {
    list->n = 0;
}

void destroy(t_ordered_list *list) {
    free(list->items);
    list->items = NULL;
    free(list);
    list = NULL;
}

int main() {
    t_ordered_list *teste = create_list(10);

    insert(teste, 10);
    printf("\n");
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }
    insert(teste, 19);
    printf("\n");
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }
    insert(teste, 1);
    printf("\n");
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }
    insert(teste, -4);
    printf("\n");
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }
    insert(teste, 10);
    printf("\n");
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }
    insert(teste, 11);
    printf("\n");
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }
    insert(teste, 20);
    printf("\n");

    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }

    printf("\n");
    remove_by_index(teste, 1);
    
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }

    printf("\n");


    remove_by_element(teste, 19);

    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }

    printf("\n");

    insert(teste, 30);
    for (int i = 0; i < teste->n; i++) {
        printf("%d\t", teste->items[i]);
    }

    printf("\n");
    printf("10 está no índice %d\n", search(teste, 10));
    printf("10 está no índice %d\n", index_of(teste, 10));
    printf("O elemento da posição 3 é %d\n", get(teste, 3));
    printf("O 500 aparece %d\n", count(teste, 500));

    t_ordered_list *l1 = create_list(100), *l2 = create_list(100);
    insert(l1, 1);
    insert(l1, 2);
    insert(l1, 10);
    insert(l2, 1);
    insert(l2, 2);
    insert(l2, 10);


    t_ordered_list *merge_list = merge(l1, l2);

    printf("\n");
    for (int i = 0; i < merge_list->n; i++) {
        printf("%d\t", merge_list->items[i]);
    }

    printf("\n");
    if (equals(l1, l2)) {
        printf("LISTAS IGUAIS\n");
    } else {
        printf("LISTAS DIFERENTES\n");
    }

    printf("\n");
    t_ordered_list *lista_vazia = create_list(100);
    insert(lista_vazia, 1);
    insert(lista_vazia, 1);
    insert(lista_vazia, 1);
    clear(teste);
    if (is_empty(teste)) {
        printf("LISTA VAZIA\n");
    } else {
        printf("LISTA NÃO VAZIA\n");
    }

    printf("\n");
    destroy(l1);

    return 0;
}
