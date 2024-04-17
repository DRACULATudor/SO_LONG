/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:56:42 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/17 15:04:01 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	error_fct(int num)
{
	num = 1;
	write(2, "Error\n", 7);
	return (num);
}

char	**error_fctc(int num)
{
	num = 1;
	write(2, "Error\n", 7);
	num = num - 1;
	return (NULL);
}

void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
