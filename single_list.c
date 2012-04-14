#include <stdio.h>
#include "single_list.h"
struct _single_node
{
	void *p_data;
	struct _single_node *p_next;
};
/**
 *\brief create single list
 *\return NULL fail 
 *\return NOTNULL the pointer of single_list 
 */
single_list *slist_create(void)
{
	single_list *p_list;
	p_list = (single_list *)malloc(sizeof(single_list));
	if(p_list == NULL)
	{
		p_list->p_cur = NULL;
		p_list->p_head = NULL;
		p_list->p_tail = NULL;
		p_list->count = 0;
	}
	return p_list;
}
/**
 * \brief destroy single list
 */
void slist_destroy(single_list *list, destroy_func fn)
{
	single_node *p_node;
	single_node *p_delnode;
	if(list)
	{
		p_node = list->p_head;
		while(p_node!=NULL)
		{
			p_delnode = p_node;
			p_node = p_node->p_next;
			if(fn != NULL && p_delnode->p_data != NULL)
			{
				(*fn)(p_delnode->p_data);
			}
			free(p_delnode);
		}
		free(list);
	}
}
/**
 * \brief insert node before head
 * \param list the pointer to list which data insert in
 * \param data the pointer to data
 **/
int slist_insert_head(single_list *list, void *data)
{
	single_node *p_node;
	if(list == NULL || data == NULL)
	{
		return -1;
	}

	p_node = (single_node *)malloc(sizeof(single_node));
	if(p_node == NULL)
	{
		return -1;
	}

	p_node->p_data = data;
	p_node->p_next = list->p_head;
	list->p_head = p_node;

	if(list->p_tail == NULL)
	{
		list->p_tail = p_node;
	}
	list->count++;
	return 0;
	
}
/**
 * \brief get the count of single_node in single_list
 * 
 **/
uint slist_count_get(single_list *list)
{
	if(list == NULL)
	{
		return 0;
	}
	return list->count;
}
/**
 * \brief 
 * \
 */
void slist_enumbegin(single_list *list)
{
	list->p_cur = list->p_head;
	return;
}
/**
 *
 */
void * slist_enumnext(single_list *list)
{
	single_node *p_cur;
	p_cur = list->p_cur;
	if(p_cur != NULL)
	{
		list->p_cur = p_cur->p_next;
		return p_cur->p_data;
	}
	return NULL;
}

/**
 * \bref use for sort the single_list
 * \param  
 * \return 
 */
int slist_insertsort(single_list *list, compare_func fn)
{
	single_node *p_node;
	single_node *p_prenode;
	single_node *tmp;
	single_node *p_curnode;
	if(list == NULL || fn == NULL)
	{
		return -1;
	}
	
	p_node = list->p_head;
	p_prenode = NULL;
	
	if(p_node == NULL)
	{
		return 0;
	}
	
	while(p_node->p_next != NULL)
	{
		tmp = list->p_head;
		p_prenode = NULL;
		while(tmp != p_node->p_next)
		{
			if((*fn)(p_node->p_next->p_data, tmp->p_data) < 0)
			{
				p_curnode = p_node->p_next;
				if(p_prenode != NULL)
				{
					p_node->p_next = p_node->p_next->p_next;
					p_prenode->p_next = p_curnode;
					p_curnode->p_next = tmp;				
				}
				else
				{
					p_node->p_next = p_node->p_next->p_next;
					list->p_head = p_curnode;
					p_curnode->p_next = tmp;
				}	
		
				if(p_curnode == list->p_tail)
				{
					list->p_tail = p_node;
				}
				break;
			}
			p_prenode = tmp;
			tmp = tmp->p_next;
		}
		if(tmp == p_node->p_next)
		{
			p_node = p_node->p_next;
		}
		else
		{
			
		}
	}
	return 0;
}

