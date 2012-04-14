#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__
#define TEST 1
typedef unsigned int uint;
typedef int(*compare_func)(void *p_data1, void *p_data2);
typedef int(*destroy_func)(void *p_data);
typedef struct _single_node single_node;
typedef struct _single_list
{
	single_node *p_head;
	single_node *p_tail;
	single_node *p_cur;
	uint count;
}single_list;
single_list *slist_create(void);
void slist_destroy(single_list *list, destroy_func fn);
int insert_head(single_list *list, void *data);
int insert_tail(single_list *list, void *data);
void *head_pop(single_list *list);
void *head_get(single_list *list);
void *tail_get(single_list *list);
void *tail_pop(single_list *list);
void *count_get(single_list *list);
#endif
