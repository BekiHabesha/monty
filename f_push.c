/*
 * Project Description:📝
 *                               Project Weight: 2 (Two)
 *                           Project Start Date: 📅Dec 12, 2023 🕕6:00 AM
 *                             Project End Date: 📅Dec 15, 2023 🕕6:00 AM
 *                        Checker Released Date: 📅Dec 13, 2023 🕛12:00 AM
 *                    Auto Review Launched Date: 📅@Deadline(Dec 15, 2023)
 *
 * File Details: 📁📖
 *                     File_name: 📋 f_push.c file
 *                     Task Type: 🟥 Mandatory Task
 *                   Task Number: 🔢 No 0
 *                     Functions: 💻 void f_push
 *                 Project Title: 📒 0x19.C-Stacks, Queues-LIFO, FIFO
 *             GitHub Repository: 📦 monty
 *                     Directory: 📁 monty and bf
 *                       Created: 📑 On 📅 December 14, 2023
 *                        Author: 🖍️💻 Bereket Dereje Mekkonen👨
 */

#include "monty.h"

/**
 * f_push - It add node to the stack
 *
 * Author: Bereket Dereje Mekonnen
 *
 * @head: The stack head
 * @counter: The line_number
 *
 * Return: no return
 */

void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
