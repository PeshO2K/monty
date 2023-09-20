#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list.
 * @head: head pointer
 * @n: integer data
 * Return: address of new element or null
*/
void add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head)
	{
		new_node = malloc(sizeof(stack_t));
		if (!new_node)
		{
			print_error(0, MEM_ERR);
		}
		new_node->n = n;
		new_node->next = *head;
		new_node->prev = NULL;
		if (*head)
		{
			(*head)->prev = new_node;
		}
		*head = new_node;
	}
}

/**
 * add_dnodeint_end - adds a new node at the end of list.
 * @head: head pointer
 * @n: integer data
 * Return: the address of the new element, or NULL if it failed
 */

void add_dnodeint_end(stack_t **head, const int n)
{
		stack_t *new;
		stack_t *curr = *head;

		if (head)
		{
			new = malloc(sizeof(stack_t));
			if (!new)
			{
				print_error(0, MEM_ERR);
			}
			for (; curr && curr->next; curr = curr->next)
			{
				;
			}
			new->n = n;
			new->next = NULL;
			new->prev = curr;

			if (*head)
			{
				curr->next = new;
			}
			else
			{
				*head = new;
			}
		}
}


/**
 * dlistint_len - returns the number of elements
 * @h: head pointer
 * Return: number of nodes
*/
size_t dlistint_len(const stack_t *h)
{
	size_t nodes;

	for (nodes = 0; h; nodes++, h = h->next)
	{
		;
	}
	return (nodes);
}

/**
 * print_dlistint - prints all the elements of a stack_t list
 * @h: head pointer
 * @top_only: print top only
 * @mode: Print int type or str
 * Return: # of nodes
*/
size_t print_dlistint(const stack_t *h, unsigned int top_only, strMode mode)
{
	size_t nodes;
	int done = 0;


	for (nodes = 0; h; nodes++, h = h->next)
	{
		if (mode == INT)
		{
			printf("%d\n", h->n);

		}
		else if (mode == STR)
		{
			/*printf("Debugger: str mode\n");*/
			done = print_string(h->n, top_only);
		}


		if (top_only || done)
		{
			break;
		}
	}
	if (mode == STR)
	{
		
		if (top_only && (h == NULL))
		{
			/*printf("debugger: printing top only\n");*/
			/*printf("debugger: empty top\n");*/
			print_error(LINE, "can't %s, stack empty\n", stack.line_num, stack.opcode);
			
		}
		printf("\n");
	}


	return (nodes);
}
/**
 * print_string - Prints a string
 * @top: Pointer to the top of the stack
 * @c: Integer c
 * @top_only: The top only
 *
 * Return: Returns 1 if the string is printed, 0 otherwise.
 *
 * Description: This function prints a string.
 */
int print_string(int c, unsigned int top_only)
{
	if (top_only && (c < 0 || c > 127))
	{
		/*printf("debugger: out of range\n");*/
		print_error(LINE, "can't %s, value out of range\n", stack.line_num, stack.opcode);
	}
	else if (c <= 0 || c > 127)
	{
			return (1);
	}
	printf("%c", c);
	return (top_only);
}
