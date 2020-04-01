#include <stdio.h>
#include <math.h>
const long double eps = 1e-10;
inline double PI() { return 2.0 * acos(0); }
double s = 1e-2;
int cnt = 0, ansidx, mx = -1, mn = 10000000;

typedef struct {
	double x, y;
} P;

P ans[10000000];

inline long double f(double x, double y) {
	return (long double)sin(x)* exp((1 - cos(y))*(1 - cos(y)))
		+ cos(y) * exp((1 - sin(x))*(1 - sin(x)))
		+ (x - y) * (x - y);
}
inline double fpx(double x, double y) {
	return cos(x)* exp((1 - cos(y))*(1 - cos(y)))
		- 2.0 * cos(y) * cos(x) * (1 - sin(x)) * exp((1 - sin(x))*(1 - sin(x)))
		+ x * 2 - y * 2;
}
inline double fpy(double x, double y) {
	return sin(x)*2.0*exp((1 - cos(y))*(1 - cos(y))) * sin(y) * (1 - cos(y))
		- sin(y) * exp((1 - sin(x))*(1 - sin(x)))
		+ y * 2 - x * 2;
}

void bisection_x(double x, double yl, double yr) {
	if (f(x, yl) * f(x, yr) >= 0) return;
	double mid = (yl + yr) / 2.0;
	while (yr - yl > eps) {
		mid = (yl + yr) / 2.0;
		if (fabs(f(x, mid)) < eps) {
			cnt++;
			ans[ansidx].x = x, ans[ansidx++].y = mid;
			return;
		}
		else if (f(x, mid) * f(x, yl) < 0) yr = mid;
		else if (f(x, mid) * f(x, yr) < 0) yl = mid;
		else return;
		ans[ansidx].x = x, ans[ansidx++].y = mid;
	}
}

void bisection_y(double y, double xl, double xr) {
	if (f(xl, y) * f(xr, y) >= 0) return;
	double mid = (xl + xr) / 2.0;
	while (xr - xl > eps) {
		mid = (xl + xr) / 2.0;
		if (fabs(f(mid, y)) < eps) {
			cnt++;
			ans[ansidx].x = mid, ans[ansidx++].y = y;
			return;
		}
		else if (f(mid, y) * f(xl, y) < 0) xr = mid;
		else if (f(mid, y) * f(xr, y) < 0) xl = mid;
		else return;
		ans[ansidx].x = mid, ans[ansidx++].y = y;
	}
}

void root_find() {
	double X, Y;
	double xl = -2.0 * PI(), xr = 2.0 * PI(),
		yl = -2.0 * PI(), yr = 2.0 * PI();
	int x = 1, xx = 1;
	for (X = xl; X <= xr; X += s) {
		for (Y = yl; Y <= yr; Y += s) {
			cnt = 1, ansidx = 0;
			bisection_x(X, Y, Y + s);
			if (ansidx == 10000000) return;
			bisection_y(Y, X, X + s);
			if (ansidx == 10000000) return;
			if (ansidx) {
				printf("iteration %d : \n", x++);
				for (int i = 0; i < ansidx; i++) {
					printf("%d. f(%.10lf, %.10lf) = %.15lf\n", i + 1, ans[i].x, ans[i].y, f(ans[i].x, ans[i].y));
				}
				puts("");
				mx = max(mx, ansidx + 1);
				mn = min(mn, ansidx + 1);
			}
		}
	}
}
int main() {
	freopen("output.txt", "w", stdout);
	root_find();
	puts("\n\n");
	printf("max iter : %d, min iter : %d\n", mx, mn);

	return 0;
}