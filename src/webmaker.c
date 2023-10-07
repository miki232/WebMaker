#include "webMaker.h"

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

t_item  *what_item(t_data *data, char *tag, int x, int y)
{
    t_item *new;
    int h, w;

    w = 54;
    h = 20;

    new = ft_calloc(1, sizeof(t_item));
    new->tag = tag;
    new->x = x;
    new->y = y;
    new->img = ft_calloc(1, sizeof(t_img));
    if (strcmp(tag, "btn") == 0)
    {
        new->img->img = mlx_xpm_file_to_image(data->mlx, "src/btn.xpm", &w, &h);
        new->class = ft_strjoin("my-button", ft_itoa(ft_itemsize(data->item)));;
    }
    // else if (strcmp(tag, "div") == 0)
    // {
    //     new->img->img = mlx_new_image(data->mlx, 800, 100);
    //     new->img->addr = mlx_get_data_addr(new->img->img, &new->img->bits_per_pixel, &new->img->line_length, &new->img->endian);
    //     create_div(new->img);
    //     new->x = 0;
    //     new->y = 0;
    //     draw_dashed_line(new->img, 0, 99, 800, 99, 5, 5, 0);
    // }
    
    new->id = ft_strjoin(new->tag, ft_itoa(ft_itemsize(data->item)));
    return (new);
}

void	ft_itemadd_front(t_item **lst, t_item *new)
{
	new->next = lst[0];
	lst[0] = new;
}

t_item	*ft_last_item(t_item *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
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

void    ft_add_item(t_data *data, char *tag, int x, int y)
{
    t_item *new;
    t_item *head;
    int i;
    int h, w;

    w = 54;
    h = 20;
    new = what_item(data, tag, x, y);
    if (data->item == NULL)
    {
        data->item = new;
        printf("OK %s\n", new->tag);
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
    if (button == 1)
    {
        ft_add_item(data, "btn", x, y);
        data->hold = 1;
    }    
    return (0);
}

int mouse_move(int x, int y, t_data *data)
{
    if (data->hold == 1)
    {
        // printf("x: %d\n", x);
        // printf("y: %d\n", y);
        data->item->x = x;
        data->item->y = y;
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


int keypress(int keycode, t_data *data)
{
    printf("keycode: %d\n", ft_itemsize(data->item));
    if (keycode == 65307)
    {
        generateHTML(data->item);
        // exit(0);
    }
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
	while (data->item->next)
	{
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
    display_grid(data);
    if (data->item)
        ft_itemiter(data, put_to_window);
    // mlx_put_image_to_window(data->mlx, data->mlx_win, data->item->img, data->x, data->y);
    return (0);
}

int main()
{
    t_data *data;
    data = calloc(1, sizeof(t_data));
    data->item = NULL;
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, 800, 920, "Web Maker");
    data->img = mlx_new_image(data->mlx, 800, 920);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
                                   &data->endian);
    clean_screen(data);
    mlx_mouse_hook(data->mlx_win, mouse_hook, data);
    mlx_hook(data->mlx_win, 2, 1L<<0, keypress, data);
    mlx_hook(data->mlx_win, 6, 1L<<6, mouse_move, data);
    mlx_hook(data->mlx_win, 5, 1L<<3, mouse_release, data);
    // mlx_hook(data->mlx_win, 25, 1L<<18, resize, data);
    mlx_loop_hook(data->mlx, display, data);

    mlx_loop(data->mlx);
}