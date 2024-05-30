#include"push_swap.h"
static void add_node(t_stack_node **stack, int n)
{
	t_stack_node *node;
	t_stack_node *last_node;

	if (!stack)
		return;
	node = malloc(sizeof(t_stack_node));
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
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	construct_stack_a(s_node **a, char **argv)
{
    int i;
    int r;

    i = 0; 
    while (argv[i])
    {
        r = check_Input(a,argv[i]);
        if (r == 0)
        {
           add_node(a, (int)n);
           i++;
        }
        
        
    }

}