#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

stack_t *stack = NULL; // Global variable to represent the stack

/**
 * push - Pushes an element onto the stack
 * @value: The value to push onto the stack
 */
void push(int value) {
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL) {
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = stack;
	if (stack != NULL) {
		stack->prev = new_node;
	}
	stack = new_node;
}

/**
 * pall - Prints all the values on the stack
 */
void pall(void) {
	stack_t *current = stack;
	while (current != NULL) {
		printf("%d\n", current->n);
		current = current->next;
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "USAGE: monty file\n");
		return EXIT_FAILURE;
	}

	char opcode[5];
	int value;
	while (fscanf(file, "%4s %d", opcode, &value) == 2) {
		if (strcmp(opcode, "push") == 0) {
			push(value);
		} else if (strcmp(opcode, "pall") == 0) {
			pall();
		} else {
			fprintf(stderr, "Error: unknown instruction %s\n", opcode);
			 return EXIT_FAILURE;
		}
	}

	fclose(file);
	return EXIT_SUCCESS;
}
