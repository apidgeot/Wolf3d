#include "../includes/wolf.h"

void			printvision(t_wolf *data)
{
	float	x;
	float	y;

	x = data->ppos.px + data->ppos.pdx * 5;
	y = data->ppos.py + data->ppos.pdy * 5;
	draw_rays(data);
}

void			printlab(t_wolf *data)
{
	int w;
	int h;

	w = data->x / data->map.block;
	h = data->y / data->map.block;
}
