#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *mlx;
	void *mlx_win;
	int pix;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000 , 650, "test");
	int i = 1;
	while(i < 20)
	{
		pix = mlx_pixel_put(mlx,mlx_win,1000/i,650/i,0xFFFFFF);
	i++;
	}
	mlx_loop(mlx);
	mlx_destroy_window(mlx,mlx_win);
	free(mlx);

}
