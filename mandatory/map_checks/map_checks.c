/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:13:51 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/24 21:07:15 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	validate_map_features_custom(char **arr)
{
	int	pande;
	int	c;

	pande = 0;
	c = 0;
	count_map_features(arr, &pande, &c);
	if (pande != 2)
		return (error_fct(pande));
	if (c < 1)
		return (error_fct(c));
	return (0);
}

int	calculate_width(char **arr, t_mlx *win)
{
	int	j;
	int	last_column_index;

	j = 0;
	last_column_index = 0;
	while (arr[0][j] != '\0')
	{
		last_column_index = j;
		j++;
	}
	j--;
	win->width = j;
	last_column_index--;
	return (last_column_index);
}

int	calculate_height(char **arr, t_mlx *win)
{
	int	i;
	int	last_row_index;

	i = 0;
	last_row_index = 0;
	while (arr[i] != NULL)
	{
		last_row_index = i;
		i++;
	}
	win->height = last_row_index + 1;
	return (last_row_index);
}

int	validate_map_element(char **arr, t_mlx *win)
{
	int	i;
	int	valid;
	int	j;
	int	last_row_index;
	int	last_column_index;

	last_row_index = calculate_height(arr, win);
	last_column_index = calculate_width(arr, win);
	j = 0;
	while (j <= last_column_index)
	{
		if (arr[0][j] != '1' || arr[last_row_index][j] != '1')
			return (error_fct(1));
		j++;
	}
	i = 0;
	while (i <= last_row_index)
	{
		if (arr[i][0] != '1' || arr[i][last_column_index] != '1')
			return (error_fct(1));
		i++;
	}
	valid = validate_map_features_custom(arr);
	return (valid);
}

int	validate_map_features(char **arr, t_mlx *win)
{
	int	i;
	int	j;
	int	len;
	int	valid;

	if (arr == NULL)
		exit (1);
	i = 0;
	len = -1;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\n' && arr[i][j] != '\0')
			j++;
		if (len == -1)
			len = j;
		else if (len != j)
		{
			write(2, "Error\n", 7);
			exit (1);
		}
		i++;
	}
	valid = validate_map_element(arr, win);
	return (valid);
}
