#include <stdio.h>
#include <math.h>

void newton(float* estRoots);

void main()
{
	double estRoots[2], f, error;

	printf("Input initial point x, y\n");
	printf("x =");
	scanf("%lf", &estRoots[0]);
	printf("y =");
	scanf("%lf", &estRoots[1]);

	int i = 0;
	f = sin(estRoots[0]) * exp((1 - cos(estRoots[1])) * (1 - cos(estRoots[1]))) + cos(estRoots[1]) * exp((1 - sin(estRoots[0])) * (1 - sin(estRoots[0]))) + (estRoots[0] - estRoots[1]) * (estRoots[0] - estRoots[1]);
	while (f > 0.0000000001 || f < -0.0000000001)
	{
		printf("%d : Error = %.10lf\n", i, f);
		newton(estRoots, f);
		f = sin(estRoots[0]) * exp((1 - cos(estRoots[1])) * (1 - cos(estRoots[1]))) + cos(estRoots[1]) * exp((1 - sin(estRoots[0])) * (1 - sin(estRoots[0]))) + (estRoots[0] - estRoots[1]) * (estRoots[0] - estRoots[1]);
		++i;
	}

	printf("Final estimated point is (%lf, %lf)\n", estRoots[0], estRoots[1]);
	printf("Function value of final estimated point is %.10lf, Total attemp is %d", f, i);
}



// function = sin(x) * e^(1-cos(y))^2 + cos(y) * e^(1-sin(x))^2 + (x-y)^2
void newton(double estRoots[], double f)
{
	double dfdx, dfdy, x, y, grad;
	x = estRoots[0];
	y = estRoots[1];

	dfdx = cos(x) * exp((1 - cos(y)) * (1 - cos(y))) - 2 * cos(y) * cos(y) * (1 - sin(x)) * exp((1 - sin(x)) * (1 - sin(x))) + 2 * (x - y);
	dfdy = sin(x) * exp((1 - cos(y)) * (1 - cos(y))) * 2 * (1 - cos(y)) * sin(y) - sin(y) * exp((1 - sin(x)) * (1 - sin(x))) - 2 * (x - y);

	grad = sqrt(dfdx * dfdx + dfdy * dfdy);

	estRoots[0] = x - f * dfdx / (grad * grad);
	estRoots[1] = y - f * dfdy / (grad * grad);
}
