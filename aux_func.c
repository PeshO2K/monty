#include "monty.h"
/**
 * print_error - Prints a custom error message to stderr and exits.
 * @mode: The mode of the error message (ERROR, USAGE, LINE).
 * @format: The format string for the error message.
 * @...: The arguments for the format string.
 *
 * Description:  takes a mode, a format string, and a variable
 * number of arguments. It uses the mode to determine the type of error message
 * to print (ERROR, USAGE, LINE). It then uses the format string and arguments
 * to print a custom error message to stderr. After printing the error message,
 * it exits the program with a status code of EXIT_FAILURE.
 */

void print_error(eMode mode, const char *format, ...) {
	va_list args;

	va_start(args, format);

	switch (mode)
	{
		case ERROR:
			fprintf(stderr, "Error: ");
			break;
		case USAGE:
			fprintf(stderr, "USAGE: ");
			break;
		case LINE:
			fprintf(stderr, "L<%u>: ", va_arg(args, unsigned int));
			break;
	}

	vfprintf(stderr, format, args);
	va_end(args);
	my_exit(EXIT_FAILURE);
}

/**
 * my_exit - Exits the program with a given status code.
 * @status: The status code to exit with.
 *
 * Description:  takes an integer status code as an argument and
 * exits the program with that status code. The status code is returned to the
 * operating system. By convention, a status code of 0 usually indicates
 * success, while a non-zero status code indicates an error.
 */
void my_exit(int status)
{
	/*free_resources();*/
	if (stack.line)
	{
		free(stack.line);
	}
	free_dlistint(stack.top);
	exit(status);
}

/**
 * free_dlistint - frees a stack_t list.
 * @head: head pointer
*/
void free_dlistint(stack_t *head)
{
	if (head)
	{
		free_dlistint(head->next);
		free(head);
	}
}

/**
 * compute - Performs a computation based on the operator sign
 * @sign: The operator sign
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description:  performs a computation based on the operator sign.
 */
void compute(operator sign, stack_t **top, unsigned int line_num)
{
	stack_t *result_node;
	
	int (*calculator[])(int f_n, int s_n) = 
	{
		add_op, sub_op, mul_op,
		div_op, mod_op
	};

	len_check(*top);

	result_node = (*top)->next;
	result_node->n = (calculator[sign])((*top)->n, (*top)->next->n);
	_pop(top, line_num);

}

/**
 * len_check - Checks the length of a doubly linked list
 * @top: Pointer to the top of the stack
 *
 * Description:  checks the length of a doubly linked list.
 */
void len_check(const stack_t *top)
{
	size_t len = dlistint_len(top);

	if ( len < 2)
	{
		print_error(LINE, LEN_ERR, stack.line_num, stack.opcode);
	}

}
