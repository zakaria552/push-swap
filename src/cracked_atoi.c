#include "push_swap.h"

int	cracked_atoi(const char *nptr, int *error)
{
	int	i;
	long	num;
	int	sign;

	i = num = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (nptr[i] && nptr[i] <= '9' && nptr[i] >= '0')
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	if (nptr[i] || num * sign > INT_MAX || num * sign < INT_MIN)
	{
		*error = 1;	
		return 0;
	}
	return (int)(num * sign);
}
