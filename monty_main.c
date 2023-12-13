/*
 * Project Description:📝
 *                               Project Weight: 2 (Two)
 *                           Project Start Date: 📅Dec 12, 2023 🕕6:00 AM
 *                             Project End Date: 📅Dec 15, 2023 🕕6:00 AM
 *                        Checker Released Date: 📅Dec 13, 2023 🕛12:00 AM
 *                    Auto Review Launched Date: 📅@Deadline(Dec 15, 2023)
 *
 * File Details: 📁📖
 *                     File_name: 📋 monty_main.c file
 *                     Task Type: 🟥 Mandatory Task
 *                   Task Number: 🔢 Main
 *                     Functions: 💻 int main
 *                 Project Title: 📒 0x19.C-Stacks, Queues-LIFO, FIFO
 *             GitHub Repository: 📦 monty
 *                     Directory: 📁 monty and bf
 *                       Created: 📑 On 📅 December 14, 2023
 *                        Author: 🖍️💻 Bereket Dereje Mekkonen👨
 */

#include "monty.h"
#include <stdio.h>
#define _GNU_SOURCE
#include <stdlib.h>

ssize_t getline(char **content, size_t *len, FILE *file);
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - The function for monty code interpreter
 *
 * Author: Bereket Dereje Mekonnen
 *
 * @argc: The number of arguments
 * @argv: The monty file location
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char *content = NULL;
	FILE *file;
	size_t len = 0;
	ssize_t nread = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (nread > 0)
	{
		content = NULL;
		nread = getline(&content, &len, file);
		bus.content = content;
		counter++;
		if (nread > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
