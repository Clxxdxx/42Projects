/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:41:16 by clalopez          #+#    #+#             */
/*   Updated: 2025/04/08 15:15:13 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

// LIBFT
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *str);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strcpy(char *dst, const char *src);

// PIPEX
void	error_exit(const char *msg);
void	cmd_not_found(char *cmd);
char	*get_full_path(char *cmd, char **envp);
char	**ft_split(char const *s, char c);
void	ft_free_split(char **arr);
void	child_process(char *cmd, int in, int out, char **envp);

#endif