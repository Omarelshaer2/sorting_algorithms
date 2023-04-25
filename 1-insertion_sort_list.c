#include "sort.h"

/**
 * swap_nodes - Interchanges two adjacent nodes in a doubly-linked list
 * @first_node: Pointer to the first node
 * @second_node: Pointer to the second node
 *
 * This function interchanges two adjacent nodes in a doubly-linked list.
 * It adjusts the pointers of the nodes as well as their surrounding nodes.
 */
void swap_nodes(listint_t *first_node, listint_t *second_node)
{
	if (first_node->prev)
		first_node->prev->next = second_node;
	if (second_node->next)
		second_node->next->prev = first_node;
	first_node->next = second_node->next;
	second_node->prev = first_node->prev;
	first_node->prev = second_node;
	second_node->next = first_node;
}

/**
 * insertion_sort_list - Organizes a doubly-linked
 *list using the insertion sort technique
 * @list_head: Pointer to the head node's address
 *
 * This function organizes a doubly-linked list using the insertion sort technique.
 * It traverses the list, switching adjacent nodes when required.
 * The list is printed after each node switch.
 */
void insertion_sort_list(listint_t **list_head)
{
	listint_t *current, *temp;

	if (!list_head || !*list_head || !(*list_head)->next)
		return;
	current = (*list_head)->next;
	while (current)
	{
		temp = current;
		current = current->next;
		while (temp && temp->prev)
		{
			if (temp->prev->n > temp->n)
			{
				swap_nodes(temp->prev, temp);
				if (!temp->prev)
					*list_head = temp;
				print_list((const listint_t *)*list_head);
			}
			else
				temp = temp->prev;
		}
	}
}
