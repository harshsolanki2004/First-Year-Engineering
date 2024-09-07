/* Harsh Solanki CPS188-162*/

# include <stdio.h>
# include <math.h>

int main (void)
{
double a, b, c;

printf("Enter the a value \n");
scanf("%lf", &a);
printf("Enter the b value \n");
scanf("%lf", &b);

c = sqrt(a*a+b*b);

printf("The Hypotenuse is %lf", c);
}
