/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:57:33 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/26 17:31:08 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		validate_map_features_custom(char **arr)
{
	int i;
	int j;
	int pande;
	int c;
	i = 0;
	j = 0;
	c = 0;
	pande = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == 'E' || arr[i][j] == 'P')
				pande++;
			else if (arr[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (pande != 2)
	{
		printf("Invalid elements\n");
		return(1);
	}
	if (c < 1)
	{
		printf("Invalid elements\n");
		return(1);
	}
	return(0);
}

int	validate_map_element(char **arr)
{
	int	i;
	int	valid;
	int	j;
	int	last_row_index;
	int	last_column_index;

	i = 0;
	j = 0;
	last_row_index = 0;
	last_column_index = 0;
	while (arr[0][j] != '\0')
	{
		last_column_index = j;
		j++;
	}
	last_column_index--;
	while (arr[i] != NULL)
	{
		last_row_index = i;
		i++;
	}
	j = 0;
	while (j <= last_column_index)
	{
		if (arr[0][j] != '1' || arr[last_row_index][j] != '1')
		{
			printf("Error ->WrongWall\n");
			return (1);
		}
		j++;
	}
	i = 0;
	while (i <= last_row_index)
	{
		if (arr[i][0] != '1' || arr[i][last_column_index] != '1')
		{
			printf("Error ->WrongWall\n");
			return (1);
		}
		i++;
	}
	valid = validate_map_features_custom(arr);
	return (valid);
}

int	validate_map_features(char **arr)
{
	int	i;
	int	j;
	int	len;
	int	valid;

	i = 0;
	len = -1;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\n' && arr[i][j] != '\0')
		{
			j++;
		}
		if (len == -1)
			len = j;
		else if (len != j)
		{
			printf("Error ->Invalid map\n");
			return (1);
		}
		i++;
	}
	valid = validate_map_element(arr);
	return (valid);
}

char	**fill_map_arr(char *filename)
{
	char	**arr;
	char	**new_arr;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	i = 0;
	arr = NULL;
	if (fd == -1)
	{
		printf("Error\n");
		return (NULL);
	}
	filename = get_next_line(fd);
	if (fd == -1 || fd == 0 || filename == NULL)
	{
		printf("Error\n");
		return (NULL);
	}
	while (filename != NULL)
	{
		new_arr = malloc(sizeof(char *) * (i + 2));
		if (new_arr == NULL)
		{
			printf("Error\n");
			return (NULL);
		}
		if (arr != NULL)
		{
			ft_memcpy(new_arr, arr, sizeof(char *) * (i));
			free(arr);
		}
		arr = new_arr;
		arr[i] = filename;
		arr[i + 1] = NULL;
		i++;
		filename = get_next_line(fd);
	}
	close(fd);
	return (arr);
}
// int tester (t_mlx   *win)
// {
// 	mlx_put_image_to_window (win->mlx, win->mlx_win, win->test_img, 50, 200);
// 	return 0;
// }
int	main(int argc, char **argv)
{
	int		i;
	char	**arr;
	t_mlx   win;
	int		validate;
	
	if (argc != 2)
		return (1);
	i = ft_strleng(argv[1]);
	if (i < 4 || (argv[1][i - 4] != '.' || argv[1][i - 3] != 'b' || argv[1][i
			- 2] != 'e' || argv[1][i - 1] != 'r'))
		return (1);
	arr = fill_map_arr(argv[1]);
	validate = validate_map_features(arr);
	/*to show mlx image handling*/
	char	*relative_path = "textures/Mountain.xpm";
	int		img_width = 30;
	int		img_height  = 30;
	if (validate == 0)
{
    win.mlx = mlx_init();
    win.mlx_win = mlx_new_window(win.mlx, 1920, 1080, "So_Long");
    win.test_img = mlx_xpm_file_to_image(win.mlx, relative_path, &img_width, &img_height);
    if (win.test_img == NULL)
    {
        printf("Error loading image\n");
        return (1);
    }
    mlx_put_image_to_window(win.mlx, win.mlx_win, win.test_img, 500, 500);
    mlx_loop(win.mlx);
}
	return (0);
}

