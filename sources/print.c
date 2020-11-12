#include "../includes/wolf.h"

void	*print_wolf(void *data)
{
	t_wolf *newdata;

	newdata = (t_wolf *)data;
	while (newdata->x < WIDTH)
	{
		printlab(data);
		newdata->x++;
	}
	newdata->x = 0;
	data = newdata;
	return (0);
}

int		print_thread_wolf(t_wolf *data)
{
	data->y = 0;
	data->x = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	while (data->y < HEIGHT)
	{
		print_wolf((void*)data);
		data->y++;
	}
	printvision(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
	return (0);
}
