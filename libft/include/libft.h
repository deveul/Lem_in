/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:28:24 by smakni            #+#    #+#             */
/*   Updated: 2019/02/01 19:07:10 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include <inttypes.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memset_from(void *b, size_t start, int c, size_t len);
void				*ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_putchar(wchar_t c);
void				ft_putchar1(wchar_t c);
void				ft_putchar2(wchar_t c);
void				ft_putchar3(wchar_t c);
void				ft_putchar4(wchar_t c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_print_bits(unsigned char octet);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strdup(const char *src);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *str, const char *find, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsub_free(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strjoin_free1(char *s1, char *s2);
char				*ft_strjoin_2free(char *s1, char *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa_base(int n, int len, int flag);
char				*ft_itoa_base_ui(unsigned int n, int len, int flag);
char				*ft_itoa_base_uit(size_t n, int len, int flag);
char				*ft_itoa_base_it(size_t n, int len, int flag);
char				*ft_itoa_base_lui(unsigned long int n, int len, int flag);
char				*ft_itoa_base_llui(unsigned long long int n, int l, int f);
char				*ft_itoa(int n);
char				*ft_itoa_ui(unsigned int n);
char				*ft_itoa_lui(unsigned long int n);
char				*ft_itoa_llui(unsigned long long int n);
char				*ft_itoa_uit(uintmax_t n);
char				*ft_itoa_li(long int n);
char				*ft_itoa_lli(long long int n);
char				*ft_itoa_imax(intmax_t n);
char				*ft_itoa_sit(ssize_t n);
char				*ft_itoa_it(size_t n);
char				*ft_strtoupper(char *str);
char				*ft_strtolower(char *str);
char				**ft_strsplit(char const *s, char c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
long				ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isdigit(int c);
int					ft_isnumber(char *c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isprint(int c);
long long			ft_power(long long nb, int power);
int					ft_factorial(int nb);
int					ft_sqrt(int nb);
int					ft_strlen_c(const char *str, char c);
int					ft_strlen_from(char *str, char start, char end);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
t_list				*ft_lstnew(void	const	*content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstmove_last(t_list **alst, t_list *elem);
t_list				*ft_llast(t_list *lst, void *content, size_t content_size);
void				*ft_memjoin(void *s1, const void *s2, size_t n1, size_t n2);
void				*ft_memcpy_from(void *dst, const void *src, int s, int n);
void				ft_putstr_printf(char const *s, size_t len);
void				ft_tabdel(char **tab, int len);
char				*ft_strcpy_from(char *dst, const char *src, int start);

#endif
