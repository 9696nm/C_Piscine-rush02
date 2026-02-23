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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define DEFAULT_X 3
#define DEFAULT_Y 3

void	rush(int x, int y);


int	main(int argc, char *argv[])
{
	// if (1 == argc)
	// 	rush(DEFAULT_X, DEFAULT_Y);
	// else if (3 == argc)
	// 	rush(mini_atoi(argv[1]), mini_atoi(argv[2]));
	// else
	// 	write(STDOUT_FILENO, "Usage: ./a.out <x> <y>\nx, y: integer\n", 37);
	char *str1, *str2;

	str1 = malloc(10);
	str2 = realloc(NULL, 5);
	if (str2 == NULL)
		return (1);
	memset(str2, '\0', 5);
	str2[0] = '4';
	printf("%s\n", str2);

	free(str1);
	free(str2);
	return (0);
}
		// ft_putchar((*argv[1] - 'a' + 1) % 5 + '0');
	// ft_putchar('\n');
