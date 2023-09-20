#include "monty.h"
/**
 * _pstr - Prints the string starting at the top of the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: prints the string starting at the top of the stack.
 */
void _pstr(stack_t **top, unsigned int line_num)
{
	(void) line_num;
	print_dlistint(*top, 0, STR);
}

/**
 * _pall - Prints all elements of the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: prints all the elements of the stack.
 */
void _pall(stack_t **top, unsigned int line_num)
{
	(void) line_num;
	print_dlistint(*top, 0, INT);
}

/**
 * _pint - Prints the integer at the top of the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: prints the integer at the top of the stack.
 */
void _pint(stack_t **top, unsigned int line_num)
{
	if (*top == NULL)
	{
		print_error(LINE, "can't %s, stack empty\n", line_num, stack.opcode);
	}
	print_dlistint(*top, 1, INT);
}

/**
 * _pop - Removes the top element of the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: removes the top element of the stack.
 */
void _pop(stack_t **top, unsigned int line_num)
{
	stack_t *next;

	/**error handling goes here*/
	if (*top == NULL)
	{
		print_error(LINE, "can't %s an empty stack\n", line_num, stack.opcode);
	}

	next = (*top)->next;
	if (next)
	{
		next->prev = NULL;
	}
	free(*top);
	*top = next;
}

/**
 * _swap - Swaps the top two elements of the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: swaps the top two elements of the stack.
 */
void _swap(stack_t **top, unsigned int line_num)
{

	stack_t *first_top;
	stack_t *second_top;

	(void) line_num;

	len_check(*top);
	first_top = *top;
	second_top = first_top->next;

	first_top->next = second_top->next;
	second_top->next = first_top;
	first_top->prev = second_top;
	if (first_top->next)
	{
		first_top->next->prev = first_top;
	}
	second_top->prev = NULL;
	*top = second_top;
}
