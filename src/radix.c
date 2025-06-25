#include "push_swap.h"

static void	sort_radix_nth_bit(int n, unsigned int *ptr_first, unsigned *ptr_last);
static int	max_bit(unsigned int *norm_nums, int size);

void	radix_sort(int argc, unsigned int *norm_nums)
{
	const int max = max_bit(norm_nums, argc - 1);
	unsigned int *p1;
	unsigned int *p2;	
	int i;

	i = -1;
	while (++i < max)	
	{
		p1 = norm_nums;
		p2 = norm_nums + argc - 2;
		sort_radix_nth_bit(i, p1, p2);
	}
}

static void	sort_radix_nth_bit(int n, unsigned int *ptr_first, unsigned *ptr_last)
{
	unsigned int *p2;
	int sb_pushes;
	
	p2 = ptr_last;
	sb_pushes = 0;
	while (ptr_first <= p2)	
	{
		if (((*ptr_first >> n) & 1))
		{
			rotate_arr(ptr_first, ptr_last);
			operate(E_OP_ROTATE_A);
			p2--;
		}
		else
		{
			operate(E_OP_PUSH_B);
			sb_pushes++;
			ptr_first++;
		}
	}
	while (sb_pushes-- > 0)
		operate(E_OP_PUSH_A);
}

void rotate_arr(unsigned int * num, unsigned int *ptr_last)
{
	int tmp;
	int i;

	tmp = *num;
	i = 0;
	while (num < ptr_last)
	{
		*num = *(num + 1);
		num++;
	}
	*ptr_last = tmp;
}
void rev_rotate_arr(unsigned int * num, unsigned int *ptr_last)
{
	int tmp;
    unsigned int *start = ptr_last; 
    int i;

    tmp = *ptr_last;
    i = 0;
    while (start > num)
    {
        *start = *(start - 1);
        start--;
    }
    *num = tmp;
}

static int	max_bit(unsigned int *norm_nums, int size)
{
	int i;
	unsigned int max_n;
	i = -1;

	max_n = 0;
	while (++i < size)	
	{
		if (max_n < norm_nums[i])
			max_n = norm_nums[i];
	}
	i = 0;
	while (max_n > 0)
	{
		max_n = (max_n >> 1);
		i++;
	}
	return (i);
}