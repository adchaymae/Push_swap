#include "push_swap.h"

void sort_three(s_node **a)
{
    s_node *max_node = ft_max(*a);

    if (max_node == *a)
    {
        ra(a, false);
    }
    else if ((*a)->next == max_node)
    {
        rra(a, false);
    }

    if ((*a)->nbr > (*a)->next->nbr)
    {
        sa(a, false);
    }
}
