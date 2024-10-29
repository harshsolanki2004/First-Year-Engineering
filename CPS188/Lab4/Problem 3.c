#include <stdio.h>


double pressure (double temp2)
{
   double pressure2, temp1, pressure1;
   temp1 = 300;
   pressure1 = 50;
   pressure2 = (pressure1*temp2) / temp1;
   return (pressure2);
}


int main(void)
{
   double maxtemp, k, i;
   maxtemp = (300*500)/50; /*calculates the macimum temperature the cylinder can hold*/
   printf("The tank can handle a temperatue of %.2lf Kelvin before exploding. \n", maxtemp);
  
   printf("Temperature (K)\t\t\tPressure (atm) \n");
   printf("—--------------\t\t\t-------------- ");
  
   for (i=273.5; i<maxtemp; i=i+100) /*Loop calculates the temperature from 273.15 to maxtemp*/
   {
       k = pressure(i);
       printf("\n%.2lf ", i);
       printf("  \t\t\t%.2lf ", k);
   }
  
   printf("\n%.2lf ", i); /*displays final temperature and pressure*/
   printf("   \t\t\t%.2lf ", pressure(i));
  
   printf("\nKABOOM!");
  
  
   return 0;
}
