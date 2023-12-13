#ifndef MONTY_H_
#define MONTY_H_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - The doubly linked list representation
 *                  of a stack(or queue)
 *
 * Author: Bereket Dereje Mekonnen
 *
 * @n: integer
 * @prev: points to the previous element of the stack(queue)
 * @next: points to the next element of the stack(queue)
 *
 * Description: doubly linked list node structure
 *              for stack, queues, LIFO, FIFO project
 *
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 *
 * Author: Bereket Dereje Mekonnen
 *
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 *              for stack, queues, LIFO, FIFO project
 *
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -args, file, line content
 *
 * Author: Bereket Dereje Mekonnen
 *
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 *
 * Description: carries values through the program
 *
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

ssize_t getstdin(char **lineptr, int file);

char  *clean_line(char *content);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);

int execute(char *content, stack_t **head, unsigned int counter, FILE *file);

void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
void f_pop(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);

#endif /* MONTY_H_ */