#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft/ft_atoi.h"
#include "libft/ft_strncmp.h"
// #include "libft/libft.h"

#define DEBUG 0



int max(int size_a, int size_b)
{
	if (size_a < size_b)
	{
		return (size_b);
	}
	return (size_a);
}

void ft_show_numbers(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int i;
	int max_variable;

	i = 0;
	max_variable = max(size_a, size_b);
	while (i < max_variable)
	{
		if (size_a > i)
			printf("%d ", stack_a[i]);
		else
			printf("  ");
		if (size_b > i)
			printf("%d ", stack_b[i]);
		printf("\n");
		i++;
	}
	printf("- -\n");
	printf("a b\n");
}

void ft_push(int *source, int *destination, int *size_source, int *size_destination)
{
	int i;

	if (*size_source == 0)
	{
		return;
	}
	*size_destination = *size_destination + 1;
	i = *size_destination;
	while(0 < i)
	{
		destination[i] = destination[i - 1];
		i--;
	}
	destination[0] = source[0];
	i = 0;
	while(i < *size_source)
	{
		source[i] = source[i + 1];
		i++;
	}
	*size_source = *size_source - 1;
}

void ft_swap(int *stack, int size)
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

void ft_rotate(int *stack, int size)
{
	int aux;
	int i;

	if (size <= 1)
	{
		return;
	}
	aux = stack[0];
	i = 0;
	while(i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = aux;
}

void ft_reverse_rotate(int *stack, int size)
{
	int aux;
	int i;

	if (size <= 1)
	{
		return;
	}
	aux = stack[size - 1];
	i = size;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = aux;
}

int ft_lowest(int *stack, int size)
{
	int	lowest;
	int i;

	lowest = 2147483647;
	for (i = 0; i < size; i++)
	{
		if (stack[i] < lowest)
			lowest = stack[i];
	}
	return (lowest);
}

void ft_lowest_top(int *stack, int size, int lowest)
{
	if (size == 0)
	{
		return ;
	}
	else if (lowest == stack[0])
	{
		return ;
	}
	while (lowest != stack[0])
	{
		ft_rotate(stack, size);
		printf("ra\n");
	}
}

void ft_simple_sort(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	while (*size_a != 0)
	{
		ft_lowest_top(stack_a, *size_a, ft_lowest(stack_a, *size_a));
		ft_push(stack_a, stack_b, size_a, size_b);
		printf("pb\n");
	}
	while (*size_b != 0)
	{
		ft_push(stack_b, stack_a, size_b, size_a);
		printf("pa\n");
	}
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
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ft_simple_sort(a, b, &size_a, &size_b);
		return (0);
	// ft_show_numbers(a, b, size_a, size_b);
	while (1)
	{
		scanf("%s", commands);
		if (!ft_strncmp(commands, "sa", 2))
		{
			ft_swap(a, size_a);
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "sb", 2))
		{
			ft_swap(b, size_b);
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "ss", 2))
		{
			ft_swap(a, size_a);
			ft_swap(b, size_b);
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "pa", 2))
		{
			ft_push(b, a, &size_b, &size_a);
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "pb", 2))
		{
			ft_push(a, b, &size_a, &size_b);
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "ra", 2))
		{
			ft_rotate(a, size_a);
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "rb", 2))
		{
			ft_rotate(b, size_b);
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "rra", 3))
		{
			ft_reverse_rotate(a, size_a);
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "rrb", 3))
		{
			ft_reverse_rotate(b, size_b);
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "rrr", 3))
		{
			ft_reverse_rotate(a, size_a);
			ft_reverse_rotate(b, size_b);
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "rr", 2))
		{
			ft_rotate(a, size_a);
			ft_rotate(b, size_b);
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "ll", 2))
		{
			ft_lowest_top(a, size_a, ft_lowest(a, size_a));
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "l", 1))
		{
			ft_lowest(a, size_a);
			printf("%d\n", ft_lowest(a, size_a));
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
		else if (!ft_strncmp(commands, "s", 1))
		{
			ft_simple_sort(a, b, &size_a, &size_b);
			if (DEBUG)
				ft_show_numbers(a, b, size_a, size_b);
		}
	}
	return (0);
}