#include "../headers/ft_push_swap.h"

// int	ft_isspace(int c)
// {
// 	if (c == ' ' || c == '\f' || c == '\n'
// 		|| c == '\r' || c == '\t' || c == '\v')
// 		return (1);
// 	return (0);
// }

long long	ft_atoll(const char *str)
{
	int	i;
	long long	res;
	int	negative;

	i = 0;
	res = 0;
	negative = 1;
	if (!str)
		return (-1);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * negative);
}