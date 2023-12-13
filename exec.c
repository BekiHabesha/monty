/*
 * Project Description:📝
 *                               Project Weight: 2 (Two)
 *                           Project Start Date: 📅Dec 12, 2023 🕕6:00 AM
 *                             Project End Date: 📅Dec 15, 2023 🕕6:00 AM
 *                        Checker Released Date: 📅Dec 13, 2023 🕛12:00 AM
 *                    Auto Review Launched Date: 📅@Deadline(Dec 15, 2023)
 *
 * File Details: 📁📖
 *                     File_name: 📋 exec.c file
 *                     Task Type: 🟥 Mandatory Task
 *                   Task Number: 🔢 No
 *                     Functions: 💻 int execute
 *                 Project Title: 📒 0x19.C-Stacks, Queues-LIFO, FIFO
 *             GitHub Repository: 📦 monty
 *                     Directory: 📁 monty and bf
 *                       Created: 📑 On 📅 December 14, 2023
 *                        Author: 🖍️💻 Bereket Dereje Mekkonen👨
 */

#include "monty.h"

/**
 * execute - executes the opcode
 *
 * Author: Bereket Dereje Mekonnen
 *
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poiner to monty file
 * @content: line content
 *
 * Return: no return
 */

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
