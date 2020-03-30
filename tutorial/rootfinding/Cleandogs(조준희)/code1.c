#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#define MAXD 2*M_PI
#define MIND (-2)*M_PI
#define MAXSPLIT 100000
#include <math.h>

double error = 0.1e-12;
double min = -106.764537, minx = 4.70104, miny = 3.15294;

void searchx(double, double, double);
void searchy(double, double, double);
double function(double, double);

int main(void) {
	double initx, inity, space = (MAXD - MIND) / MAXSPLIT;
	double x, y;
	int i, j;
	scanf("%lf%lf", &initx, &inity);
	for (i = 0; i < MAXSPLIT; i++) {
		for (j = 0; j < MAXSPLIT; j++) {
			if (MIND + j * space<inity &&
				MIND + (j + 1) * space>inity) break;
		}
		if (MIND + i * space<initx && MIND + (i + 1) * space > initx) break;
	}
	x = MIND + i * space, y = MIND + j * space;
	while (x <= MAXD) {
		while (y <= MAXD) {
			searchy(x, y, y + space);
			searchx(y, x, x + space);
			y += space;
		}
		x += space;
	}
	x = MIND + i * space, y = MIND + j * space;
	while (x >= MIND) {
		while (y <= MAXD) {
			searchy(x, y, y + space);
			searchx(y, x, x + space);
			y += space;
		}
		x -= space;
	}
	x = MIND + i * space, y = MIND + j * space;
	while (x <= MAXD) {
		while (y >= MIND) {
			searchy(x, y, y + space);
			searchx(y, x, x + space);
			y -= space;
		}
		x += space;
	}
	x = MIND + i * space, y = MIND + j * space;
	while (x >= MIND) {
		while (y >= MIND) {
			searchy(x, y, y + space);
			searchx(y, x, x + space);
			y -= space;
		}
		x -= space;
	}
	printf("\n%.12f %.12f %.12f\n", minx,miny,min);
	return 0;
}


void searchx(double yconst, double xstart, double xend) {
	double xmid;
	if (function(xstart, yconst) * function(xend, yconst) >= 0) return;
	while (xend - xstart > error) {
		xmid = (xstart + xend) / 2;
		if (fabs(function(xmid, yconst)) < fabs(min)) { 
			min = function(xmid, yconst); 
			minx = xmid;
			miny = yconst;
		}
		printf("%.12f %.12f %.12f\n", xmid, yconst, function(xmid, yconst));
		if (function(xmid, yconst) * function(xend, yconst) == 0) break;
		else if (function(xstart, yconst) * function(xmid, yconst) < 0) xend = xmid;
		else if (function(xmid, yconst) * function(xend, yconst) < 0) xstart = xmid;
		else return;
	}
}
void searchy(double xconst, double ystart, double yend) {
	double ymid;
	if (function(xconst, ystart) * function(xconst, yend) >= 0) return;
	while (yend - ystart > error) {
		ymid = (ystart + yend) / 2;
		if (fabs(function(ymid, xconst)) < fabs(min)) { 
			min = function(ymid, xconst); 
			minx = xconst;
			miny = ymid;
		}
		printf("%.12f %.12f %.12f\n", xconst, ymid, function(xconst, ymid));
		if (function(xconst, ymid) * function(xconst, yend) == 0) break;
		else if (function(xconst, ystart) * function(xconst, ymid) < 0) yend = ymid;
		else if (function(xconst, ymid) * function(xconst, yend) < 0) ystart = ymid;
		else return;
	}
}
double function(double x, double y) {
	double value;
	return value = sin(x) * exp(pow(1 - cos(y), 2)) + cos(y) * exp(pow(1 - sin(x), 2)) + pow(x - y, 2);
}
