
#include <limits.h>
#include <stddef.h>

int	mini_atoi(char *str)
{
	int			sing;
	long int	res;

	sing = 1;
	res = 0;
	if (str == NULL)
		return (0);
	while (*str && (' ' == *str || ('\t' <= *str && '\r' >= *str)))
		str++;
	if ('-' == *str)
		sing = -1;
	if ('-' == *str || '+' == *str)
		str++;
	while (*str && '0' <= *str && '9' >= *str)
	{
		res = res * 10 + sing * (*str - '0');
		if (0 < sing && 0 > res)
			return ((int)LONG_MAX);
		if (0 > sing && 0 < res)
			return ((int)LONG_MIN);
		str++;
	}
	return ((int)res);
}
