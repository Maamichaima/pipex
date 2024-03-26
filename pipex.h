/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaami <cmaami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:15:38 by cmaami            #+#    #+#             */
/*   Updated: 2024/03/26 00:50:12 by cmaami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
	char	**env;
	int		in;
	int		out;
}			t_cmd;

typedef struct s_data
{
	char	**v;
	int		**pipe;
	char	*in;
	char	*out;
	char	**env;
	int		num_cmd;
	int		*pids;
}			t_data;

char		**ft_split(char *str, char *charset);
char		*ft_strjoin(char *s1, char *s2);
char		*correct_path(char **path, char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*path_in_env(char **env);
int			ft_is_mot(char *str);
int			ft_isalpha(int c);
char		*ft_strcpy(char *s1, char *s2);
void		executer(t_cmd cmd, t_data data);
void		inisialiser(t_data *data, char **v, char **env, int c);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
char		*ft_strjoin_(char *s1, char *s2);
char		*ft_strdup(const char *s1);
char		*ft_strchr(char *s, int c);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
void		uni_multi_pipe(t_data *data, t_cmd *cmd);
void		creer_cmd(t_data data, t_cmd *n, int index);
void		executer(t_cmd cmd, t_data data);
void		here_doc(t_data data, t_cmd cmd, char *limiter);
int			close_wait(t_data data);
void		outfile(t_data data, t_cmd *n, int index);
void		infile(t_data data, t_cmd *n);
void		creer_cmd_here(t_data data, t_cmd *n, int index, int *pipe_her);
void		pipe_here_doc(t_data data, t_cmd *cmd, int *pipe_her);
void		in_here_doc(t_data data, t_cmd *n, int *pipe_her);
void		*ft_fr_char(char **t);
void		*ft_fr_int(int i, int **t);
void		khwi(t_data data);

#endif
