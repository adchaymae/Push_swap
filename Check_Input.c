#include"push_swap.h"

int	invalid_string(char *str)
{
	if (!(*str == '+'|| *str == '-'|| (*str >= '0' && *str <= '9'))) 
		return (1);
	if ((*str == '+'|| *str == '-') && !(str[1] >= '0' && str[1] <= '9')) 
		return (1);
	while (*++str) 
	{
		if (!(*str >= '0' && *str <= '9')) 
			return (1);
	}
	return (0);
}
int	double_Input(s_node *s, int n)
{
	if (!s)
		return (0);
	while (s)
	{
		if (s->nbr == n)
			return (1);
		s = s->next;
	}
	return (0);
}
int check_overflow(long n){
    if (n > INT_MAX || n < INT_MIN)
        return (1);
    return (0);
}

void	free_stack(s_node **stack) 
{
	s_node	*next;
	s_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		current->nbr = 0;
		free(current);
		current = next;
	}
	*stack = NULL;
}
int check_Input(s_node **a, char *argv)
{
    long n ;

        if (invalid_string(argv))
        {
            free_stack(a);
            write(1,"Error\n",7);
            return(1);
        }
        n = ft_atoi(argv);
        if(check_overflow(n)|| double_Input(a,(int)n))
        {
            free_stack(a);
            write(1,"Error\n",7);
            return(1);
        }
    return(0);

}
