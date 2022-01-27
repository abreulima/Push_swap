#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

int max(int size_a, int size_b)
{
	if (size_a < size_b)
	{
		return (size_b);
	}
	return (size_a);
}

void show_numbers(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int i;
	int max_variable;

	i = 0;
	max_variable = max(size_a, size_b);
	while (i < max_variable)
	{
		if (size_a > i)
			printf("%d ", stack_a[i]);
		if (size_b > i)
			printf("%d ", stack_b[i]);
		printf("\n");
		i++;
	}
	printf("- -\n");
	printf("a b\n");
}

void push(int *source, int *destination, int *size_source, int *size_destination)
{
	int i;

	if (*size_source == 0)
	{
		return;
	}
	*size_destination = *size_destination + 1;
	for(i = *size_destination; 0 < i; i--)
	{
		destination[i] = destination[i - 1];
	}
	destination[0] = source[0];
	for(i = 0; i < *size_source; i++)
	{
		source[i] = source[i + 1];
	}
	*size_source = *size_source - 1;
}

void swap(int *stack, int size)
{
	int aux;

	if (size <= 1)
	{
		return;
	}
	aux = stack[0];
	stack[0] = stack[1];
	stack[1] = aux;
}

void rotate(int *stack, int size)
{
	int aux;
	int i;

	if (size <= 1)
	{
		return;
	}
	aux = stack[0];
	for (i = 0; i < size - 1; i++)
	{
		stack[i] = stack[i + 1];
	}
	stack[size - 1] = aux;
}

void reverse_rotate(int *stack, int size)
{
	int aux;
	int i;

	if (size <= 1)
	{
		return;
	}
	aux = stack[size - 1];
	for (i = size; i > 0; i--)
	{
		stack[i] = stack[i - 1];
	}
	stack[0] = aux;
}

int main(int argc, char **argv)
{
	int n_elements;
	int *a;
	int *b;
	int size_a;
	int size_b;
	int i;
	char commands[4];

	if (argc == 1)
	{
		printf("Oh no, we have only 1 parameter!\n");
		exit(1);
	}

	n_elements = argc - 1;
	a = malloc(n_elements * sizeof(int));
	b = malloc(n_elements * sizeof(int));
	size_a = n_elements;
	size_b = 0;

	i = 0;
	while (i < n_elements)
	{
		a[i] = atoi(argv[i + 1]);
		i++;
	}
	show_numbers(a, b, size_a, size_b);
	// printf("-\n");
	// printf("a\n");
	// printf("-\n");
	// swap(a, size_a);
	// show_numbers(a, size_a);
	while (1)
	{
		scanf("%s", commands);
		if (!strncmp(commands, "sa", 2))
		{
			swap(a, size_a);
			if (DEBUG)
				show_numbers(a, b, size_a, size_b);
		}
		else if (!strncmp(commands, "sb", 2))
		{
			swap(b, size_b);
			if (DEBUG)
				show_numbers(a, b, size_a, size_b);
		}
		else if (!strncmp(commands, "ss", 2))
		{
			swap(a, size_a);
			swap(b, size_b);
			if (DEBUG)
				show_numbers(a, b, size_a, size_b);
		}
		else if (!strncmp(commands, "pa", 2))
		{
			push(b, a, &size_b, &size_a);
			if (DEBUG)
				show_numbers(a, b, size_a, size_b);
		}
		else if (!strncmp(commands, "pb", 2))
		{
			push(a, b, &size_a, &size_b);
			if (DEBUG)
				show_numbers(a, b, size_a, size_b);
		}
		else if (!strncmp(commands, "ra", 2))
		{
			rotate(a, size_a);
			if (DEBUG)
				show_numbers(a, b, size_a, size_b);
		}
		else if (!strncmp(commands, "rb", 2))
		{
			rotate(b, size_b);
			if (DEBUG)
				show_numbers(a, b, size_a, size_b);
		}
		else if (!strncmp(commands, "rra", 3))
		{
			reverse_rotate(a, size_a);
			if (DEBUG)
				show_numbers(a, b, size_a, size_b);
		}
		else if (!strncmp(commands, "rrb", 3))
		{
			reverse_rotate(b, size_b);
			if (DEBUG)
				show_numbers(a, b, size_a, size_b);
		}
		else if (!strncmp(commands, "rrr", 3))
		{
			reverse_rotate(a, size_a);
			reverse_rotate(b, size_b);
			if (DEBUG)
				show_numbers(a, b, size_a, size_b);
		}
		else if (!strncmp(commands, "rr", 2))
		{
			rotate(a, size_a);
			rotate(b, size_b);
			if (DEBUG)
				show_numbers(a, b, size_a, size_b);
		}
	}
	return (0);
}