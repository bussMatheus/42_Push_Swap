/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:05:33 by mely-pan          #+#    #+#             */
/*   Updated: 2024/12/18 20:06:57 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	ft_isvalid_n(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '+' || number[i] == '-')
		i++;
	if (!number[i])
		return (0);
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdup(char **numbers, int n, int size, int flag_argc)
{
	int	i;
	int	num;

	i = 0;
	if (flag_argc == 1)
		i += flag_argc;
	while (i < size)
	{
		num = ft_atoi(numbers[i]);
		if (num == n)
			return (1);
		i++;
	}
	return (0);
}

int	check_str_numbers(char **numbers, t_stack_node **a)
{
	int		i;
	long	n;

	i = 0;
	while (numbers[i])
		i++;
	while (--i >= 0)
	{
		if (!ft_isvalid_n(numbers[i]))
			return (free_splited(numbers), 0);
		n = ft_atoi(numbers[i]);
		if (n > 2147483647 || n < -2147483648 || ft_isdup(numbers, n, i, 0))
			return (free_lst(a), free_splited(numbers), 0);
		if (!append(a, n))
			return (free_splited(numbers), free_lst(a), 0);
	}
	return (free_splited(numbers), 1);
}

int	check_argv_numbers(int argc, char **argv, t_stack_node **a)
{
	int		i;
	long	n;

	i = argc - 1;
	while (i > 0)
	{
		if (!ft_isvalid_n(argv[i]))
			return (free_lst(a), 0);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN || ft_isdup(argv, n, i, 1))
			return (free_lst(a), 0);
		if (!append(a, n))
			return (free_lst(a), 0);
		i--;
	}
	return (1);
}
// manage_input will receive our arguments, check if they are valid
// and if they are a string to be splited or many numbers as arguments

int	manage_input(int argc, char **argv, t_stack_node **a)
{
	char	**str_numbers;
	int		i;

	i = 0;
	if (argc == 1 || !argv[1][0])
		return (0);
	if (argc == 2)
	{
		str_numbers = ft_split(argv[1], ' ');
		if (!str_numbers)
			return (0);
		return (check_str_numbers(str_numbers, a));
	}
	return (check_argv_numbers(argc, argv, a));
}
