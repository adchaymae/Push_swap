#include "push_swap.h"

int invalid_string(char *str)
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

int double_Input(s_node *s, int n)
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

int check_overflow(int n)
{
    if (n > INT_MAX || n < INT_MIN)
        return (1);
    return (0);
}

