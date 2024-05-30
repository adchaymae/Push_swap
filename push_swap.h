#ifndef push_swap.h
#define push_swap.h
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
	int					nbr;
	int					position;
	int					count_cmd;
	bool				above_median;
	bool				cheapest;
	struct s_node	*target_node;
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
int	ft_isdigit(int c);
int stack_size(s_node *a);
s_node *last_node(s_node *stack);
static void add_node(t_stack_node **stack, int n);
void	free_stack(s_node **stack);
void	construct_stack_a(s_node **a, char **argv);



#endif