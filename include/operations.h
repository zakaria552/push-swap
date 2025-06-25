#ifndef H_OPERATIONS_H
#define H_OPERATIONS_H

typedef enum e_operation
{
	E_OP_SWAP_A,
	E_OP_SWAP_B,
	E_OP_ROTATE_A,
	E_OP_ROTATE_B,
	E_OP_REV_ROTATE_A,
	E_OP_PUSH_A,
	E_OP_PUSH_B,
} t_operation;


bool	operate(t_operation op);
void peform_operations(const char *ops, unsigned int *nums, unsigned int *end);

#endif