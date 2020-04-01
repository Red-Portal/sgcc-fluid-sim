# sgcc-fluid-sim
SGCC Fluid Simulation Project 
## 1. Bird Function에서의 root finding

본 실습은 2변수 함수의 근 f(x,y)=0를 만족하는 순서쌍 (x,y)을 해결하는 과정을 작성하였다.

* method: Bisection Method
>   domain을 $$10^(-2)\times10^(-2)$$로 분해하여 각각의 격자에 대하여 bisection method를 적용하였다.
>   한 평면에 대하여 1) X값을 고정하고 Y값을 조정, 2) Y값을 고정하고 X값을 조정하여 2회의 bisection을 수행하였다.
```c
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
```
* 오차범위: $$10^(-10)$$
* min iteration : 19, max iteration : 55
