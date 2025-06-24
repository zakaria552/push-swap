#include "push_swap.h"

void clean_exit(int **nums)
{
	if (nums)
		free(*nums);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}