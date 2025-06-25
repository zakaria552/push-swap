
void bubble_sort(int *nums, int size)
{
	int i;
	int j;	
	int tmp;

	i = j = -1;
	while (++i < size)
	{
		j = 0;
		while ((j + 1) < (size - i))
		{
			if(nums[j] > nums[j + 1]) 
			{
				tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
			j++;
		}

	}
}

int get_index(int *nums, int size, int num)
{
	int i;

	i = -1;
	while(++i < size)
	{
		if (nums[i] == num)
			return (i);
	}
}