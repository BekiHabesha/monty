*
 * Project Description:📝
 *                               Project Weight: 2 (Two)
 *                           Project Start Date: 📅Dec 12, 2023 🕕6:00 AM
 *                             Project End Date: 📅Dec 15, 2023 🕕6:00 AM
 *                        Checker Released Date: 📅Dec 13, 2023 🕛12:00 AM
 *                    Auto Review Launched Date: 📅@Deadline(Dec 15, 2023)
 *
 * File Details: 📁📖
 *                     File_name: 📋 f_sub.c file
 *                     Task Type: 📘 Advanced Task
 *                   Task Number: 🔢 No 6
 *                     Functions: 💻 void f_sub
 *                 Project Title: 📒 0x19.C-Stacks, Queues-LIFO, FIFO
 *             GitHub Repository: 📦 monty
 *                     Directory: 📁 monty and bf
 *                       Created: 📑 On 📅 December 14, 2023
 *                        Author: 🖍️💻 Bereket Dereje Mekkonen👨
 */

#include "monty.h"

/**
 * f_sub- It sustration node to the head stack
 *
 * Author: Bereket Dereje Mekonnen
 *
 * @head: The stack head
 *
 * @counter: The line_number
 *
 * Return: no return
 */

void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
