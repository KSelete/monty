#include "monty.h"

/**
 * add_top_two - Adds the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number where the error occurred
 *
 * Description: This function removes the top element of the stack,
 * adds its value to the new top element, and updates the stack.
 */
void add_top_two(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *next;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        fclose(file);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    next = top->next;
    next->n += top->n;
    *stack = next;
    next->prev = NULL;
    free(top);
}
