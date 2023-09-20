#include "monty.h"

/**
 * _sub - Subtracts top element from second top element of stack
 * @top: Double pointer to top of stack
 * @line_num: line number
 *
 * Description: subtracts top element from second top element of stack.
 */
void _sub(stack_t **top, unsigned int line_num)
{
	compute(SUB, top, line_num);
}

/**
 * _mul - Multiplies top two elements of stack
 * @top: Double pointer to top of stack
 * @line_num: line number
 *
 * Description: multiplies top two elements of stack.
 */
void _mul(stack_t **top, unsigned int line_num)
{
	compute(MUL, top, line_num);
}
/**
 * _div - Divides second top element by top element of stack
 * @top: Double pointer to top of stack
 * @line_num: line number
 *
 * Description: divides second top element by top element of stack.
 */
void _div(stack_t **top, unsigned int line_num)
{
	compute(DIV, top, line_num);
}

/**
 * _add - Adds top two elements of stack
 * @top: Double pointer to top of stack
 * @line_num: line number
 *
 * Description: adds top two elements of stack.
 */
void _add(stack_t **top, unsigned int line_num)
{
	compute(ADD, top, line_num);
}

/**
 * _mod - Computes modulus of second top element by top element of stack
 * @top: Double pointer to top of stack
 * @line_num: line number
 *
 * Description: computes modulus of second top element by top element of stack.
 */
void _mod(stack_t **top, unsigned int line_num)
{
	compute(MOD, top, line_num);
}
