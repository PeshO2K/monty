#ifndef MONTY_H_
#define MONTY_H_
#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define DELIM " \n"
#define MEM_ERR "malloc failed\n"
#define LEN_ERR "can't %s, stack too short\n"
#define RANGE_ERR "can't %s, value out of range\n"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * enum eMode - Enumeration of different modes
 * @ERROR: Error mode
 * @USAGE: Usage mode
 * @LINE: Line mode
 */
typedef enum eMode
{
	ERROR,
	USAGE,
	LINE
} eMode;

/**
 * enum opMode - Enumeration of operation modes
 * @STACK: Stack mode
 * @QUEUE: Queue mode
 */
typedef enum opMode
{
	STACK,
	QUEUE
} opMode;

/**
 * enum strMode - Enumeration of string modes
 * @INT: Integer mode
 * @STR: String mode
 */
typedef enum strMode
{
	INT,
	STR
} strMode;

/**
 * struct stack_vars_s - contains stack variables
 * @mode: Operation mode
 * @top: Pointer to the top of the stack
 * @line: Line string
 * @opcode: Opcode string
 * @value: Value string
 * @n: Integer n
 * @line_num: Line number
 *
 * Description: contains various variables related to a stack.
 */
typedef struct stack_vars_s
{
	opMode mode;
	stack_t *top;
	char *line;
	char *opcode;
	char *value;
	int n;
	unsigned int line_num;

} stack_vars;

extern stack_vars stack;

/**
 * enum operator - Enumeration of operators
 * @ADD: Addition operator
 * @SUB: Subtraction operator
 * @MUL: Multiplication operator
 * @DIV: Division operator
 * @MOD: Modulus operator
 */
typedef enum operator
{
	ADD,
	SUB,
	MUL,
	DIV,
	MOD
} operator;

/*aux_func.c*/
void print_error(eMode mode, const char *format, ...);
void my_exit(int status);

/*file_man.c*/
void open_file(char *filename);
void read_file(FILE *file);
void process_line(char *line);
void get_op_func(void);
int is_integer(char *str);

void add_dnodeint(stack_t **head, const int n);
void add_dnodeint_end(stack_t **head, const int n);

int add_op(int a, int b);
int sub_op(int a, int b);
int mul_op(int a, int b);
int mod_op(int a, int b);
int div_op(int a, int b);

void _push(stack_t **top, unsigned int line_num);
void _pall(stack_t **top, unsigned int line_num);
void _pint(stack_t **top, unsigned int line_num);
void _pop(stack_t **top, unsigned int line_num);
void _swap(stack_t **top, unsigned int line_num);
void _add(stack_t **top, unsigned int line_num);
void _nop(stack_t **top, unsigned int line_num);
void _sub(stack_t **top, unsigned int line_num);
void _mul(stack_t **top, unsigned int line_num);
void _mod(stack_t **top, unsigned int line_num);
void _div(stack_t **top, unsigned int line_num);
void _pstr(stack_t **top, unsigned int line_num);
void _pchar(stack_t **top, unsigned int line_num);
void _rotr(stack_t **top, unsigned int line_num);
void _rotl(stack_t **top, unsigned int line_num);
void _switch_mode(stack_t **top, unsigned int line_num);
int print_string(int c, unsigned int top_only);

size_t print_dlistint(const stack_t *h, unsigned int top_only, strMode mode);
size_t dlistint_len(const stack_t *h);
void free_dlistint(stack_t *head);

int is_integer(char *str);
void len_check(const stack_t *top);

void compute(operator sign, stack_t **top, unsigned int line_num);


#endif
