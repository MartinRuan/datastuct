#include "single_list.h"
struct _single_node
{
	void *p_data;
	struct _single_node p_next;
};
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
	if(single_list == NULL || fn == NULL)
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
		while(tmp != p_node->next)
		{
			if((*fn)(p_node->p_next->p_data, tmp->p_data) < 0)
			{
				p_curnode = p_node->next;
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

