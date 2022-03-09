#include "../headers/ft_push_swap.h"


int main(int argc, char **argv)
{
	int	i;
	long long test;
	
	i = 1;
	while (argv[i])
	{
		ft_strip(argv[i]);
		if (ft_strlen(argv[i]) <= 11 && pile_isdigit(argv[i]))
		{
			test = ft_atoll(argv[i]);
			printf("%d\n", ft_is_integer(test));
		} 
		else
		{
			puts("error");
			exit(1);
		}
		i++;
	}
	return (0);
}