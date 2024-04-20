#include "minilibx-linux/mlx.h"

void draw_circle(void *mlx, void *mlx_win, int center_x, int center_y, int radius, int color)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        // Plot points using symmetry
        mlx_pixel_put(mlx, mlx_win, center_x + x, center_y + y, color);
        mlx_pixel_put(mlx, mlx_win, center_x - x, center_y + y, color);
        mlx_pixel_put(mlx, mlx_win, center_x + x, center_y - y, color);
        mlx_pixel_put(mlx, mlx_win, center_x - x, center_y - y, color);
        mlx_pixel_put(mlx, mlx_win, center_x + y, center_y + x, color);
        mlx_pixel_put(mlx, mlx_win, center_x - y, center_y + x, color);
        mlx_pixel_put(mlx, mlx_win, center_x + y, center_y - x, color);
        mlx_pixel_put(mlx, mlx_win, center_x - y, center_y - x, color);

        if (err <= 0)
        {
            y += 6;
            err += 2 * y + 1;
        }
        if (err > 0)
        {
            x -= 2;
            err -= 2 * x + 1;
        }
    }
}

int main()
{
    void *mlx;
    void *mlx_win;

    // Initialize mlx
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 600, "Circle");

    // Draw circle
    draw_circle(mlx, mlx_win, 400, 300, 100, 0xFFFFFF); // Center at (400, 300), radius 100, white color

    mlx_loop(mlx);

    return 0;
}
