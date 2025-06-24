#ifndef H_OPERATIONS_H
#define H_OPERATIONS_H

typedef enum e_operation
{
	E_OP_SWAP_A,
	E_OP_SWAP_B,
	E_OP_ROTATE_A,
	E_OP_ROTATE_B,
	E_OP_PUSH_A,
	E_OP_PUSH_B,
} t_operation;


void	operate(t_operation op);

#endif