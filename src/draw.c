#include "webMaker.h"

void	my_divixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void clean_screen(t_data *data)
{
    int i, j;
    i = 0;
    j = 0;
    while (i < 800)
    {
        while (j < 920)
        {
            my_mlx_pixel_put(data, i, j, 0x00FFFFFF);
            j++;
        }
        j = 0;
        i++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void draw_horizontal_lines(t_data *data, int num_lines)
{
    int window_height = 400;
    int line_spacing = window_height / num_lines;

    for (int i = 0; i < num_lines; i++)
    {
        int y = i * line_spacing;

        for (int x = 0; x < 800; x++)
        {
            my_mlx_pixel_put(data, x, y, 0x000000); // Colore della linea (nero)
        }
    }

    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}


void display_grid(t_data *data)
{
    int window_width = 800;
    int line_spacing = 800 / col;

    for (int i = 0; i < col; i++)
    {
        int x = i * line_spacing;

        for (int y = 0; y < 920; y++)
        {
            my_mlx_pixel_put(data, x, y, 0x000000); // Colore della linea (nero)
        }
    }
    draw_horizontal_lines(data, row);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}


