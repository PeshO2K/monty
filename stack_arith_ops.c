#include "monty.h"

/**
 * _sub - Subtracts the top element from the second top element of the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: This function subtracts the top element from the second top element of the stack.
 */
void _sub(stack_t **top, unsigned int line_num)
{
	compute(SUB, top, line_num);
}

/**
 * _mul - Multiplies the top two elements of the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: This function multiplies the top two elements of the stack.
 */
void _mul(stack_t **top, unsigned int line_num)
{
	compute(MUL, top, line_num);
}
/**
 * _div - Divides the second top element by the top element of the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: This function divides the second top element by the top element of the stack.
 */
void _div(stack_t **top, unsigned int line_num)
{
	compute(DIV, top, line_num);
}

/**
 * _add - Adds the top two elements of the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: This function adds the top two elements of the stack.
 */
void _add(stack_t **top, unsigned int line_num)
{
	compute(ADD, top, line_num);
}

/**
 * _mod - Computes the modulus of the second top element by the top element of the stack
 * @top: Double pointer to the top of the stack
 * @line_num: The line number
 *
 * Description: This function computes the modulus of the second top element by the top element of the stack.
 */
void _mod(stack_t **top, unsigned int line_num)
{
	compute(MOD, top, line_num);
}
