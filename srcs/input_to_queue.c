/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:40:20 by akurusio          #+#    #+#             */
/*   Updated: 2022/07/20 17:16:00 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "queue.h"

// Reads text from file descriptor fd and puts it into a string queue.
// Returns the queue with input content
t_queue	*read_fd_to_queue(int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;
	t_queue	*q;

	q = create_queue();
	ret = read(fd, buf, BUFF_SIZE);
	while (ret)
	{
		if (ret < 0)
			exit(1);
		buf[ret] = '\0';
		tmp = ft_strcpy(buf);
		en_queue(q, tmp);
		ret = read(fd, buf, BUFF_SIZE);
	}
	return (q);
}

// Connects the processes of reading the input from file descriptor and
// processing the resulting queue
void	read_and_process_any(int fd)
{
	t_queue	*q;

	q = (read_fd_to_queue(fd));
	if (q->first)
		process_queue(q);
	else
		display_error();
	clean_queue(q);
}

// Takes the filename and processes that file
void	process_file(char *f_name)
{
	int	fd;

	fd = open(f_name, O_RDONLY);
	if (fd == -1)
	{
		display_error();
		return ;
	}
	read_and_process_any(fd);
	if (close(fd) < 0)
		exit(1);
}

// Stdin case
void	use_std_input(void)
{
	read_and_process_any(STDIN_FILENO);
}

// Filenames case
void	use_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		process_file(av[i]);
		if (i < ac - 1)
			ft_putchar ('\n');
		i++;
	}
}
