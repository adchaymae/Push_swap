#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_node
{
	int				nbr;
	int				position;
	struct s_node	*next;
	struct s_node	*prev;
} s_node;
int	invalid_string(char *str);
int	double_Input(s_node *s, int n);
int check_overflow(int n);
char    **ft_split(char *str, char separator);
long	ft_atoi(const char *s);
void	sa(s_node	**a, bool checker);
void	sb(s_node	**b, bool checker);
void	ss(s_node **a, s_node **b, bool checker);
void pa(s_node **a, s_node **b, bool checker);
void pb(s_node **b, s_node **a, bool checker);
void ra(s_node **a, bool checker);
void rb(s_node **b, bool checker);
void	rr(s_node **a, s_node **b, bool checker);
void	rra(s_node **a, bool checker);
void	rrb(s_node **b, bool checker);
void	rrr(s_node **a, s_node **b, bool checker);

int stack_size(s_node *a);
s_node *last_node(s_node *stack);
static void add_node(s_node **stack, int n);
void	free_stack(s_node **stack);
void	construct_stack_a(s_node **a, char **argv);
int	ft_checksorted(s_node *stack_a);
int	get_position(s_node *a, int nbr);
s_node* ft_min_node(s_node *a);
s_node* ft_max_node(s_node *a);
void sort_three(s_node **a);
int calculate_cost(s_node *stack, s_node *current);



#endif