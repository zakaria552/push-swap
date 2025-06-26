/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:12:58 by zfarah            #+#    #+#             */
/*   Updated: 2025/06/26 12:13:13 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	operate(t_operation op)
{
	const char	*ops[] = {"sa", "sb", "ra", "rb", "rra", "pa", "pb", NULL};

	ft_printf("%s\n", ops[op]);
	return (true);
}

void	peform_operations(const char *ops, unsigned int *nums,
		unsigned int *end)
{
	const char	*op = ops;
	const char	*ptr = ft_strchr(op, ' ');

	while (ptr)
	{
		if (!ft_strncmp(op, "ra", ptr - op) && operate(E_OP_ROTATE_A))
			rotate_arr(nums, end);
		else if (!ft_strncmp(op, "sa", ptr - op) && operate(E_OP_SWAP_A))
			rotate_arr(nums, nums + 1);
		else if (!ft_strncmp(op, "rra", ptr - op) && operate(E_OP_REV_ROTATE_A))
			rev_rotate_arr(nums, end);
		op = ptr + 1;
		ptr = ft_strchr(op, ' ');
	}
}
