#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"

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
    t_img   *img;
    int     x;
    int     y;
    char    *name;
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
    int     x;
    int     y;
    t_item  *item;
}				t_data;

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

void   inithtmlpage(FILE *fp)
{
    fprintf(fp, "init\n");
}

int mouse_move(int x, int y, t_data *data)
{
    int h, w;
    w = 54;
    h = 20;
    if (data->hold == 1)
    {
        // printf("x: %d\n", x);
        // printf("y: %d\n", y);
        data->item->x = x;
        data->item->y = y;
    }
    
    return (0);
}

t_item	*ft_last_item(t_item *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_itemadd_front(t_item **lst, t_item *new)
{
	new->next = lst[0];
	lst[0] = new;
}

void	ft_itemadd_back(t_item **lst, t_item *new)
{
	t_item	*temp;

	if (lst)
	{
		if (lst[0] == 0)
			lst[0] = new;
		else
		{
			temp = ft_last_item(lst[0]);
			temp->next = new;
		}
	}
}

int	ft_itemsize(t_item *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void draw_dashed_line(t_img *img, int x0, int y0, int x1, int y1, int dash_length, int gap_length, int color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    int dash_counter = 0; // Contatore per la lunghezza del tratteggio
    int draw_pixel = 1;   // Variabile per decidere se disegnare il pixel o meno

    while (1) {
        if (dash_counter < dash_length) {
            if (draw_pixel) {
                my_divixel_put(img, x0, y0, color);
            }
            dash_counter++;
        } else {
            dash_counter = 0;
            draw_pixel = !draw_pixel; // Inverti il valore
        }

        if (x0 == x1 && y0 == y1) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}


void    create_div(t_img *img)
{
    int i, j;
    i = 0;
    j = 0;
    while (i < 800)
    {
        while (j < 100)
        {
            my_divixel_put(img, i, j, 0x00FFFFFF);
            j++;
        }
        j = 0;
        i++;
    }
}

t_item  *what_item(t_data *data, char *name, int x, int y)
{
    t_item *new;
    int h, w;

    w = 54;
    h = 20;

    new = ft_calloc(1, sizeof(t_item));
    new->name = name;
    new->x = x;
    new->y = y;
    new->img = ft_calloc(1, sizeof(t_img));
    if (strcmp(name, "btn") == 0)
        new->img->img = mlx_xpm_file_to_image(data->mlx, "src/btn.xpm", &w, &h);
    else if (strcmp(name, "div") == 0)
    {
        new->img->img = mlx_new_image(data->mlx, 800, 100);
        new->img->addr = mlx_get_data_addr(new->img->img, &new->img->bits_per_pixel, &new->img->line_length, &new->img->endian);
        create_div(new->img);
        new->x = 0;
        new->y = 0;
        draw_dashed_line(new->img, 0, 99, 800, 99, 5, 5, 0);
    }
    
    new->name = ft_strjoin(new->name, ft_itoa(ft_itemsize(data->item)));
    return (new);
}

void    ft_add_item(t_data *data, char *name, int x, int y)
{
    t_item *new;
    t_item *head;
    int i;
    int h, w;

    w = 54;
    h = 20;
    new = what_item(data, name, x, y);
    // new = ft_calloc(1, sizeof(t_item));
    // new->name = name;
    // new->x = x;
    // new->y = y;
    // new->img = ft_calloc(1, sizeof(t_img));
    // new->img->img = mlx_xpm_file_to_image(data->mlx, "src/btn.xpm", &w, &h);
    // new->name = ft_strjoin(new->name, ft_itoa(ft_itemsize(data->item)));
    if (data->item[0].name == 0)
    {
        printf("OK\n");
        data->item[0] = *new;
    }
    else
    {
        head = data->item;
        ft_itemadd_back(&data->item, new);
        data->item = head;
    }
}

int mouse_hook(int button, int x, int y, t_data *data)
{
    printf("button: %d\n", button);
    // printf("x: %d\n", x);
    if (button == 1)
    {
        ft_add_item(data, "btn", x, y);
        data->hold = 1;
    }
    if (button == 3)
    {
        ft_add_item(data, "div", x, y);
        // data->hold = 1;
    }
    
    return (0);
}


int mouse_release(int button, int x, int y, t_data *data)
{
    printf("release\n");
    if (button == 1)
    {
        data->item->x = x;
        data->item->y = y;
    }
    data->hold = 0;
    return (0);
}

void    put_to_window(t_data *data, void *img)
{
    mlx_put_image_to_window(data->mlx, data->mlx_win, img, data->item->x, data->item->y);
}

void	ft_itemiter(t_data *data, void (*f)(t_data *data, void *))
{
    t_item *head;
    int x = 0;

	head = data->item;
	while (data->item)
	{
        // printf("item->name: %s\n", data->item->name);
        // printf("x: %d\n", x);
		f(data, data->item->img->img);
		data->item = data->item->next;
        x++;
	}
    // exit(0);
    data->item = head;
}

int display(t_data *data)
{
    clean_screen(data);
    if (data->item)
        ft_itemiter(data, put_to_window);
    // mlx_put_image_to_window(data->mlx, data->mlx_win, data->item->img, data->x, data->y);
    return (0);
}

void    ft_compile(t_data *data)
{
    FILE *fp;
    fp = fopen("prova.map", "w");
    fprintf(fp, "init\n");
    while(data->item)
    {
        fprintf(fp, "%s %d %d\n", data->item->name, data->item->x, data->item->y);
        data->item = data->item->next;
    }
    fclose(fp);
}

int keypress(int keycode, t_data *data)
{
    printf("keycode: %d\n", keycode);
    if (keycode == 65307)
    {
        ft_compile(data);
        exit(0);
    }
    return (0);
}

int resize(t_data *data)
{
    printf("resizen/n");
    return (0);
}

int		main(void)
{
    t_data	data;
    
    
    data.item = ft_calloc(1, sizeof(t_item));
    int h, w;
    w = 54;
    h = 20;
    data.x,data.y = 0;
    data.hold = 0;
    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, 840, 920, "Hello world!");
    data.img = mlx_new_image(data.mlx, 840, 920);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    clean_screen(&data);
    data.item = ft_calloc(1, sizeof(t_item));
    data.item->name = "empty";
    data.item->img = ft_calloc(1, sizeof(t_img));
    data.item->img->img = mlx_xpm_file_to_image(data.mlx, "src/btn.xpm", &w, &h);
    mlx_mouse_hook(data.mlx_win, mouse_hook, &data);
    mlx_hook(data.mlx_win, 2, 1L<<0, keypress, &data);
    mlx_hook(data.mlx_win, 6, 1L<<6, mouse_move, &data);
    mlx_hook(data.mlx_win, 25, 1L<<18, resize, &data);
    mlx_hook(data.mlx_win, 5, 1L<<3, mouse_release, &data);
    mlx_loop_hook(data.mlx, display, &data);
    mlx_loop(data.mlx);
    
}