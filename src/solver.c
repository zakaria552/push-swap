#include "push_swap.h"

static void normalize_nums(int argc, int **nums, unsigned int **norm_nums, int **sorted);
static void solve_stack_of_three(unsigned int *nums);
static void	solve_stack_of_two(unsigned int *nums);
static void solve_stack_of_five(int argc, unsigned int *nums);

void	solve(int argc, int **nums)
{
	unsigned int *norm_nums;	
	int * sorted_nums;

	normalize_nums(argc, nums, &norm_nums, &sorted_nums);
	if (argc - 1 == 2)
		solve_stack_of_two(norm_nums);
	else if (argc - 1 == 3)
		solve_stack_of_three(norm_nums);
	else if (argc - 1 == 5)
		solve_stack_of_five(argc, norm_nums);
	else 
		radix_sort(argc, norm_nums);
	free(norm_nums);
	free(sorted_nums);
}

static void normalize_nums(int argc, int **nums, unsigned int **norm_nums, int **sorted)
{
	int i;

	*norm_nums = ft_calloc(argc - 1, sizeof(int));
	if (*norm_nums == NULL)
		clean_exit(nums);
	*sorted = ft_calloc(argc - 1, sizeof(int));
	if (!*sorted)
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

static void solve_stack_of_three(unsigned int *nums)
{
	if (nums[0] > nums[1] && nums[0] > nums[2])
	{
		operate(E_OP_ROTATE_A);
		rotate_arr(nums, nums + 2);
		if (nums[0] > nums[1] && operate(E_OP_SWAP_A))
			rotate_arr(nums, nums + 1);
		return;
	}
	if (nums[2] > nums[1] && nums[2] > nums[0])
	{
		if (nums[0] > nums[1] && operate(E_OP_SWAP_A))
			rotate_arr(nums, nums + 1);	
		return;
	}	
	rev_rotate_arr(nums, nums + 2);	
	operate(E_OP_REV_ROTATE_A);
	if (nums[0] > nums[1] && operate(E_OP_SWAP_A))
		rotate_arr(nums, nums + 1);
}

static void	solve_stack_of_two(unsigned int *nums)
{
	int tmp;

	if (*nums < *(nums + 1))
		return;
	tmp = *nums;
	*nums = *(nums + 1);
	*(nums + 1) = tmp;
	operate(E_OP_ROTATE_A);
}

static void solve_stack_of_five(int argc, unsigned int *nums)
{
	const char *ops1[] = {"pb", "sa pb", "ra ra pb", "rra rra pb", "rra pb"};
	const char *ops2[] = {"pb", "ra pb", "ra ra pb", "rra pb"};
	unsigned int *sa = nums;
	unsigned int *sb = NULL;

	peform_operations(ops1[get_index((int *) sa, argc - 1, 0)], sa, nums + 4);
	operate(E_OP_PUSH_B);
	sb = sa;	
	sa++;
	peform_operations(ops2[get_index((int *) sa, argc - 1, 1)], sa, nums + 4);
	operate(E_OP_PUSH_B);
	sa++;
	solve_stack_of_three(sa);
	operate(E_OP_PUSH_A);	
	operate(E_OP_PUSH_A);	
}
