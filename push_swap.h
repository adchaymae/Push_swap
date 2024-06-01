#ifndef push_swap.h
#define push_swap.h
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
	int				nbr;
	int				position;
	struct s_node	*next;
	struct s_node	*prev;
} s_node;
int	invalid_string(char *str);
int	double_Input(s_node *s, int n);
int check_overflow(long n);
void	free_stack(s_node **stack);
int check_Input(s_node **a, char *argv);
char	**ft_split(char *str);
long	ft_atoi(const char *s);
int stack_size(s_node *a);
s_node *last_node(s_node *stack);
static void add_node(t_stack_node **stack, int n);
void	free_stack(s_node **stack);
void	construct_stack_a(s_node **a, char **argv);
int	ft_min(s_node *a);
int	ft_max(s_node *a);


#endif