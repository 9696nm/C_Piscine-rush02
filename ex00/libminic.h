
#ifndef LIBMINIC_H
# define LIBMINIC_H

# include <stddef.h>

void	*ft_memset(void *s, int c, size_t size);
char	*ft_strchr(const char *source, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		mini_atoi(char *str);

#endif
