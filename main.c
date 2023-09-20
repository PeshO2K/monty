#include "monty.h"
/**
 * main - Entry point of the program
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: Returns 0 on success, a non-zero value otherwise.
 *
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error(1, "monty file\n");
	}
	open_file(argv[1]);


	my_exit(EXIT_SUCCESS);
	return (0);
}

/**
 * _nop - Does nothing
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: This function does nothing.
 */
void _nop(stack_t **top, unsigned int line_num)
{
	(void) top;
	(void) line_num;
}
