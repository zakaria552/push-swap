/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarah <zfarah@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:12:13 by zfarah            #+#    #+#             */
/*   Updated: 2025/06/26 12:12:47 by zfarah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **args)
{
	int	*nums;

	nums = NULL;
	if (argc < 3)
		return (0);
	parse(argc, args, &nums);
	solve(argc, &nums);
	free(nums);
	return (0);
}
