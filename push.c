#include"push_swap.h"

static void push(s_node **dest, s_node **src)
{
    s_node *node_to_push;

    if (*src == NULL)
        return;

    node_to_push = *src;
    *src = (*src)->next;

    if (*src != NULL)
        (*src)->prev = NULL;

    node_to_push->prev = NULL;

    if (*dest == NULL)
    {
        *dest = node_to_push;
        node_to_push->next = NULL;
    }
    else
    {
        node_to_push->next = *dest;
        (*dest)->prev = node_to_push;
        *dest = node_to_push;
    }
}

void pa(s_node **a, s_node **b, bool checker)
{
    push(a, b);
    if (!checker)
        write(1, "pa\n", 3);
}

void pb(s_node **b, s_node **a, bool checker)
{
    push(b, a);
    if (!checker)
        write(1, "pb\n", 3);
}