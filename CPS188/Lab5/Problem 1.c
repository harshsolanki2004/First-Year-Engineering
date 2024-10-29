#include <stdio.h>

int main()
{
	int a, b, c, *num1, *num2, *num3;


	printf("Enter the first number: \n");
	scanf("%d", &a);
	printf("Enter the second number: \n");
	scanf("%d", &b);
	printf("Enter the third number: \n");
	scanf("%d", &c);
	
	num1=&a;
	num2=&b;
	num3=&c;	
	
	
	if (*num1>=*num2 && *num1>=*num3 && *num2>=*num3)
	{
		printf("The three numbers in order are: %d %d %d", *num1, *num2, *num3);
	}
	else if (*num1<=*num2 && *num1<=*num3 && *num2<=*num3)
	{
		printf("The three numbers in order are: %d %d %d", *num1, *num3, *num2);
	}
	else if (*num2<=*num1 && *num2<=*num3 && *num1<=*num3)
	{
		printf("The three numbers in order are: %d %d %d", *num2, *num1, *num3);
	}
	else if (*num2<=*num3 && *num2<=*num1 && *num3<=*num1)
	{
		printf("The three numbers in order are: %d %d %d", *num2, *num3, *num1);
	}
	else if (*num3<=*num1 && *num3<=*num2 && *num1<=*num2)
	{
		printf("The three numbers in order are: %d %d %d", *num3, *num1, *num2);
	}
	else
	{
		printf("The three numbers in order are: %d %d %d" , *num3, *num2, *num1);
	}
	return 0;
}
