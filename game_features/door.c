/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:21:48 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/11 19:21:52 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void handle_door(t_mlx *win, int i, int j, int *door_frame)
{
    if (win->arr[i][j] == 'E')
    {
        if (win->door_opening)
        {
            mlx_put_image_to_window(win->mlx, win->mlx_win,
                win->door_imgs[*door_frame], j * 64, i * 64);
            if (*door_frame == 4)
            {
                win->exit = true;
            }
        }
        else if (check_for_colectables(win) == false)
        {
            win->door_opening = true;
            *door_frame = 0;
        }
    }
}

void update_frames(t_mlx *win, int *current_frame, int *door_frame, int *counter)
{
    if (*counter % 1000 == 0)
    {
        *current_frame = (*current_frame + 1) % 8;
        if (win->door_opening && *door_frame < 4)
        {
            if (*counter % 5 == 0)
            {
                (*door_frame)++;
            }
        }
    }
    (*counter)++;
}

int display_next_frame_and_door(t_mlx *win)
{
    static int current_frame = 0;
    static int door_frame = 0;
    static int counter = 0;
    int i;
    int j;
    int p_x;
    int p_y;

    if (win == NULL || win->arr == NULL)
    {
        printf("Error: arr or win is NULL\n");
        return (1);
    }
    i = 0;
    while (win->arr[i] != NULL)
    {
        j = 0;
        p_x = get_e_x(win->arr);
        while (win->arr[i][j] != '\0')
        {
            p_y = get_e_y(win->arr);
            handle_exit(win, i, j, p_x, p_y);
            handle_coin(win, i, j, &current_frame);
            handle_door(win, i, j, &door_frame);
            j++;
        }
        i++;
    }
    update_frames(win, &current_frame, &door_frame, &counter);
    return (0);
}