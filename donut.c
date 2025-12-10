#include "donut.h"

const float theta_spacing = 0.07;
const float phi_spacing   = 0.02;

const float	R1 = 1;
const float	R2 = 2;
const float	K2 = 5;

const int	width = 100;
const int	height = 100;

int	free_tab(char **tab)
{
	int		i = 0;

	if (!tab)
		return 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return 1;
}

const float	K1 = (width*K2*3)/(8*(R1 + R2));
int	ft_donut()
{
	int		i = 0;
	int		j = 0;
	char	**output;

	output = (char**)malloc((height + 1) * sizeof(char*));
	if (!output)
		return 0;
	while (i < height)
	{
		j = 0;
		output[i] = (char*)malloc((width + 1) * sizeof(char));
		if (!output)
			return 0;
		while (j < width)
		{
			output[i][j] = ' ';
			j++;
		}
		output[i][j] = '\0';
		i++;
	}
	output[i] = NULL;

	for (float theta = 0; theta < 2*M_PI; theta += theta_spacing)
	{
		float	costheta = cos(theta);
		float	sintheta = sin(theta);
		for (float phi = 0; phi < 2*M_PI; phi += phi_spacing)
		{
			float	cosphi = cos(phi);
			float	sinphi = sin(phi);
			float	x = (R2 + R1 * costheta) * cosphi;
			float	y = R1 * sintheta;
			float	z = -(R2 + R1 * costheta) * sinphi;
			printf("x: %f, y: %f, z: %f\n", x, y, z);
			float	ozz = 1 / z;

			int		xp = (int) ((width / 2) + );
			int		yp = (int) (((height / 2) * y) / z);
			printf("xp: %d, yp: %d\n", xp, yp);
			output[yp][xp] = '.';
		}
	}
	for(int	i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			printf("%c", output[i][j]);
		}
		printf("\n");
	}
	return 1;
}

int	main(void)
{
	ft_donut();
	return 0;
}
