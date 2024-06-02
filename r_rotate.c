#include "push_swap.h"

static void	r_rotate(s_node **stack)
{
	s_node	*last;
	int				len;

	len = stack_size(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	last = last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(s_node **a, bool checker)
{
	r_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(s_node **b, bool checker)
{
	r_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(s_node **a, s_node **b, bool checker)
{
	r_rotate(a);
	r_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}