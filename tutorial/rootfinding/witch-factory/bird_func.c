#include <stdio.h>
#include <math.h>

double e = 2.718281828459045;
double pi = 3.141592653589793;

double bird(double x, double y) {
	return (sin(x) * pow(e, pow(1 - cos(y), 2)) + cos(y) * pow(e, pow(1 - sin(x), 2)) + pow(x - y, 2));
}

int main() {

	int cnt = 0;
	//count the number of root
	double dx = 4 * pi / 1000;
	double dy = dx;

	for (double nx = -2 * pi; nx < 2 * pi; nx += dx) {
		for (double ny = -2 * pi; ny < 2 * pi; ny += dy) {

			double lowx = nx, lowy = ny;
			double highx = nx + dx, highy = ny + dy;
			
			int iter = 0;
			//count the number of iteration of binary search

			while (lowx <= highx && lowy <= highy) {
				double midx = (lowx + highx) / 2, midy = (lowy + highy) / 2;

				if (bird(lowx, lowy) * bird(highx, highy) > 0) { break; }
				//if the sign of function value is predicted to be unchanged in the section

				printf("x = %.10lf, y = %.10lf\n", midx, midy);
				printf("current function value : %.15lf\n", bird(midx, midy));
				//print the process of binary search

				if (-1e-13 < bird(midx, midy) && bird(midx, midy) < 1e-13) {
					//when the error becomes less than 1e-13, consider the (x,y) pair as a root and print it
					printf("we got the root, x = %.10lf, y = %.10lf\n", midx, midy);
					printf("bird function value : %.15lf\n", bird(midx, midy));
					printf("number of iteration : %d\n\n", iter);
					cnt++;
					break;
				}
				iter++;
				if (bird(lowx, lowy) * bird(midx, midy) < 0) { highx = midx; highy = midy; }
				if (bird(midx, midy) * bird(highx, highy) < 0) { lowx = midx; lowy = midy; }

			}
			
		}
	}
	printf("number of numerical root : %d\n", cnt);
}