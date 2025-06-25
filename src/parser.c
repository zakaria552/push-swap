#include "push_swap.h"
static void stratoi(int argc, char **args, int **nums);
static int is_duplicate(int argc, int *nums, int num, int stop);

void parse(int argc, char **args, int **nums)
{
	*nums = ft_calloc(argc - 1, sizeof(int));
	if (!*nums)
		clean_exit(NULL);
	stratoi(argc, args, nums);
}

static void stratoi(int argc, char **args, int **nums)
{
	int error;
	int i;
	int j;

	i = j = error = 0;
	while (++i < argc)
	{
		(*nums)[j] = cracked_atoi(args[i], &error);
		if (error)
			clean_exit(nums);
		if(is_duplicate(argc, *nums, (*nums)[j], j))
			clean_exit(nums);
		j++;
	}
}
static int is_duplicate(int argc, int *nums, int num, int stop)
{
	int i;

	i = -1;
	while (++i < stop)
	{
		if (nums[i] == num)
			return (1);
	}
	return (0);
}