#include"push_swap.h"
static void add_node(s_node **stack, int n)
{
	s_node *node;
	s_node *last_node_f;

	if (!stack)
		return;
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