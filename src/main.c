#include "push_swap.h"

int main(int argc, char **args)
{
	int *nums;

	nums = NULL;
	if (argc < 3)
		return 0;
	parse(argc, args, &nums);
	solve(argc, &nums);
	free(nums);
	return 0;
}