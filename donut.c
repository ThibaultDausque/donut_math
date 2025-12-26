#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

# define PI 3.14159265358979323846

const float theta_spacing = 0.07;
const float phi_spacing   = 0.02;

const float	R1 = 1;
const float	R2 = 2;
const float	K2 = 5;

const int	width = 50;
const int	height = 50;

const float	K1 = (width*K2*3)/(8*(R1+R2));
int	ft_donut(float A, float B)
{
	char	output[height][width];
	float	zbuffer[height][width];
	char	*luminance = ".,-~:;=!*#$@";

	memset(output, ' ', sizeof(output));
	memset(zbuffer, 0, sizeof(zbuffer));
	for (float theta = 0; theta < 2*M_PI; theta += theta_spacing)
	{
		float	costheta = cos(theta);
		float	sintheta = sin(theta);
		for (float phi = 0; phi < 2*M_PI; phi += phi_spacing)
		{
			float	cosphi = cos(phi);
			float	sinphi = sin(phi);
			
			float	x = (R2 + R1*costheta)*(cos(B)*cosphi + sin(A)*sin(B)*sinphi) - R1*cos(A)*sin(B)*sintheta;
			float	y = (R2 + R1 * costheta)*(cosphi*sin(B) - cos(B)*sin(A)*sinphi) + R1*cos(A)*cos(B)*sintheta;
			float	z = K2 + cos(A)*(R2 + R1*costheta)*sinphi + R1*sin(A)*sintheta;
			float	ooz = 1/z;
			int		xp = (int) (width/2 + K1*ooz*x);
			int		yp = (int) (height/2 - (K1*0.5)*ooz*y);
			
			float	L = cosphi*costheta*sin(B) - cos(A)*costheta*sinphi - sin(A)*sintheta + cos(B)*(cos(A)*sintheta - costheta*sin(A)*sinphi);
			if (L > 0)
			{
				if (ooz > zbuffer[yp][xp])
				{
					zbuffer[yp][xp] = ooz;
					int		lum_idx = L * 8;
					output[yp][xp] = luminance[lum_idx];
				}
			}
		}
	}
	printf("\x1b[2J\x1b[H");
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			putchar(output[i][j]);
		}
		putchar('\n');
	}
	return 1;
}

int	main(void)
{
	float	A = 0;
	float	B = 0;
	while (1)
	{
		ft_donut(A, B);
		A += 0.004;
		B += 0.005;
	}
	return 0;
}
