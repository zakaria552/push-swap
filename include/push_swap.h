#ifndef H_PUSH_SWAP_H
#define H_PUSH_SWAP_H

#include "libft.h"
#include "operations.h"

// error handlers
void clean_exit(int **nums);

// atoi
int	cracked_atoi(const char *nptr, int *error);

// parser
void parse(int argc, char **args, int **nums);

#endif