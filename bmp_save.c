#include "cub3d.h"

void bmp_make(t_param *p, int fd)
{
	int tmp;

	write(fd, "BM", 2); //signature indiquant que c'est un fichier bmp
	tmp = 40 + 14 + 4 * p->win_width * p->win_height;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4); //bf size
	tmp = 40;
	write(fd, &tmp, 4); //bi size
	write(fd, &p->win_width, 4); //largeur de l'image, c-a-d le nb de pixel horizontal
	write(fd, &p->win_height, 4); // hauteur
	tmp = 1;
	write(fd, &tmp, 2); // nb de plans, tjr = 1
	write(fd, &p->img.bits_per_pixel, 2); // profondeur du codage de la couleur, nb de bits utilisé pour code la couleur
	tmp = 0;
	write(fd, &tmp, 4); // méthode de compression, = 0 lorsque l'image n'est pas compressée
	write(fd, &tmp, 4); //la taille total de l'image
	write(fd, &tmp, 4); //resolution horizontale
	write(fd, &tmp, 4); //resolution verticale 
	write(fd, &tmp, 4); //nb de couleurs de la palette
	write(fd, &tmp, 4); // nb de couleurs importantes de la palette, = 0 quand chaque couleur a son importance
}

int	save(t_param *p)
{
	char *dest;
	int fd;
	int x;
	int y;

	if ((fd = open("./Screenshot_of_the_game.bmp", O_CREAT | O_RDWR)) == -1)
		return (quit(p, "Error :\nProblem creating the bmp fd.\n"));
	bmp_make(p, fd);
	y = p->win_height;
	while (y >= 0)
	{
		x = 0;
		while (x < p->win_width)
		{
			dest = p->img.addr + (y * p->img.line_length + x * (p->img.bits_per_pixel / 8));
			write(fd, &dest, 4);
			x++;
		}
		y--;
	}
	if (close(fd) == -1)
    	return (quit(p, "Error :\nClosing the bmp FD failed.\n"));
	return (quit(p, "Image saved !\n"));
}