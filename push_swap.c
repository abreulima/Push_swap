#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft/libft.h"

#define DEBUG 0

int max(int size_a, int size_b)
{
	if (size_a < size_b)
	{
		return (size_b);
	}
	return (size_a);
}

int pos_in_stack(int *stack, int value)
{
	int pos;

	pos = 0;
	while (stack[pos] != value)
		pos++;

	return pos;
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
			printf("%d ", stack_a[i]); // Replace
		else
			printf("  ");
		if (size_b > i)
			printf("%d ", stack_b[i]); // Replace
		printf("\n"); // Replace
		i++;
	}
	printf("- -\n"); // Replace
	printf("a b\n"); // Replace
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
	while (0 < i)
	{
		destination[i] = destination[i - 1];
		i--;
	}
	destination[0] = source[0];
	i = 0;
	while (i < *size_source)
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
	while (i < size - 1)
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
	int lowest;
	int i;

	lowest = 2147483647;
	for (i = 0; i < size; i++) // Replace
	{
		if (stack[i] < lowest)
			lowest = stack[i];
	}
	return (lowest);
}

void ft_lowest_top(int *stack, int size, int lowest)
{

	int pos;

	if (size == 0)
	{
		return;
	}
	else if (lowest == stack[0])
	{
		return;
	}

	pos = pos_in_stack(stack, lowest);

	if (pos < size / 2)
	{
		while (lowest != stack[0])
		{
			ft_rotate(stack, size);
			printf("ra\n"); // Replace
		}
	}
	else
	{
		while (lowest != stack[0])
		{
			ft_reverse_rotate(stack, size);
			printf("rra\n"); // Replace
		}
	}

}

void ft_simple_sort(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	while (*size_a != 0)
	{
		ft_lowest_top(stack_a, *size_a, ft_lowest(stack_a, *size_a));
		ft_push(stack_a, stack_b, size_a, size_b);
		printf("pb\n"); // Replace
	}
	while (*size_b != 0)
	{
		ft_push(stack_b, stack_a, size_b, size_a);
		printf("pa\n"); // Replace
	}
}

void ft_better_sort(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	while (*size_a != 0)
	{
		ft_lowest_top(stack_a, *size_a, ft_lowest(stack_a, *size_a));
		ft_push(stack_a, stack_b, size_a, size_b);
		printf("pb\n"); // Replace
	}
	while (*size_b != 0)
	{
		ft_push(stack_b, stack_a, size_b, size_a);
		printf("pa\n"); // Replace
	}
}

void ft_allocate_and_sort(char **numbers, int n_elements)
{
	int i;

	int *stack_a;
	int *stack_b;
	int size_a;
	int size_b;

	stack_a = (int *)malloc(n_elements * sizeof(int));
	stack_b = (int *)malloc(n_elements * sizeof(int));

	size_a = n_elements;
	size_b = 0;

	i = 0;
	while (i < n_elements)
	{
		stack_a[i] = ft_atoi(numbers[i + 1]);
		i++;
	}

	ft_simple_sort(stack_a, stack_b, &size_a, &size_b);
	ft_show_numbers(stack_a, stack_b, size_a, size_b);

	free(stack_a);
	free(stack_b);

}

int main(int argc, char **argv)
{
	int n_elements;

	if (argc == 1)
	{
		exit(1);
	}

	n_elements = argc - 1;
	ft_allocate_and_sort(argv, n_elements);

	return 0;
}