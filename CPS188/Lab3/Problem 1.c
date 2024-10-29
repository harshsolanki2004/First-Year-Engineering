#include<stdio.h>
#include<math.h>
#define e 2.718281828 

double males_Low (double age, double rhr)
{
	double exp = 0.033*(age-104.3);
	double MHR;
	double THR;
	
	MHR = 203.7/(1+pow(e, exp));
	
	THR = ((MHR-rhr)*0.55)+rhr;
	return (THR);
}

double males_Medium (double age, double rhr)
{
	double exp = 0.033*(age-104.3);
	double MHR;
	double THR;
	
	MHR = 203.7/(1+pow(e, exp));
	
	THR = ((MHR-rhr)*0.65)+rhr;
	return (THR);
}

double males_High (double age, double rhr)
{
	double exp = 0.033*(age-104.3);
	double MHR;
	double THR;
	
	MHR = 203.7/(1+pow(e, exp));
	
	THR = ((MHR-rhr)*0.8)+rhr;
	return (THR);
}

double females_Low (double age, double rhr)
{
	double exp = 0.0453*(age-107.5);
	double MHR;
	double THR;
	
	MHR = 190.2/(1+pow(e, exp));
	
	THR = ((MHR-rhr)*0.55)+rhr;
	return (THR);
}

double females_Medium (double age, double rhr)
{
	double exp = 0.0453*(age-107.5);
	double MHR;
	double THR;
	
	MHR = 190.2/(1+pow(e, exp));
	
	THR = ((MHR-rhr)*0.65)+rhr;
	return (THR);
}

double females_High (double age, double rhr)
{
	double exp = 0.0453*(age-107.5);
	double MHR;
	double THR;
	
	MHR = 190.2/(1+pow(e, exp));
	
	THR = ((MHR-rhr)*0.8)+rhr;
	return (THR);
}

int main (void)
{
	int AGE;
	char INTEN;
	char GENDER;
	double RHR;
	int training_rate;
	
	printf("Enter Age\n");
	scanf("%d", &AGE);
	
	printf("Enter M if male or F if female\n");
	scanf(" %c", &GENDER);
	
	printf("Enter fitness level (L for low, M for medium, H for high)\n");
	scanf(" %c", &INTEN);
	
	printf("Enter resting heart rate\n");
	scanf("%lf", &RHR);
	
	if (GENDER == 'M' && INTEN == 'L')
	{	
		training_rate = males_Low(AGE, RHR);
		printf("The training heart rate is %d", training_rate);
	} 
	else if (GENDER == 'M' && INTEN == 'M')
	{
		training_rate = males_Medium(AGE, RHR);
		printf("The training heart rate is %d", training_rate);
	}
	else if (GENDER == 'M' && INTEN == 'H') 
	{
		training_rate = males_High(AGE, RHR);
		printf("The training heart rate is %d", training_rate);
	}
	else if (GENDER == 'F' && INTEN == 'L')
	{
		training_rate = females_Low(AGE, RHR);
		printf("The training heart rate is %d", training_rate);
	}
	else if (GENDER == 'F' && INTEN == 'M') 
	{
		training_rate = females_Medium(AGE, RHR);
		printf("The training heart rate is %d", training_rate);
	}
	else if (GENDER == 'F' && INTEN == 'H')
	{
		training_rate = females_High(AGE, RHR);
		printf("The training heart rate is %d", training_rate);
	}
	else
	{
	printf("Invalid entry, please restart application and enter letters in capitals");
	}
		
}
