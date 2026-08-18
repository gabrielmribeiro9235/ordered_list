#include <stdlib.h>
#include "list.h"

t_ordered_list* create_list(int max) {
    if (max <= 0) {
        exit(1);
    }

    t_ordered_list *list = malloc(sizeof(t_ordered_list));

    if (list == NULL) {
        exit(1);
    }
    
    list->items = malloc(sizeof(int) * max);

    if (list->items == NULL) {
        free(list);
        exit(1);
    }

    list->max = max;
    list->n = 0;

    return list;
}

int realloc_list(t_ordered_list *list) {
    int *temp = realloc(list->items, (list->max*2) * sizeof(int));

    if (temp == NULL) {
        return ERROR;
    }

    list->items = temp;
    list->max *= 2;

    return SUCCESS;
}

int insert(t_ordered_list *list, int number) {
    if (list->n + 1 > list->max && realloc_list(list) == ERROR) {
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

    for (int i = list->n; i > index; i--) {
        list->items[i] = list->items[i-1];
    }

    list->items[index] = number;
    
    list->n++;

    return SUCCESS;
}

int remove_by_index(t_ordered_list *list, int index) {
    if (index < 0 || index >= list->n) {
        return ERROR;
    }

    for (int i = index; i < list->n-1; i++) {
        list->items[i] = list->items[i+1];
    }

    list->n--;
    return SUCCESS;
}

int remove_by_element(t_ordered_list *list, int element) {
    int index_of_element = index_of(list, element);

    if (index_of_element == NOT_FOUND) {
        return ERROR;
    }
    
    remove_by_index(list, index_of_element);

    return SUCCESS;
}

int search(t_ordered_list *list, int element) {
    int esquerda = 0;
    int direita = list->n-1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if(list->items[meio] == element) {
            return meio;
        }

        if (list->items[meio] > element) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
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
        exit(1);
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
    t_ordered_list *result = create_list(l1->n + l2->n);
    int i = 0, j = 0, k = 0;

    while (i < l1->n && j < l2->n) {
        if (l1->items[i] < l2->items[j]) {
            result->items[k++] = l1->items[i++];
        } else {
            result->items[k++] = l2->items[j++];
        }
    }

    while (i < l1->n) {
        result->items[k++] = l1->items[i++];
    }

    while (j < l2->n) {
        result->items[k++] = l2->items[j++];
    }

    result->n = l1->n + l2->n;
    
    return result;
}

int equals(t_ordered_list *l1, t_ordered_list *l2) {
    if (l1->n != l2->n) {
        return 0;
    }

    for (int i = 0; i < l1->n; i++) {
        if (l1->items[i] != l2->items[i]) {
            return 0;
        }
    }
    
    return 1;
}

int is_empty(t_ordered_list *list) {
    return list->n == 0;
}

void clear(t_ordered_list *list) {
    list->n = 0;
}

void destroy(t_ordered_list **list) {
    if (*list == NULL) {
        return;
    }
    free((*list)->items);
    free(*list);
    *list = NULL;
}