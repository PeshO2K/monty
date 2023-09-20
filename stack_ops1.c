#include "monty.h"
/**
 * _push - Pushes an element to the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: This function pushes an element to the top of the stack.
 */
void _push(stack_t **top, unsigned int line_num)
{
	void (*push_mode[])(stack_t **top, const int n) = {
		add_dnodeint,
		add_dnodeint_end
		};
	(void) top;
	(void) line_num;
	if (stack.value && is_integer(stack.value))
	{
		stack.n = atoi(stack.value);
	}
	else
	{
		print_error(LINE, "usage: push integer\n", stack.line_num);
	}
	(push_mode[stack.mode])(&stack.top, stack.n);
}

/**
 * _pchar - Prints the char at the top of the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: This function prints the char at the top of the stack.
 */
void _pchar(stack_t **top, unsigned int line_num)
{
	(void) line_num;
	/*printf("Debugger: in pchar\n");*/
	print_dlistint(*top, 1, STR);
}

/**
 * _switch_mode - Switches the mode of the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: This function switches the mode of the stack.
 */
void _switch_mode(stack_t **top, unsigned int line_num)
{
	(void) top;
	(void) line_num;
	if (strcmp(stack.opcode, "stack") == 0)
	{
		stack.mode = STACK;
	}
	else
	{
		stack.mode = QUEUE;
	}
}

/**
 * _rotl - Rotates the stack to the left
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: This function rotates the stack to the left.
 */
void _rotl(stack_t **top, unsigned int line_num)
{
	stack_t *new_top;
	stack_t *old_top;

	(void) line_num;
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}

	new_top = (*top)->next;
	old_top = *top;

	while (old_top->next != NULL)
	{
		old_top = old_top->next;
	}

	old_top->next = *top;
	(*top)->prev = old_top;
	(*top)->next = NULL;
	new_top->prev = NULL;
	*top = new_top;
}

/**
 * _rotr - Rotates the stack to the right
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: This function rotates the stack to the right.
 */
void _rotr(stack_t **top, unsigned int line_num)
{
	stack_t *new_top;
	stack_t *old_top;

	(void) line_num;
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}

	new_top = *top;
	old_top = NULL;

	while (new_top->next != NULL)
	{
		old_top = new_top;
		new_top = new_top->next;
	}

	old_top->next = NULL;
	new_top->prev = NULL;
	new_top->next = *top;
	(*top)->prev = new_top;
	*top = new_top;
}
