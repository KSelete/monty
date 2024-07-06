#include "monty.h"

/**
 * div_top_two - Divides the second top element of the stack by the top element
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number where the error occurred
 *
 * Description: This function removes the top element of the stack,
 * divides the new top element by the removed element's value, and updates the stack.
 */
void div_top_two(stack_t **stack, unsigned int line_number)
{
    stack_t *top, *next;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        fclose(file);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        fclose(file);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    next = top->next;
    next->n /= top->n;
    *stack = next;
    next->prev = NULL;
    free(top);
}
