#include <stdio.h>
#include <math.h>


double spsound (double t)
{
	double a, in_root, fahrenheit, kmh;
	
	fahrenheit = (1.8*t)+32;
	in_root = ((5*fahrenheit)+297)/247;
	a = 1086*sqrt(in_root);
	
	kmh = a*(1.09728);
	return (kmh);
}

int main(void)
{
	double temp, speed;
	
	printf("Enter the temperature in celsius \n");
	scanf("%lf", &temp);
	
	speed = spsound(temp);
	
	printf("the speed of sound in %lf degrees celsius is %lf kilometers per hour", temp, speed);
	
	return(0);
}
