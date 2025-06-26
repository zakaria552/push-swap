#ifndef H_PUSH_SWAP_H
#define H_PUSH_SWAP_H

#include "libft.h"
#include "operations.h"

// error handlers
void clean_exit(int **nums);

// parser
void parse(int argc, char **args, int **nums);

// solver
void	solve(int argc, int **nums);

// bubble sort
void bubble_sort(int *nums, int size);
int get_index(int *nums, int size, int num);

// radix sort
void	radix_sort(int argc, unsigned int *norm_nums);
void rotate_arr(unsigned int * num, unsigned int *ptr_last);
void rev_rotate_arr(unsigned int * num, unsigned int *ptr_last);

#endif