#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double min(double x, double y)
{
    if(x > y) return y;
    return x;
}

double max(double x, double y)
{
    if(x < y) return y;
    return x;
}

int main()
{
    int counter;
    double minimum, maximum;
    FILE * fpointer = fopen("file.txt", "r");
    fscanf(fpointer, "%d %lf %lf", &counter, &minimum, &maximum);
    double x[counter], xlow, xhigh;
    for(int i = 0; i < counter; i++)
    {
        fscanf(fpointer, "%lf", &x[i]);
        if(i == 0)
        {
            xlow = x[i];
            xhigh = x[i];
        }
        xlow = min(xlow, x[i]);
        xhigh = max(xhigh, x[i]);
    }
    double normx[counter];
    for(int i = 0; i < counter; i++){
        normx[i] = minimum + (x[i] - xlow) * (maximum - minimum) / (xhigh - xlow);
    }
    printf("Original values         Normalized values\n");
    for(int i = 0; i < counter; i++)
    {
        printf("%.1f\t\t\t%.1f\n", x[i], normx[i]);
    }
    return 0;
}
