#include "monty.h"
/**
 * add_op - Performs addition operation
 * @a: The first integer
 * @b: The second integer
 *
 * Return: Returns the result of the addition operation.
 *
 * Description: This function adds two integers 'a' and 'b'.
 */
int add_op(int a, int b)
{
	return (a + b);
}

/**
 * sub_op - Performs subtraction operation
 * @a: The first integer
 * @b: The second integer
 *
 * Return: Returns the result of the subtraction operation.
 *
 * Description: This function subtracts 'b' from 'a'.
 */
int sub_op(int a, int b)
{
	return (b - a);
}

/**
 * mul_op - Performs multiplication operation
 * @a: The first integer
 * @b: The second integer
 *
 * Return: Returns the result of the multiplication operation.
 *
 * Description: This function multiplies 'a' and 'b'.
 */
int mul_op(int a, int b)
{
	return (a * b);
}

/**
 * mod_op - Performs modulus operation
 * @a: The first integer
 * @b: The second integer
 *
 * Return: Returns the result of the modulus operation.
 *
 * Description: This function computes the modulus of 'a' by 'b'.
 */
int mod_op(int a, int b)
{
	if (a)
	{
		return (b % a);
	}
	print_error(LINE, "division by zero\n", stack.line_num);
	return (0);
}

/**
 * div_op - Performs division operation
 * @a: The first integer
 * @b: The second integer
 *
 * Return: Returns the result of the division operation.
 *
 * Description: This function divides 'a' by 'b'.
 */
int div_op(int a, int b)
{
	if (a)
	{
		return (b / a);
	}
	print_error(LINE, "division by zero\n",stack.line_num);
	return (0);
}
