#ifndef LIST_H
#define LIST_H

typedef struct {
    int max;
    int n;
    int *items;
} t_ordered_list;
t_ordered_list* create_list(int max);
int insert(t_ordered_list *list, int number);
int remove_by_index(t_ordered_list *list, int index);
int remove_by_element(t_ordered_list *list, int element);
int search(t_ordered_list *list, int element);
int index_of(t_ordered_list *list, int element);
int get(t_ordered_list *list, int index);
int count(t_ordered_list *list, int element);
int size(t_ordered_list *list);
t_ordered_list* merge(t_ordered_list *l1, t_ordered_list *l2);
int equals(t_ordered_list *l1, t_ordered_list *l2);
int is_empty(t_ordered_list *list); 
void clear(t_ordered_list *list);
void destroy(t_ordered_list *list);

#endif