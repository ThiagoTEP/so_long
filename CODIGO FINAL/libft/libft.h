/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:30:00 by user              #+#    #+#             */
/*   Updated: 2025/07/14 16:30:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char    *ft_strchr(const char *s, int c);
int		ft_printf(const char *str, ...);
void    *ft_memset(void *s, int c, size_t n);
char    *ft_substr(char const *s, unsigned int start, size_t len);
void    *ft_calloc(size_t nmemb, size_t size);
void    ft_putendl_fd(char *s, int fd);
int     ft_strcmp(const char *s1, const char *s2);
void    *ft_memmove(void *dest, const void *src, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char *line, char *stash);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);

#endif
