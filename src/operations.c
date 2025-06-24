#include "push_swap.h"

void	operate(t_operation op)
{
	const char *ops[] = {"sa", "sb", "ra", "rb", "pa", "pb", NULL};
	
	ft_printf("%s\n", ops[op]);
}