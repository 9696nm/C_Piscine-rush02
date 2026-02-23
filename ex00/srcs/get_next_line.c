/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:58:22 by hmori             #+#    #+#             */
/*   Updated: 2025/02/22 18:29:51 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libminic.h"
#include "internal/get_next_line.h"

static char	*get_fd_buf(int fd, t_fd_buf_mode mode)
{
	static char	*fd_buf[FD_MAX];

	if (fd < 0 || FD_MAX <= fd)
		return (NULL);
	if (mode == FD_BUF_ALLOC && fd_buf[fd] == NULL)
		fd_buf[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	return (fd_buf[fd]);
}

static void	*set_fd_buf(int fd, char *src, ssize_t rlen)
{
	if (src)
		ft_strlcpy(get_fd_buf(fd, FD_BUF_RDONLY), src + 1, rlen + 1);
	else
		ft_memset(get_fd_buf(fd, FD_BUF_RDONLY), '\0', BUFFER_SIZE + 1);
}

static char	*join_res(char **dst, char *src)
{
	size_t	len;
	char	*res;

	if (ft_strchr(src, '\n'))
		*ft_strchr(src, '\n') = '\0';
	len = ft_strlen(src);
	if (*dst)
		len += ft_strlen(*dst);
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, )

	if (len)
		ft_strlcpy(res, *dst, len + 1);
	else
		ft_strlcpy(res, src, ft_strlen(src) + 1);

	if (*dst)
	else
		ft_strlcpy(*dst, src, ft_strlen(src) + 1);
	free(*dst);
	return (res);
}

char	*get_next_line(int fd)
{
	ssize_t		rlen;
	char		*res;
	char		src[BUFFER_SIZE + 1];

	res = NULL;
	while (0 <= fd && fd < FD_MAX && get_fd_buf(fd, FD_BUF_ALLOC))
	{
		ft_memset(src, '\0', BUFFER_SIZE + 1);
		if (get_fd_buf(fd, FD_BUF_RDONLY) == '\0')
			rlen = read(fd, src, BUFFER_SIZE);
		else
			rlen = ft_strlcpy(src, get_fd_buf(fd, FD_BUF_RDONLY), BUFFER_SIZE + 1);
		if (BUFFER_SIZE == 0 || rlen < 0)
			break ;
		set_fd_buf(fd, ft_strchr(src, '\n'), rlen);
		res = join_res(&res, src);
		if (res == NULL)
			break ;
		if (ft_strchr(get_fd_buf(fd, FD_BUF_RDONLY), '\n') || rlen == 0)
			return (res);
	}
	if (res)
		free(res);
	return (NULL);
}

__attribute__((destructor)) \
static void	free_fd_buffer(void)
{
	int		fd;
	char	*buf;

	fd = 0;
	while (FD_MAX > fd)
	{
		if ((buf = get_fd_buf(fd, FD_BUF_RDONLY)))
			free(buf);
		fd++;
	}
}


// #include <stdio.h>
// #include <fcntl.h>
// int	main (int argc, char *argv[])
// {
// 	char	*str;

// 	if (argc != 2)
// 		return (0);
// 	int	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	while (str = get_next_line(fd), str)
// 	{
// 		printf("%s", str);
// 		fflush(stdout);
// 		free(str);
// 	}
// 	// printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
// 	close(fd);
// 	return (0);
// }
