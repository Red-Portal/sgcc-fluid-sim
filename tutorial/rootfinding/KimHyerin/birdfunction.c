#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/*
function scores = birdfcn(x)
    
    n = size(x, 2);
    assert(n == 2, 'Bird function is only defined on a 2D space.')
    X = x(:, 1);
    Y = x(:, 2);
    
    scores = sin(X) .* exp((1 - cos(Y)).^2) + ... 
        cos(Y) .* exp((1 - sin(X)) .^ 2) + ...
        (X - Y) .^ 2;
end
*/

double birdfuntion(double x, double y)
{
    double score;
    score = sin(x)*exp(pow(1-cos(y),2)) + cos(y)*exp(pow(1-sin(x),2)) + pow(x-y, 2);

    return score;
}
double bird_derivative_x(double x, double y)
{
    double fx = cos(x)*exp(pow(1-cos(y),2)) + cos(y)*exp(pow(1-sin(x),2))*2*(1-sin(x))*(-cos(x)) + 2*(x-y);
    return fx;
}
double bird_derivative_y(double x, double y)
{
    double fy = cos(x)*exp(pow(1-cos(y),2))*2*(1-cos(y))*sin(y) - sin(y)*exp(pow(1-sin(x),2)) - 2*(x-y);
    return fy;
}
int main()
{
    double x, y;
    int cnt = 0;


    printf("x: ");
    scanf("%lf", &x);
    printf("y: ");
    scanf("%lf", &y);

    printf("<iteration %2d> x: %.11lf ,y: %.11lf ,error: %.11lf\n",++cnt, x, y, birdfuntion(x, y));


    while(1){
        if(cnt == 30)
            break;
    

        if(birdfuntion(x, y) < 0.00000000001 && birdfuntion(x, y) > -0.00000000001)
            break;
            
        double z = birdfuntion(x, y);

        double nx = x - z/bird_derivative_x(x, y);
        double ny = y - z/bird_derivative_y(x, y);
    


        printf("<iteration %2d> x: %.11lf ,y: %.11lf ,error: %.11lf\n",++cnt, nx, ny, birdfuntion(nx, ny));

        x = nx;
        y = ny;

    }


    return 0;
}