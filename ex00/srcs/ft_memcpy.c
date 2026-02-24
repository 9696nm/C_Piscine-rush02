/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:07:54 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:20:48 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*ch_buf1;
	unsigned char	*ch_buf2;

	ch_buf1 = (unsigned char *)buf1;
	ch_buf2 = (const unsigned char *)buf2;
	if (ch_buf1 == NULL && ch_buf2 == NULL)
		return (NULL);
	while (n-- > 0)
		ch_buf1[n] = ch_buf2[n];
	return (ch_buf1);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[13] = "hello world!";
	// char	s2[7] = {"123\0xyz"};

	for (size_t i=0; i < 13; i++)
		printf("%zu:(%c) ", i, s1[i]);
	printf("\n");
	ft_memcpy(s1, s1 + 3, 10);
	for (size_t i=0; i < 13; i++)
		printf("%zu:(%c) ", i, s1[i]);
	printf("\n");
	return (0);
}

/*
オーバー分は未定義で良い
*/
