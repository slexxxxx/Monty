#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	my_free_nodes();
	return (0);
}

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err_nabil(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * my_free_nodes - Frees nodes in the stack.
 */
void my_free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * my_add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void my_add_to_qu(stack_t **new_noe, __attribute__((unused))unsigned int ln)
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
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_noe;
	(*new_noe)->prev = tmp;

}
