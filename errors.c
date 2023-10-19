#include "monty.h"

/**
 * my_err - Prints appropriate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => The user does not provide a file or provides more than one file to the program.
 * (2) => The file provided is not a valid file that can be opened or read.
 * (3) => The file provided contains an unrecognized instruction.
 * (4) => When the program is unable to allocate more memory.
 * (5) => When the parameter passed to the "push" instruction is not an integer.
 * (6) => When the stack is empty for the "pint" operation.
 * (7) => When the stack is empty for the "pop" operation.
 * (8) => When the stack is too short for the operation.
 */
void err_nabil(int error_ce, ...)
{
	va_list ag;
	char *ol;
	int line_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			line_num = va_arg(ag, int);
			ol = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, ol);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * my_more_err - handles errors.
 * @error_code: The error codes are the following:
 * (6) => When the stack is empty for the "pint" operation.
 * (7) => When the stack is empty for the "pop" operation.
 * (8) => When the stack is too short for the operation.
 * (9) => Division by zero.
 */
void mor_err_nabil(int error_code, ...)
{
	va_list ag;
	char *ol;
	int line_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			line_num = va_arg(ag, unsigned int);
			ol = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, ol);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void strng_err_nabil(int error_code, ...)
{
	va_list ag;
	int line_num;

	va_start(ag, error_code);
	line_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
