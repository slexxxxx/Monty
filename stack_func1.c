#include "monty.h"


/**
 * my_add_to_stack - Adds a node to the stack.
 * @new_noe: Pointer to the new node to be added to the stack.
 * @ln: Integer representing the line number of the opcode.
 */
void my_add_to_stack(stack_t **new_noe, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_noe == NULL || *new_noe == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_noe;
		return;
	}
	tmp = head;
	head = *new_noe;
	head->next = tmp;
	tmp->prev = head;
}


//**
 * pop_top - Removes the top node from the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_numberr: Integer representing the line number of the opcode.
 *
 */
void my_print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * print_top - Prints the value of the top node in the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_numberr: Integer representing the line number of the opcode.
 */
void my_pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void my_print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
