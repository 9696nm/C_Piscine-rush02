/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:33:31 by hmori             #+#    #+#             */
/*   Updated: 2025/02/22 18:29:43 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stddef.h>

# ifndef FD_MAX
#  define FD_MAX FD_SETSIZE
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# if BUFFER_SIZE < 0
#  error "BUFFER_SIZE must be a positive number"
# endif

# if 65536 < BUFFER_SIZE
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 65536
# endif

typedef enum e_fd_buf_mode
{
	FD_BUF_RDONLY = 0,
	FD_BUF_ALLOC
}	t_fd_buf_mode;

typedef struct s_gnl_buffer
{
	ssize_t		rlen;
	char		pull[BUFFER_SIZE + 1];
	char		*res;
}	t_gnl_buf;

char	*get_next_line(int fd);

