#include "push_swap.h"

void normalize_nums(int argc, int **nums, unsigned int **norm_nums, int **sorted);

void	solve(int argc, int **nums)
{
	unsigned int *norm_nums;	
	int * sorted_nums;
	
	normalize_nums(argc, nums, &norm_nums, &sorted_nums);
	radix_sort(argc, norm_nums, sorted_nums);
	free(norm_nums);
	free(sorted_nums);
}

void normalize_nums(int argc, int **nums, unsigned int **norm_nums, int **sorted)
{
	int *c_nums;
	int i;

	*norm_nums = ft_calloc(argc - 1, sizeof(int));
	if (*norm_nums == NULL)
		clean_exit(nums);
	*sorted = ft_calloc(argc - 1, sizeof(int));
	if (!sorted)
	{
		free(norm_nums);
		clean_exit(nums);
	}
	ft_memcpy(*sorted, *nums, (argc - 1) * sizeof(int));
	bubble_sort(*sorted, argc - 1);
	i = -1;
	while (++i < argc - 1)
		(*norm_nums)[i] = get_index(*sorted, argc - 1, (*nums)[i]);
}
