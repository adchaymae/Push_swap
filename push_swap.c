#include "push_swap.h"
#include<stdio.h>
int	main(int argc, char **argv)
{
	s_node	*a;
	s_node	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
    construct_stack_a(&a, argv+1);
    if (!ft_checksorted(a)) //Check if the stack is not sorted
	{
		if (stack_size(a) == 2) //If not, and there are two numbers, swap the first two nodes
			sa(&a, false);
		else if (stack_size(a) == 3) //If not, and there are three numbers, call the sort three algorithm
			sort_three(&a);

        else
			write(1,"a",1);
    }
    return 0;
}