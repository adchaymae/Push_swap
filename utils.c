#include"push_swap.h"

int			ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int		count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			count++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str)
{
	char *word;
	int	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char **arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	int i = 0;
	while (*str)
	{
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			
			arr[i] = malloc_word(str);
			i++;
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

long	ft_atoi(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - 48);
	return (result * sign);
}

int stack_size(s_node *a)
{
    int counter;

    counter = 0;
    while (a)
    {
        ++counter;
        a = a->next;
    }
    
    return (counter);
}

s_node *last_node(s_node *stack)
{
    if(!stack)
        return NULL;
    while(stack->next != NULL)
    {
        stack = stack->next;
    }
    return (stack);
}

int	ft_checksorted(s_node *stack_a)
{
	int	i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}

void free_stack(s_node **node) // ** we want to set the pointer to node to null to make sure that nothing exist
{
	s_node *current;
	s_node *tmp;
	if (!node)
		return;
	current = node;
	while(current->next!= NULL )
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*node = NULL;
}
int	ft_min(s_node *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr < i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

int	ft_max(s_node *a)
{
	int		i;

	i = a->nbr;
	while (a)
	{
		if (a->nbr > i)
			i = a->nbr;
		a = a->next;
	}
	return (i);
}

int	get_position(s_node *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int calculate_cost(s_node **a, s_node *current)
{
	int index;
	int median ;
	int cost;

	median = stack_size(a)/2;
	index = get_position(current, current->nbr);
	if(median > index)
	{
		cost = index;
	}
	else
	{
		cost = median - index;
	}
	return(cost);

}

s_node *get_target(s_node **a, s_node *s)
{

}

s_node *find_cheapest_move(s_node **a, s_node **b)
{

}





