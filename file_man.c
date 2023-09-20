#include "monty.h"
stack_vars stack = { STACK, NULL, NULL, NULL, NULL, 0, 0 };

/**
 * open_file - Opens a file
 * @filename: The name of the file to be opened
 *
 * Description: opens a file with the given filename.
 */
void open_file(char *filename)
{
	FILE *file;

	file = fopen(filename, "r");
	if (!file)
	{
		print_error(0, "Can't open file <%s>\n", filename);
	}
	read_file(file);
	fclose(file);

}

/**
 * read_file - Reads a file
 * @file: Pointer to the file to be read
 *
 * Description: reads the contents of a file pointed to by 'file'.
 */
void read_file(FILE *file)
{
	size_t len = 0;
	ssize_t n_bytes = getline(&stack.line, &len, file);

	for (stack.line_num = 1; n_bytes != -1; stack.line_num++)
	{
		if (stack.line == NULL)
		{
			print_error(0, MEM_ERR);
		}
		process_line(stack.line);
		/*free(line);*/
	}
	free(stack.line);


}

/**
 * process_line - Processes a line
 * @line: The line to be processed
 *
 * Description: processes a given line 'line'.
 */
void process_line(char *line)
{
	stack.opcode = strtok(line, DELIM);
	if (stack.opcode && (stack.opcode[0] != '#'))
	{
		stack.value = strtok(NULL, DELIM);
		get_op_func();
	}
}

/**
 * get_op_func - Gets an operation function
 *
 * Description: retrieves an operation function.
 */
void get_op_func(void)
{
	int i;

	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _switch_mode},
		{"queue", _switch_mode},
		{NULL, NULL}
	};

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(op_funcs[i].opcode, stack.opcode) == 0)
		{
			op_funcs[i].f(&(stack.top), stack.line_num);
			return;
		}
	}
	print_error(2, "unknown instruction %s\n", stack.line_num, stack.opcode);

}

/**
 * is_integer - Checks if a string is an integer
 * @str: The string to be checked
 *
 * Return: Returns 1 if the string is an integer, 0 otherwise.
 *
 * Description: checks if a given string 'str' is an integer.
 */
int is_integer(char *str)
{

	if (*str == '-')
	{
		++str;
	}
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		++str;
	}
	return (1);
}
