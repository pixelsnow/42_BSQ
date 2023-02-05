/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:07:53 by vvagapov          #+#    #+#             */
/*   Updated: 2022/07/20 17:11:55 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_node	*create_elem(char *data)
{
	t_node	*res;

	res = malloc(sizeof(t_node));
	if (!res)
		exit(1);
	res->next = NULL;
	res->data = data;
	return (res);
}

t_queue	*create_queue(void)
{
	t_queue	*res;

	res = malloc(sizeof(t_queue));
	if (!res)
		exit(1);
	res->first = NULL;
	res->last = NULL;
	return (res);
}

void	en_queue(t_queue *q, char *data)
{
	t_node	*tmp;

	tmp = create_elem(data);
	if (!q->last)
	{
		q->first = tmp;
		q->last = tmp;
	}
	else
	{
		q->last->next = tmp;
		q->last = tmp;
	}
}

void	de_queue(t_queue *q)
{
	t_node	*tmp;

	if (!q->first)
		return ;
	tmp = q->first;
	q->first = q->first->next;
	if (tmp->data)
		free(tmp->data);
	free(tmp);
}

void	clean_queue(t_queue *q)
{
	while (q->first)
		de_queue(q);
	free(q);
}
