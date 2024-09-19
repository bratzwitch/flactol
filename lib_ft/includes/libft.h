/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:48:07 by vmoroz            #+#    #+#             */
/*   Updated: 2024/09/14 16:00:18 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <inttypes.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
double				ft_atof(char *str);
void				ft_bzero(void *dest, size_t n);
void				*ft_calloc(size_t num, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_strcmp(char *s1, char *s2);
void				*ft_memchr(const void *src, int chr, size_t n);
int					ft_memcmp(void *str1, void *str2, int l);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, unsigned int n);
void				*ft_memset(void *dest, int value, size_t count);
char				*ft_strchr(const char *str, int ch);
char				*ft_strdup(char *src);
char				*ft_strjoin(char const *s1, char const *s2);
unsigned int		ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
char				*ft_strrchr(const char *str, int chr);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_printf(const char *str, ...);
int					ft_formats(va_list ap, const char format);
int					ft_printstr(char *str);
int					ft_hexpointer(unsigned long long ptr);
char				*ft_itoa(int n);
int					ft_printnbr(int n);
int					ft_udecimal(unsigned int num);
int					print_percent(void);
int					ft_print_hex(unsigned int num, const char format);
int					ft_printchar(int ch);

char				*get_next_line(int fd);
char				*ft_read_to_next_str(int fd, char *next_str);
char				*ft_get_line(char *next_str);
char				*ft_new_next_str(char *next_str);

#endif