#include "push_swap.h"
#include<stdio.h>
int main(int argc, char **argv)
{
    s_node *a;
    s_node *b;
    int    i;

    i = 1;
    a = NULL;
    b = NULL;
    
    if (argc == 1 || argv[1]==  NULL)
        return 1;
    else if (argc >= 2 && argv[i]!= NULL)
    {
        while(i < argc)
        {
            ft_split(argv[i]);
            i++;
        }
        // char **v = ft_split(argv[1]);
        // int i = 0;
        // while(v[i])
        // {
        //     printf("%s\n",v[i]);
        //     i++;
        // } 
        
    }

    return 0;
}