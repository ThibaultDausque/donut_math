#include "donut.h"

const float theta_spacing = 0.07;
const float phi_spacing   = 0.02;

const float	R1 = 1;
const float	R2 = 2;

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

int	ft_donut()
{
	int		screen_width = 100;
	int		screen_height = 100;
	int		i = 0;
	int		j = 0;
	char	**output;
	char	dot = '.';

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
		float	costheta = R2 + R1 * cosf(theta);
		float	sintheta = R1 * sinf(theta);
		for (float phi = 0; phi < 2*M_PI; phi += phi_spacing)
		{
			// calcule x, and y postion for '.' placement
			// float	x;
			// float	y;
		}
	}
	return 1;
}
