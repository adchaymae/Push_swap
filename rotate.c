#include "push_swap.h"

static void	rotate(s_node **stack)
{
	s_node	*last_node_f;
	int				len;

	len = stack_size(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node_f = last_node(*stack);
	last_node_f->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node_f->next->prev = last_node_f;
	last_node_f->next->next = NULL;
}	

void	ra(s_node **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(s_node **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(s_node **a, s_node **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}