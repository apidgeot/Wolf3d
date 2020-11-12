#include "wolf.h"

void	key1(int key, t_wolf *data)
{
	if (key == ARROW_UP)
	{
		data->ppos.px += data->ppos.pdx;
		data->ppos.py += data->ppos.pdy;
	}
	if (key == ARROW_DOWN)
	{
		data->ppos.px -= data->ppos.pdx;
		data->ppos.py -= data->ppos.pdy;
	}
}

void	key2(int key, t_wolf *data)
{
	if (key == ARROW_LEFT)
	{
		data->ppos.pa -= 0.1;
		if (data->ppos.pa < 0)
			data->ppos.pa += 2 * PI;
		data->ppos.pdx = cos(data->ppos.pa) * 5;
		data->ppos.pdy = sin(data->ppos.pa) * 5;
	}
	if (key == ARROW_RIGHT)
	{
		data->ppos.pa += 0.1;
		if (data->ppos.pa > 2 * PI)
			data->ppos.pa -= 2 * PI;
		data->ppos.pdx = cos(data->ppos.pa) * 5;
		data->ppos.pdy = sin(data->ppos.pa) * 5;
	}
}

void	key3(t_wolf *data)
{
	data->ppos.px = data->map.new_width / 2;
	data->ppos.py = data->map.new_height / 2;
	data->ppos.pa = PI2;
}
