#include "monty.h"

/**
 * execute_opcode - Executes the opcode
 * @opcode: The opcode to execute
 * @stack: Double pointer to the stack
 * @line_number: Line number
 *
 * Return: 0 on success, -1 on failure
 */
int execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
    int n;
    char *arg;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    if (strcmp(opcode, "push") == 0)
    {
        arg = strtok(NULL, " \t\n");
        if (arg == NULL || !is_number(arg))
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            return -1;
        }
        n = atoi(arg);
        push(stack, line_number, n);
        return 0;
    }

    for (int i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return 0;
        }
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    return -1;
}

/**
 * is_number - Checks if a string is a valid number
 * @str: The string to check
 *
 * Return: 1 if the string is a valid number, 0 otherwise
 */
int is_number(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

/**
 * free_stack - Frees a stack
 * @stack: The stack to free
 */
void free_stack(stack_t *stack)
{
    stack_t *temp;

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}
