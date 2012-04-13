#ifndef __SINGLE_LIST_H__
#define __SINGLE_LIST_H__
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
};
#endif
