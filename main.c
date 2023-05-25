#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
int fd; /* file descriptor */
char temp[1000]; /* buffer to store file content */
char *split[1000]; /* array to store tokens from file */
stack_t **stack; /* pointer to the stack */

/* check if the number of arguments is correct */
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

/* open the file and check for errors */
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
/* read the file content into the buffer and close the file */
read(fd, temp, 1000);
close(fd);
 /* parse the buffer into tokens and store them in the array */
parse_string(temp, split);
/* create a new stack and check for errors */
stack = create_stack();
if (stack == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
/* find and execute the corresponding function for each token */
find_function(stack, split);
/* free the stack and exit */
free_list(stack);
return (0);
}
