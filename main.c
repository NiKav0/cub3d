#include "map.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Error: Make sure you entered 2 arguments.\n", 42);
		return (1);
	}
	if (parse_map(av[1]) != 0)
	{
		write(2, "Error: Map parsing failed.\n", 27);
		return (1);
	}
	return (0);
}
