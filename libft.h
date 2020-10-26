/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsaariko <jsaariko@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 15:48:44 by jsaariko      #+#    #+#                 */
/*   Updated: 2020/10/26 15:28:26 by jsaariko      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_vector
{
	void			**data;
	size_t			item_size;
	size_t			amt;
}					t_vector;

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int c, int fd);
void				ft_putbytes_fd(const void *bytes, size_t n, int fd);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
size_t				ft_strlen(const char *s);
int					ft_numlen(int n);
void				*ft_memset(void *ptr, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcpy(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *s);
long long			ft_atoll(const char *s);
void				*ft_calloc(size_t count, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int					ft_strchrset(const char *str, const char *charset);
char				*ft_strdupchr(const char *str, const char *charset);
char				*ft_strjoinchar(const char *str, char c);
int					ft_numlen_base(long long value, long long base);
char				ft_numtochar_base(int n);
char				*ft_lltoa_base(long long value, int base);
char				*ft_ulltoa_base(unsigned long long value, long long base);
char				*ft_ftoa(double value, ssize_t precision);
void				ft_toupperstr(char **str);
void				ft_tolowerstr(char **str);
char				*ft_strjoinindex(const char *s1, const char *s2, int index);
int					ft_strmatch(const char *str, const char *match);
int					ft_dprintf(int fd, const char *str, ...);
int					get_next_line(int fd, char **line);
double				ft_pow(double base, int exp);
double				ft_atof(const char *str);
int					vector_init(t_vector *v);
int					vector_push(t_vector *v, void *item);
void				*vector_get(t_vector *v, size_t index);
int					vector_search(t_vector *v, int (*cmp)(), void *item);
int					vector_delete(t_vector *v, size_t index);



#endif
