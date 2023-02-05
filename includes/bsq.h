/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:15:47 by akurusio          #+#    #+#             */
/*   Updated: 2022/07/20 17:19:19 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BUFF_SIZE	256

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "queue.h"

typedef struct s_map_info
{
	int		n_lines;
	char	empty_ch;
	char	obst_ch;
	char	full_ch;
	int		l_length;
	int		sq_side;
	int		sq_x;
	int		sq_y;
}			t_map_info;

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
char	*ft_strcpy(char *src);
void	malloc_matrix(int ***matrix, int height, int width);
void	free_matrix(int **matrix, int height);
void	use_args(int ac, char **av);
void	use_std_input(void);
void	process_file(char *f_name);
void	read_and_process_any(int fd);
t_queue	*read_fd_to_queue(int fd);
void	process_queue(t_queue *q);
int		queue_to_matrix(t_queue *q, int ***matrix, t_map_info *map_info);
int		data_to_matrix(t_queue *q, int **matrix, t_map_info *map_info);
int		symbol_to_matrix(int **matrix, t_vector *xy,
			t_map_info *map_info, char ch);
void	write_valid_symbol(int **matrix, t_map_info *map_info,
			t_vector xy, char ch);
int		go_to_data_start(t_node *node, int i);
int		read_map_info(t_queue *q, t_map_info *map_info);
void	print_largest_square(int **matrix, t_map_info map_info);
int		any_two_equal(char ch1, char ch2, char ch3);
int		valid_symbol(t_map_info map_info, char ch);
int		calculate_width(t_queue *q);
int		newline_found(int *width, int *n_new_line, char ch);
int		solve_matrix(int **matrix, t_map_info *map_info,
			t_vector xy, int value);
int		min_three(int x, int y, int z);
void	display_error(void);
void	init_map_info(t_map_info *map_info);

#endif
