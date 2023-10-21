#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void my_free_nodes(void);
void my_print_stack(stack_t **, unsigned int);
void my_add_to_stack(stack_t **, unsigned int);
void my_add_to_qu(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void my_print_top(stack_t **, unsigned int);
void my_pop_top(stack_t **, unsigned int);
void my_nop(stack_t **, unsigned int);
void my_swap_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void my_add_nodes(stack_t **, unsigned int);
void my_sub_nodes(stack_t **, unsigned int);
void my_div_nodes(stack_t **, unsigned int);
void my_ul_nodes(stack_t **, unsigned int);
void my_mod_nodes(stack_t **, unsigned int);

/*String operations*/
void my_print_char(stack_t **, unsigned int);
void my_print_str(stack_t **, unsigned int);
void my_ro(stack_t **, unsigned int);

/*Error hanlding*/
void err_nabil(int error_code, ...);
void mor_err_nabil(int error_code, ...);
void strng_err_nabil(int error_code, ...);
void my_rot(stack_t **, unsigned int);

#endif
