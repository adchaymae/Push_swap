#include "push_swap.h"

static void add_node(s_node **stack, int n)
{
    s_node *node;
    s_node *last_node_f;

    node = malloc(sizeof(s_node));
    if (!node)
        return;
    node->next = NULL;
    node->nbr = n;
    if (!(*stack))
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node_f = last_node(*stack);
        last_node_f->next = node;
        node->prev = last_node_f;
    }
}

void construct_stack_a(s_node **a, char **argv)
{
    int i;
	int nbr;
    i = 0;
    while (argv[i])
    {
		if (invalid_string(argv[i]))
		{
            free_stack(a);
            write(1, "Error\n", 6);
            exit(1);
        }
		nbr = ft_atoi(argv[i]);
		if (check_overflow(((int)nbr)))
		{
            free_stack(a);
            write(1, "Error\n", 6);
            exit(1);
        }
		if (double_Input(*a, (int)nbr))
		{
            free_stack(a);
            write(1, "Error\n", 6);
            exit(1);
        }
		add_node(a, (int)nbr);
		++i;
}
}
