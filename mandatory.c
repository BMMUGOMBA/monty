#include "monty.h"

/**
 * pall - print all nodes in stack
 * @s: pointer to stack
 * @n: line numnber
 */
void pall(stack_t **s, unsigned int n)
{
	stack_t *temp;
	(void) n;

	temp = *s;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - prints top of stack
 * @s: pointer to stack
 * @n: line number
 */
void pint(stack_t **s, unsigned int n)
{
	(void) s;
	(void) n;

	if (!*s)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n);
		free_list(s);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*s)->n);
}



/**
 * push - adds new node to the stack
 * @s: pointer to stack
 * @n: line number
 * @value: value of new node
 */
void push(stack_t **s, unsigned int n, int value)
{
	stack_t *new;
	stack_t *current;

	(void) n;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->next = NULL;
	new->prev = NULL;
	if (*s == NULL)
		*s = new;
	else if (!g.stoq) /* is stack: add to top */
	{
		new->next = *s;
		(*s)->prev = new;
		*s = new;
	}
	else /* is queue: add to bottom */
	{
		current = *s;
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
}
