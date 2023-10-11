#ifndef WEBMAKER_H
#define WEBMAKER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#define row 10
#define col 10

typedef struct s_img
{
    void    *img;
    char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}               t_img;

typedef struct s_item
{
    char    *tag;
    char    *id;
    char    *class;
    int     ps_x;
    int     to_ps_x;
    int     ps_y;
    int     to_ps_y;
    int     x;
    int     y;
    t_img   *img;
    struct s_item  *next;
}               t_item;


typedef struct	s_data
{
    void	*mlx;
    void	*mlx_win;
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int     hold;
    t_item  *item;
}				t_data;


void generateHTML(t_item *head);
void clean_screen(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_divixel_put(t_img *data, int x, int y, int color);
void    display_grid(t_data *data);

#endif