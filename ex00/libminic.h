
#ifndef LIBMINIC_H
# define LIBMINIC_H

# include <stddef.h>

void	*ft_memset(void *s, int c, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_memcpy(void *buf1, const void *buf2, size_t n);
size_t	ft_strlen(const char *str);
int		mini_atoi(char *str);

#endif
