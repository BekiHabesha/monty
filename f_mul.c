/*
 * Project Description:📝
 *                               Project Weight: 2 (Two)
 *                           Project Start Date: 📅Dec 12, 2023 🕕6:00 AM
 *                             Project End Date: 📅Dec 15, 2023 🕕6:00 AM
 *                        Checker Released Date: 📅Dec 13, 2023 🕛12:00 AM
 *                    Auto Review Launched Date: 📅@Deadline(Dec 15, 2023)
 *
 * File Details: 📁📖
 *                     File_name: 📋 f_mul.c file
 *                     Task Type: 📘 Advanced Task
 *                   Task Number: 🔢 No 8
 *                     Functions: 💻 void f_mul
 *                 Project Title: 📒 0x19.C-Stacks, Queues-LIFO, FIFO
 *             GitHub Repository: 📦 monty
 *                     Directory: 📁 monty and bf
 *                       Created: 📑 On 📅 December 14, 2023
 *                        Author: 🖍️💻 Bereket Dereje Mekkonen👨
 */


#include "monty.h"

/**
 * f_mul - It multiplies top two elements of the stack.
 *
 * Author: Bereket Dereje Mekonnen
 *
 * @head: The stack head
 * @counter: The line_number
 *
 * Return: no return
 */

void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
