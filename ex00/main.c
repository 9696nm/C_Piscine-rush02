/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:32:11 by hana/hmori        #+#    #+#             */
/*   Updated: 2026/02/10 23:04:54 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

#define DEFAULT_X 3
#define DEFAULT_Y 3

void	rush(int x, int y);

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

int	main(int argc, char *argv[])
{
	if (1 == argc)
		rush(DEFAULT_X, DEFAULT_Y);
	else if (3 == argc)
		rush(mini_atoi(argv[1]), mini_atoi(argv[2]));
	else
		write(STDOUT_FILENO, "Usage: ./a.out <x> <y>\nx, y: integer\n", 37);
	return (0);
}
		// ft_putchar((*argv[1] - 'a' + 1) % 5 + '0');
	// ft_putchar('\n');
