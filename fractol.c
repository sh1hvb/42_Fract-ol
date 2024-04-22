/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:13:20 by mchihab           #+#    #+#             */
/*   Updated: 2024/04/23 00:12:42 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
void fract_ren(t_fract *fract);

int close_win(t_fract *fract)
{
    mlx_destroy_image(fract->mlx_conn,fract->img.img);
    mlx_destroy_window(fract->mlx_conn,fract->mlx_win);
    mlx_destroy_display(fract->mlx_conn);
    free(fract->mlx_conn);
    exit(1);
    return 0;
}
int onclick(int keysim,t_fract *fract)
{
    if(keysim == XK_Escape)
        close_win(fract);
    if(keysim == XK_Left)
        fract->shift_x-=0.5;
    else if(keysim == XK_Right)
        fract->shift_x+=0.5;
    else if(keysim == XK_Up)
        fract->shift_y+=0.5;
    else if(keysim == XK_Down)
        fract->shift_y-= 0.5;
    else if(keysim == XK_equal)
        fract->iterations+=10;
    else if(keysim == XK_minus)
        fract->iterations-=10;
    fract_ren(fract);
    return 0;
}

void handle_events(t_fract *fract)
{
    mlx_hook(fract->mlx_win, KeyPress, KeyPressMask, onclick, fract);
    // mlx_hook(fract->mlx_win, KeyPress, KeyPressMask, onclick, fract);
    mlx_hook(fract->mlx_win, DestroyNotify, StructureNotifyMask, close_win, fract);

}
void init_data(t_fract *fract)
{
    fract->iterations = 42;
    fract->escaped = 4 ;
    fract->shift_x= 0.0;
    fract->shift_y= 0.0;

}
t_cmplx sum(t_cmplx z1, t_cmplx z2)
{
    t_cmplx r;
    r.x = z1.x + z2.x;
    r.y = z1.y + z2.y;
    return r;
}
void pixel_put_in(int x ,int y , t_img *img , int color)
{
    int of;

    of = (y * img->len) + (x * (img->bpp / 8));
    *(unsigned int  *)(img->p_pixels + of) = color;
}
t_cmplx square(t_cmplx z)
{
    t_cmplx r;
    
    r.x= (z.x * z.x) - (z.y * z.y);
    r.y = 2 * z.x * z.y;
    return r;
}

double scale(double unum, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min)* (unum -old_min) / (old_max -old_min) + new_min;
}
void handle_pix(int x, int y, t_fract *fract)
{
    t_cmplx z;
    t_cmplx c;
    int i ;
    int rgb;

    i = 0;
    z.x =0;
    z.y =0;
    
    c.x= scale(x ,-2 ,+2 ,0,800) + fract->shift_x;
    c.y = scale(y , +2 ,-2,0 ,800) + fract->shift_y;
    while(i < fract->iterations)
    {
        z = sum(square(z) , c);
        if((z.x * z.x) - (z.y * z.y) > fract->escaped)
        {
            rgb = scale(i,WHITE , BLACK, 0 ,fract->iterations);
            pixel_put_in(x , y , &fract->img, rgb);
            return;
        }
        ++i;
    }
    pixel_put_in(x , y , &fract->img,MAGENTA);

}

void fract_ren(t_fract *fract)
{
    int x;
    int y;

    // x = 0;
    y = 0;
    while (y < 800)
    {
        x = 0;
        while (x < 800)
        {
            handle_pix(x,y,fract);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fract->mlx_conn,fract->mlx_win,fract->img.img, 0, 0);
    
}
void init_fract(t_fract *fract)
{
    fract->mlx_conn= mlx_init();
    if(NULL == fract->mlx_conn)
        return;
    fract->mlx_win = mlx_new_window(fract->mlx_conn,800,800,fract->name);
    if(fract->mlx_win == NULL)
    {
        // mlx_clear_window(fract->mlx_conn, fract->mlx_win);
        mlx_destroy_display(fract->mlx_conn);
    }
    fract->img.img= mlx_new_image(fract->mlx_conn, 800,800);
    fract->img.p_pixels= mlx_get_data_addr(fract->img.img,&fract->img.bpp,&fract->img.len, &fract->img.endian);

    init_data(fract);
    handle_events(fract);
}
int main(int ac , char **av)
{
    t_fract fract;
    if((ac == 2 && !ft_strncmp(av[1] , "mandelbrot",10) ) || (ac == 4 && !ft_strncmp(av[1],"julia",5)))
    {
        fract.name = av[1];
        init_fract(&fract);
        fract_ren(&fract);
        mlx_loop(fract.mlx_conn);
    }
    else    
    {
        ft_putendl_fd("please enter a correct value",2);
        exit(1);
    }
}