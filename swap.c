#include "push_swap.h"

static void	swap(s_node **head)
{
	int	len;

	len = stack_size(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(s_node	**a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(s_node **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(s_node **a, s_node **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}

