#include "mlx.h"

#define WIDTH 800
#define HEIGHT 800
#define DEPTH 6

typedef struct s_mlx {
	void *mlx_ptr;
	void *win_ptr;
}				t_mlx;

// Function to draw the Sierpiński triangle
void draw_sierpinski(t_mlx *mlx, int depth, int x1, int y1, int x2, int y2, int x3, int y3) {
	if (depth == 0) {
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x1, y1, 0xFFFFFF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x2, y2, 0xFFFFFF);
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x3, y3, 0xFFFFFF);
	} else {
		int midx1 = (x1 + x2) / 2;
		int midy1 = (y1 + y2) / 2;
		int midx2 = (x2 + x3) / 2;
		int midy2 = (y2 + y3) / 2;
		int midx3 = (x1 + x3) / 2;
		int midy3 = (y1 + y3) / 2;

		draw_sierpinski(mlx, depth - 1, x1, y1, midx1, midy1, midx3, midy3);
		draw_sierpinski(mlx, depth - 1, midx1, midy1, x2, y2, midx2, midy2);
		draw_sierpinski(mlx, depth - 1, midx3, midy3, midx2, midy2, x3, y3);
	}
}

int main(void) {
	t_mlx mlx;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "Sierpiński Triangle");
	draw_sierpinski(&mlx, DEPTH, WIDTH / 2, 0, 0, HEIGHT, WIDTH, HEIGHT);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
