/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:43:20 by vrenaudi          #+#    #+#             */
/*   Updated: 2018/12/12 13:41:20 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include "../printf/ft_printf.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			**ft_strsplit(char const *s, char c);
char			*ft_dec_to_bi(unsigned int nb);
char			*ft_dec_to_hex(unsigned long long nb, char c);
char			*ft_dec_to_octa(unsigned long long nb);
char			*ft_dectobi_ll(unsigned long long nb);
char			*ft_itoa(int n);
char			*ft_itoa_ll(long long n);
char			*ft_memjoin(char *s1, const char *s2, int n1, int n2);
char			*ft_memjoinfreeall(char *s1, char *s2, int n1, int n2);
char			*ft_putwcinstr(wchar_t wc);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinfree(char *s1, char const *s2);
char			*ft_strjoinfreeall(char *s1, char *s2);
char			*ft_strjoinfreesec(char const *s1, char *s2);
char			*ft_strjoinone(char *s1, char c);
char			*ft_strjoinuntilc(char *s1, const char *s2, char c);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strndup(const char *s1, int n);
char			*ft_strnew(size_t size);
char			*ft_strnjoin(char const *s1, char const *s2, size_t n);
char			*ft_strnstr(const char *src, const char *need, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrpc(const char *s, int c, int d);
char			*ft_strrpcall(char *s, int c, int d);
char			*ft_strstr(const char *src, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtolower(char *str);
char			*ft_strtoupper(char *str);
char			*ft_strtrim(char const *s);
char			*ft_uintmax_to_hex(uintmax_t nb, char c);
char			*ft_uns_itoa(unsigned int n);
char			*ft_uns_itoa_ll(unsigned long long n);
int				ft_atoi(const char *str);
int				ft_bi_to_dec(char *bi);
int				ft_intlen(int nb);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_lololen(long long nb);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_power(int nb, int power);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strlct(const char *s, int c);
int				ft_strlenuntilc(const char *s, char c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_unsintlen(unsigned int nb);
int				ft_unslololen(unsigned long long nb);
size_t			ft_charlen(wchar_t wc);
size_t			ft_strlcat(char *s1, const char *s2, size_t size);
size_t			ft_strlen(const char *s);
size_t			ft_wstrlen(const wchar_t *s);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
unsigned char	ft_reversebits(unsigned char octet);
unsigned char	ft_swapbits(unsigned char octet);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memdup(const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			ft_lstadd(t_list **alst, t_list *neww);
void			ft_lstaddlast(t_list **alst, void *data);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstrmvone(t_list **b, t_list *to_del, \
											void (*del)(void *, size_t));
void			ft_memdel(void **ap);
void			ft_printbits(unsigned char octet);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putmemstr(char *s, int n);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putwchar(wchar_t wc);
void			ft_putwstr(wchar_t const *s, int len);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

#endif
