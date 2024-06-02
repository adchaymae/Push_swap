#include "push_swap.h"

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words(str, separator);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (NULL == vector_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (NULL == vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(str, separator);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}

long ft_atoi(const char *s)
{
    long result = 0;
    int sign = 1;
    while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f' || *s == '\v')
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }
    while (*s >= '0' && *s <= '9')
        result = result * 10 + (*s++ - '0');
    return result * sign;
}

int stack_size(s_node *a)
{
    int counter = 0;
    while (a)
    {
        counter++;
        a = a->next;
    }
    return counter;
}

s_node* last_node(s_node *stack)
{
    if (!stack)
        return NULL;
    while (stack->next != NULL)
    {
        stack = stack->next;
    }
    return stack;
}

int ft_checksorted(s_node *stack_a)
{
    int i = stack_a->nbr;
    while (stack_a)
    {
        if (i > stack_a->nbr)
            return 0;
        i = stack_a->nbr;
        stack_a = stack_a->next;
    }
    return 1;
}

s_node* ft_min_node(s_node *a)
{
    if (!a)
        return NULL;

    s_node *min_node = a;
    a = a->next;
    while (a)
    {
        if (a->nbr < min_node->nbr)
            min_node = a;
        a = a->next;
    }
    return min_node;
}


s_node* ft_max_node(s_node *a)
{
    if (!a)
        return NULL;

    s_node *max_node = a;
    a = a->next;
    while (a)
    {
        if (a->nbr > max_node->nbr)
            max_node = a;
        a = a->next;
    }
    return max_node;
}


int get_position(s_node *a, int nbr)
{
    int i = 0;
    while (a->nbr != nbr)
    {
        i++;
        a = a->next;
    }
    return i;
}

int calculate_cost(s_node *stack, s_node *current)
{
    int index;
    int median;
    int cost;

    median = stack_size(stack) / 2;
    index = get_position(stack, current->nbr);

    if (index <= median)
    {
        cost = index;
    }
    else
    {
        cost = stack_size(stack) - index;
    }

    return cost;
}

s_node* find_target(s_node *a_node, s_node *b)
{
    s_node *current_b = b;
    s_node *target_node = NULL;
    long best_match_index = LONG_MIN;

    while (current_b)
    {
        if (current_b->nbr < a_node->nbr && current_b->nbr > best_match_index)
        {
            best_match_index = current_b->nbr;
            target_node = current_b;
        }
        current_b = current_b->next;
    }

    if (best_match_index == LONG_MIN)
    {
        return last_node(b);
    }
    else
    {
        return target_node;
    }
}

s_node* find_cheapest_move(s_node *a, s_node *b)
{
    int cheapest_value = INT_MAX;
    s_node *cheapest_node = NULL;
    s_node *target;

    if (!a || !b)
        return NULL;

    while (a)
    {
        target = find_target(a, b);
        int current_cost = calculate_cost(a, a) + calculate_cost(b, target);

        if (current_cost < cheapest_value)
        {
            cheapest_value = current_cost;
            cheapest_node = a;
        }
        a = a->next;
    }

    return cheapest_node;
}
void free_stack(s_node **stack) 
{
    s_node *next;
    s_node *current;

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