#include <stdio.h>
#include <math.h>

// Use predefined constants
#define _USE_MATH_DEFINES

#define TOLERANCE 1e-8
#define DERIVATIVE_STEP 1e-8
#define MAX_ITERATION 10000

typedef double (*Function)(double, double);

#define DOMAIN_MAX 2 * M_PI
#define DOMAIN_MIN -2 * M_PI

double bird_function(double x, double y)
{
    return sin(x) * pow(M_E, pow(1 - cos(y), 2))
           + cos(y) * pow(M_E, pow(1 - sin(x), 2))
           + pow(x - y, 2);
}

double partial_x(Function target, double x, double y)
{
    double left = target(x - DERIVATIVE_STEP, y);
    double right = target(x + DERIVATIVE_STEP, y);
    
    double slope = (right - left) / (2 * DERIVATIVE_STEP);

    return slope;
}

double partial_y(Function target, double x, double y)
{
    double left = target(x, y - DERIVATIVE_STEP);
    double right = target(x, y + DERIVATIVE_STEP);
    
    double slope = (right - left) / (2 * DERIVATIVE_STEP);
    
    return slope;
}

void tee(FILE *f, const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vprintf(fmt, ap);
    va_end(ap);

    va_start(ap, fmt);
    vfprintf(f, fmt, ap);
    va_end(ap);
}

void search(Function target, double init_x, double init_y, FILE *output)
{
    double x = init_x, y = init_y;

    int trials = 0;
    while (trials < MAX_ITERATION) {

        double value = target(x, y);
        double df_dx = partial_x(target, x, y);
        double df_dy = partial_y(target, x, y);

        tee(
            output,
            "Trial #%d\tfunction(x: %lf, y: %lf) = %lf\n"
            "    df/dx = %lf\tdf/dy = %lf\n",
            trials, x, y, value, df_dx, df_dy
        );

        // If the value is within tolerance, abort
        if (TOLERANCE < value && value < TOLERANCE)
            break;
        
        // Okay let's construct new values
        //   slope = run / rise
        // Therefore slope * function_value seems reasonable?
        // But we need to go back so we subtract
        x -= value / df_dx;
        y -= value / df_dy;
        
        trials++;
    }
}

int main(void)
{
    FILE *output = fopen("output.txt", "w");

    double x, y;
    scanf("%lf%lf", &x, &y);

    search(bird_function, x, y, output);

    fclose(output);

    return 0;
}

