/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurusio <akurusio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:42:03 by akurusio          #+#    #+#             */
/*   Updated: 2022/07/20 17:02:07 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strcpy(char *src)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * BUFF_SIZE + 1);
	if (!res)
		exit(1);
	i = 0;
	while (src [i] != '\0' )
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
