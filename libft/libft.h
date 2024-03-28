/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasquez <jvasquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:28:16 by jvasquez          #+#    #+#             */
/*   Updated: 2024/03/28 20:03:16 by jvasquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_tree {
	void			*data;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

/* Check functions */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(char c);

/* String functions */
size_t	ft_strlen(const char *str);
void	ft_strfreel(char **str);
char	**ft_strbrk(char *str, int b_point);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
int		ft_chr_count(char *str, char c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strrep(char *str, char *old, char *new);
char	*ft_strget_btwn(char *str, int start, char ini, char end);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoinfree(char *s1, char *s2, int which);
char	**ft_split(const char *str, char delimiter);
char	*ft_unsplit(char **sarr, char *sep);
char	*ft_strtrim(char const *str, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/* Memory functions */
void	ft_bzero(void *str, size_t n);
void	*ft_memset(void *str, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);

/* Char functions */
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_chrpos(char *str, int chr, int start);

/* Print functions */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* List functions */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* To functions */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_atoi_pos(char *str, int *pos);
int		ft_atoi_btwn(char *str, char ini, char end);
double	ft_atod(char *str);

/* String Array functions */
int		ft_sarrsize(char **arr);
int		ft_sarrprint(char **arr);
int		ft_sarrcmp(char **arr, char *str);
void	ft_sarrfree(char ***arr);
char	**ft_sarrcpy(char **arr);
char	**ft_sarrrmi(int index, char **arr);
char	**ft_sarradd(char **arr, char *string);
char	**ft_sarrrep(char **arr, int index, char *str);

/* Tree functions */
t_tree	*tree_new_node(void *data);
void	tree_in_order(t_tree *tree, void (*ft)(void*));
void	tree_pre_order(t_tree *tree, void (*ft)(void*));
void	tree_post_order(t_tree *tree, void (*ft)(void*));
void	tree_del_node(t_tree *node, void (*del)(void*));

#endif
