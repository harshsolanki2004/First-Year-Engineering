#include<stdio.h>

double body_mass_index (double W, double H)
{
	double BMI;

	BMI = W/(H*H);
	
	return (BMI);
}

int main (void)
{
	double weight;
	double height;
	double bmi;
	
	
	printf("Enter Weight in kilograms\n");
	scanf("%lf", &weight);
	
	printf("Enter height in meters\n");
	scanf("%lf", &height);
	
	bmi = body_mass_index (weight, height);
	
	if (bmi < 18.5)
	{
		printf("Your BMI value is %lf, which classifies you as Underweight", bmi);
	}
	else if (bmi >= 18.5 && bmi < 25)
	{
		printf("Your BMI value is %lf, which classifies you as Normal", bmi);
	}
	else if (bmi >= 25 && bmi < 30)
	{
		printf("Your BMI value is %lf, which classifies you as Overweight", bmi);
	}
	else if (bmi >= 30)
	{
		printf("Your BMI value is %lf, which classifies you as Obese", bmi);
	}
}
