#include "../headers/ft_push_swap.h"



int	main(int argc, char **argv)
{
	int	pile;
	int	pile_size;

	if (argc != 1)
		return (ft_panic(1));
	pile_size = ft_strlen(argv[1]);
	pile = ft_atoi(argv[1]);
	if (pile <= 0 || pile_is_valid(argv[1]) == 0)
		return (ft_panic(INVALID_PILE));
	if (pile == 0)
		return (ft_panic(EMPTY_STR));
	return (0);
}
