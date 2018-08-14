/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:44:03 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/22 09:26:43 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define MIN_INT        -2147483648
# define MAX_INT        2147483647
# define SUCCESS		0
# define ERROR			1
# define TRUE           1
# define FALSE          0
# define SUCC_CHECK(x)	if (x) return (0)
# define MALLCHECK(x)	if (!x) return
# define MALLCHECK_I(x) if (!x) return (-1)
# define MALLCHECK_N(x)	if (!x) return (NULL)
# define STRCHECK(str)	if (!str) return (NULL)
# define EVEN(x)		(!(x % 2))
# define IS_SPACE(x)    (x == ' ' || x == '\t' || x== '\n')
# define ABS(x)			((x < 0) ? (-x) : x)
# define FD_MAX			50
# define BUFF_SIZE		32

# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef	int			t_bool;
typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void(*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void(*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_c(char const *dest, char const *src);
void				ft_putendl_i(char const *s, int a);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl_c_fd(char const *dest, const char *src, int fd);
void				ft_putendl_i_fd(char const *s, int a, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(const char *str);
void				ft_putstr_fd(const char *s, int fd);
void				ft_printbits(unsigned char octect);
void				ft_printmemory(void *add, size_t size);
void				ft_strclr(char *as);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				*ft_memccpy(void *str1, const void *str2, int c, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
void				*ft_memmove(void *str1, const void *str2, size_t n);
void				*ft_memset(void	*str, int c, size_t n);

int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, int base);
int					ft_clearspace(const char *s, int c);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
int					ft_rand(int min, int max, int seed);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_wordcount(const char *s, char c);
int					get_next_line(const int fd, char **line);

size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s1);

int					ft_ishex(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_intminmax(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *str, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strsub(const char *s, unsigned int start, size_t end);
char				*ft_itoa(int n);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *hay, const char *needle, size_t n);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *hay, const char *needle);
char				*ft_strsub(const char *s1, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);

char				**ft_strsplit(const char *s, char c);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(const void *content, size_t content_size);

#endif
