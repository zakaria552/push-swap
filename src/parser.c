/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:36:48 by zfarah            #+#    #+#             */
/*   Updated: 2025/06/26 12:37:04 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stratoi(int argc, char **args, int **nums);
static int	is_duplicate(int *nums, int num, int stop);
static int	cracked_atoi(const char *nptr, int *error);
static void	set_sign(const char *nptr, int *sign, int *index);

void	parse(int argc, char **args, int **nums)
{
	*nums = ft_calloc(argc - 1, sizeof(int));
	if (!*nums)
		clean_exit(NULL);
	stratoi(argc, args, nums);
}

static void	stratoi(int argc, char **args, int **nums)
{
	int	error;
	int	i;
	int	j;

	i = 0;
	j = 0;
	error = 0;
	while (++i < argc)
	{
		(*nums)[j] = cracked_atoi(args[i], &error);
		if (error)
			clean_exit(nums);
		if (is_duplicate(*nums, (*nums)[j], j))
			clean_exit(nums);
		j++;
	}
}

static int	is_duplicate(int *nums, int num, int stop)
{
	int	i;

	i = -1;
	while (++i < stop)
	{
		if (nums[i] == num)
			return (1);
	}
	return (0);
}

static void	set_sign(const char *nptr, int *sign, int *index)
{
	if (nptr[*index] == '-' || nptr[*index] == '+')
	{
		if (nptr[*index] == '-')
			*sign = (*sign) * (-1);
		(*index)++;
	}
}

static int	cracked_atoi(const char *nptr, int *error)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	set_sign(nptr, &sign, &i);
	while (nptr[i] && nptr[i] <= '9' && nptr[i] >= '0')
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	if (nptr[i] || num * sign > INT_MAX || num * sign < INT_MIN)
	{
		*error = 1;
		return (0);
	}
	return ((int)(num * sign));
}
