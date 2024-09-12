#include "map.h"

int is_there(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	not_valid(char c)
{
	if (!c)
		return (1);
	if (c == ' ' || c == '\n')
		return (1);
	else
		return (0);
}

int only_ones(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (-1);
	
    while (str[i])
	{
        if (str[i] != ' ' || str[i] != '1')
            return 0;
        i++;
    }
    return 1;
}

int	is_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
