#include "monty.h"


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

/**
 * pall - function prints all of stack
 * @stk: top of stack
 * @linenum: line number
 * Return: void
 */
void pall(stack_t **stk, unsigned int linenum)
{
	stack_t *print;

	if (stk == NULL)
	{
		printf("L%d: invalid stack\n", linenum);
		exit(EXIT_FAILURE);
	}

	print = *stk;

	while (print != NULL)
	{
		printf("%d\n", print->n);
		print = print->next;
	}
}

/**
 * pop - delets top of stack
 * @s: pointer to stack
 * @n: line number
 */
void pop(stack_t **s, unsigned int n)
{
	stack_t *temp;
	(void) s;
	(void) n;

	temp = *s;

	if (!*s)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", n);
		free(s);
		exit(EXIT_FAILURE);
	}
	if (!temp->next)
	{
		free(*s);
		*s = NULL;
		return;
	}
	else
	{
		(*s)->next->prev = NULL;
		*s = (*s)->next;
	}
	free(temp);
}
/**
 * pint - function prints the value at the top of the stack
 * @stk: stack
 * @linenum: line number
 * Return: void
 */
void pint(stack_t **stk, unsigned int linenum)
{
	if (stk == NULL || *stk == NULL)
	{
		printf("L%d: can't pint, stack empty\n", linenum);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stk)->n);
}

/**
 * swap - swapping first two elements on top of stack
 * @stk: stack
 * @linenum: line number
 * Return: void
 */
void swap(stack_t **stk, unsigned int linenum)
{
	int temp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", linenum);
		free_list(stk);
		exit(EXIT_FAILURE);
	}
	temp = (*stk)->n;
	(*stk)->n = (*stk)->next->n;
	(*stk)->next->n = temp;
}
