#include "../includes/wolf.h"

void	horizontal(t_wolf *data)
{
	float	yo;
	float	xo;
	float	rx;
	float	ry;
	
	data->crd.dof = 0;
	data->crd.dish = 100000;
	data->crd.hx = data->ppos.px;
	data->crd.hy = data->ppos.py;
	data->crd.atan = -1 / tan(data->crd.ra);
	if (data->crd.ra > PI)
	{
		ry = (int)data->ppos.py + (data->map.block - ((int)data->ppos.py % data->map.block)) - data->map.block - 0.0001;
		rx = (data->ppos.py - ry) * data->crd.atan + data->ppos.px;
		yo = -data->map.block;
		xo = -yo * data->crd.atan;
	}
	if (data->crd.ra < PI)
	{
		ry = (int)data->ppos.py + (data->map.block - ((int)data->ppos.py % data->map.block));
		rx = (data->ppos.py - ry) * data->crd.atan + data->ppos.px;
		yo = data->map.block;
		xo = -yo * data->crd.atan;
	}
	if (data->crd.ra == PI || data->crd.ra == 0)
	{
		rx = data->ppos.px;
		ry = data->ppos.py;
		data->crd.dof = data->map.height;
	}
	while (data->crd.dof < data->map.height)
	{
		data->crd.mx = (int)(rx) / data->map.block;
		data->crd.my = (int)(ry) / data->map.block;
		data->crd.mp = data->crd.my * data->map.width + data->crd.mx;
		if ((data->crd.mp > 0 && data->crd.mp < data->map.width * data->map.height && data->map.z_matrix[data->crd.my][data->crd.mx] == 1)  || (data->crd.my == 0  || data->crd.my == data->map.height))
		{
			data->crd.hx = rx;
			data->crd.hy = ry;
			data->crd.dish = distance(data->ppos.px, data->ppos.py, data->crd.hx, data->crd.hy);
			data->crd.dof = data->map.height;
		}
		else
		{
			rx += xo;
			ry += yo;
			data->crd.dof++;
		}
	}
}

void	vertical(t_wolf *data)
{
	float	yo;
	float	xo;
	float	rx;
	float	ry;
	
	data->crd.dof = 0;
	data->crd.disv = 100000;
	data->crd.vx = data->ppos.px;
	data->crd.vy = data->ppos.py;
	data->crd.ntan = -tan(data->crd.ra);
	if (data->crd.ra > PI2 && data->crd.ra < PI3)
	{
		rx = (int)data->ppos.px + (data->map.block - ((int)data->ppos.px % data->map.block)) - data->map.block - 0.0001;
		ry = (data->ppos.px - rx) * data->crd.ntan + data->ppos.py;
		xo = -data->map.block;
		yo = -xo * data->crd.ntan;
	}
	if (data->crd.ra < PI2 || data->crd.ra > PI3)
	{
		rx = (int)data->ppos.px + (data->map.block - ((int)data->ppos.px % data->map.block));
		ry = (data->ppos.px - rx) * data->crd.ntan + data->ppos.py;
		xo = data->map.block;
		yo = -xo * data->crd.ntan;
	}
	if (data->crd.ra == PI || data->crd.ra == 0)
	{
		rx = data->ppos.px;
		ry = data->ppos.py;
		data->crd.dof = data->map.width;
	}
	while (data->crd.dof < data->map.width)
	{
		data->crd.mx = (int)(rx) / data->map.block;
		data->crd.my = (int)(ry) / data->map.block;
		data->crd.mp = data->crd.my * data->map.width + data->crd.mx;
		if ((data->crd.mp > 0 && data->crd.mp < data->map.width * data->map.height && data->map.z_matrix[data->crd.my][data->crd.mx] == 1)  || (data->crd.mx == 0  || data->crd.mx == data->map.width))
		{
			data->crd.vx = rx;
			data->crd.vy = ry;
			data->crd.disv = distance(data->ppos.px, data->ppos.py, data->crd.vx, data->crd.vy);
			data->crd.dof = data->map.width;
		}
		else
		{
			rx += xo;
			ry += yo;
			data->crd.dof++;
		}
	}
}

void	hit(t_wolf *data)
{
	if (data->w < 2)
		data->t.hit = (int)data->crd.vy % data->map.block;
	else
		data->t.hit = (int)data->crd.hx % data->map.block;
}

void	comparison(t_wolf *data)
{
	if (data->crd.dish >= data->crd.disv)
	{
		data->crd.rrx = data->crd.vx;
		data->crd.rry = data->crd.vy;
		data->crd.dist = data->crd.disv;
		if (data->map.z_matrix[(int)(data->crd.rry) / data->map.block][(int)(data->crd.rrx + 1) / data->map.block] == 0)
			data->w = 0;
		else
			data->w = 1;
	}
	if (data->crd.dish < data->crd.disv)
	{
		data->crd.rrx = data->crd.hx;
		data->crd.rry = data->crd.hy;
		data->crd.dist = data->crd.dish;
		if (data->map.z_matrix[(int)(data->crd.rry - 1) / data->map.block][(int)(data->crd.rrx) / data->map.block] == 0)
			data->w = 2;
		else
			data->w = 3;	
	}
	hit(data);
}

void	draw_rays(t_wolf *data)
{
	int 		r;

	data->crd.ra = data->ppos.pa - 30 * DR;
	angle_checker(data);
	r = 0;
	while (r < 120)
	{
		horizontal(data);
		vertical(data);
		comparison(data);
		draw_3d(r, data);
		data->crd.ra += DR / 2;
		angle_checker(data);
		r++;
	}
}