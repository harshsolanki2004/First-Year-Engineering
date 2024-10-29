#include <stdio.h>

double moon (double car_speed, double *t1, double *t2)
{
	double perigee = 363104, apogee = 405696;
	
	*t1 = perigee/car_speed;
	*t2 = apogee/car_speed;
	
	return (apogee);		
}

double mars (double car_speed, double *t1, double *t2)
{
	double perigee = 54600000, apogee = 401000000;
	
	*t1 = perigee/car_speed;
	*t2 = apogee/car_speed;
	
	return (apogee);		
}

double venus (double car_speed, double *t1, double *t2)
{
	double perigee = 38000000, apogee = 261000000;
	
	*t1 = perigee/car_speed;
	*t2 = apogee/car_speed;
	
	return (apogee);		
}


int main ()
{
	int choice=0;
	double car_speed, t1, t2;

	
	while (choice != 4)
	{
		printf("Type 1 for Moon, 2 for Mars, 3 for Venus, and 4 to exit the program: \n");
		scanf("%d", &choice);
		
		if (choice == 1)
		{
			printf("Enter the speed of the car in km/h:\n");
			scanf("%lf", &car_speed);
			moon(car_speed, &t1, &t2);
			printf("The minimum time taken travelling to the moon at %.1lf km/h is %.2lf hours and the minimum is %.2lf hours.\n", car_speed,t1, t2);
		}
		else if (choice ==2)
		{
			printf("Enter the speed of the car in km/h:\n");
			scanf("%lf", &car_speed);
			mars(car_speed, &t1, &t2);
			printf("The minimum time taken travelling to Mars at %.1lf km/h is %.2lf hours and the minimum is %.2lf hours.\n", car_speed,t1, t2);
		}
		else if (choice ==3)
		{
			printf("Enter the speed of the car in km/h:\n");
			scanf("%lf", &car_speed);
			venus(car_speed, &t1, &t2);
			printf("The minimum time taken travelling to Venus at %.1lf km/h is %.2lf hours and the minimum is %.2lf hours.\n", car_speed,t1, t2);
		}
	}
}
