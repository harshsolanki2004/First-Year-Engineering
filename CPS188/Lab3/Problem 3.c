#include <stdio.h>

double final_mark_35_40 (double n1, double n2, double n3, double n4, double n5, double n6, double n7, double n8, double n9, double midterm, double final)
{
	double final_grade;
	double sum;
	sum = n1+n2+n3+n4+n5+n6+n7+n8+n9;
	 final_grade = 0.25*((sum/9)*10)+0.35*(midterm)+0.4*(final);
	 return (final_grade);
}

double final_mark_25_50 (double n1, double n2, double n3, double n4, double n5, double n6, double n7, double n8, double n9, double midterm, double final)
{
	double final_grade;
	double sum;
	sum = n1+n2+n3+n4+n5+n6+n7+n8+n9;
	 final_grade = 0.25*((sum/9)*10)+0.25*(midterm)+0.5*(final);
	 return (final_grade);
}
		
		
int main (void)
{
	double q1;
	double q2;
	double q3;
	double q4;
	double q5;
	double q6;
	double q7;
	double q8;
	double q9;
	double q10;
	double midterm;
	double final;
	double result;
	
	printf("Enter quiz 1 mark\n");
	scanf("%lf", &q1);
	
	printf("Enter quiz 2 mark\n");
	scanf("%lf", &q2);
	
	printf("Enter quiz 3 mark\n");
	scanf("%lf", &q3);
	
	printf("Enter quiz 4 mark\n");
	scanf("%lf", &q4);
	
	printf("Enter quiz 5 mark\n");
	scanf("%lf", &q5);
	
	printf("Enter quiz 6 mark\n");
	scanf("%lf", &q6);
	
	printf("Enter quiz 7 mark\n");
	scanf("%lf", &q7);
	
	printf("Enter quiz 8 mark\n");
	scanf("%lf", &q8);
	
	printf("Enter quiz 9 mark\n");
	scanf("%lf", &q9);
	
	printf("Enter quiz 10 mark\n");
	scanf("%lf", &q10);
	
	printf("Enter midterm exam mark\n");
	scanf("%lf", &midterm);
	
	printf("Enter final exam mark\n");
	scanf("%lf", &final);
	
	
	if (q1 < q2 && q1 < q3 && q1 < q4 && q1 < q5 && q1 < q6 && q1 < q7 && q1 < q8 && q1 < q9 && q1 < q10 && midterm >= final) //exclude quiz 1
	{
		result = final_mark_35_40 (q2, q3, q4, q5, q6, q7, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q2 < q1 && q2 < q3 && q2 < q4 && q2 < q5 && q2 < q6 && q2 < q7 && q2 < q8 && q2 < q9 && q2 < q10 && midterm >= final) //exclude quiz 2
	{
		result = final_mark_35_40 (q1, q3, q4, q5, q6, q7, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q3 < q1 && q3 < q2 && q3 < q4 && q3 < q5 && q3 < q6 && q3 < q7 && q3 < q8 && q3 < q9 && q3 < q10 && midterm >= final) //exclude quiz 3
	{
		result = final_mark_35_40 (q1, q2, q4, q5, q6, q7, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q4 < q1 && q4 < q2 && q4 < q3 && q4 < q5 && q4 < q6 && q4 < q7 && q4 < q8 && q4 < q9 && q4 < q10 && midterm >= final) //exclude quiz 4
	{
		result = final_mark_35_40 (q1, q2, q3, q5, q6, q7, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q5 < q1 && q5 < q2 && q5 < q3 && q5 < q4 && q5 < q6 && q5 < q7 && q5 < q8 && q5 < q9 && q5 < q10 && midterm >= final)//exclude quiz 5
	{
		result = final_mark_35_40 (q1, q2, q3, q4, q6, q7, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q6 < q1 && q6 < q2 && q6 < q3 && q6 < q4 && q6 < q5 && q6 < q7 && q6 < q8 && q6 < q9 && q6 < q10 && midterm >= final)// exclude quiz 6
	{
		result = final_mark_35_40 (q1, q2, q3, q4, q5, q7, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q7 < q1 && q7 < q2 && q7 < q3 && q7 < q4 && q7 < q5 && q7 < q6 && q7 < q8 && q7 < q9 && q7 < q10 && midterm >= final)// exclude quiz 7
	{
		result = final_mark_35_40 (q1, q2, q3, q4, q5, q6, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q8 < q1 && q8 < q2 && q8 < q3 && q8 < q4 && q8 < q5 && q8 < q6 && q8 < q7 && q8 < q9 && q8 < q10 && midterm >= final)// exclude quiz 8
	{
		result = final_mark_35_40 (q1, q2, q3, q4, q5, q6, q7, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q9 < q1 && q9 < q2 && q9 < q3 && q9 < q4 && q9 < q5 && q9 < q6 && q9 < q7 && q9 < q8 && q9 < q10 && midterm >= final)// exclude quiz 9
	{
		result = final_mark_35_40 (q1, q2, q3, q4, q5, q6, q7, q8, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q10 < q1 && q10 < q2 && q10 < q3 && q10 < q4 && q10 < q5 && q10 < q6 && q10 < q7 && q10 < q8 && q10 < q9 && midterm >= final)// exclude quiz 10
	{
		result = final_mark_35_40 (q1, q2, q3, q4, q5, q6, q7, q8, q9, midterm, final);
		printf("The final grade is %lf", result);
	}
	
	
	
	
	else if (q1 < q2 && q1 < q3 && q1 < q4 && q1 < q5 && q1 < q6 && q1 < q7 && q1 < q8 && q1 < q9 && q1 < q10 && midterm < final) //exclude quiz 1
	{
		result = final_mark_25_50 (q2, q3, q4, q5, q6, q7, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q2 < q1 && q2 < q3 && q2 < q4 && q2 < q5 && q2 < q6 && q2 < q7 && q2 < q8 && q2 < q9 && q2 < q10 && midterm < final) //exclude quiz 2
	{
		result = final_mark_25_50 (q1, q3, q4, q5, q6, q7, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q3 < q1 && q3 < q2 && q3 < q4 && q3 < q5 && q3 < q6 && q3 < q7 && q3 < q8 && q3 < q9 && q3 < q10 && midterm < final) //exclude quiz 3
	{
		result = final_mark_25_50 (q1, q2, q4, q5, q6, q7, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q4 < q1 && q4 < q2 && q4 < q3 && q4 < q5 && q4 < q6 && q4 < q7 && q4 < q8 && q4 < q9 && q4 < q10 && midterm < final) //exclude quiz 4
	{
		result = final_mark_25_50 (q1, q2, q3, q5, q6, q7, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q5 < q1 && q5 < q2 && q5 < q3 && q5 < q4 && q5 < q6 && q5 < q7 && q5 < q8 && q5 < q9 && q5 < q10 && midterm < final)//exclude quiz 5
	{
		result = final_mark_25_50 (q1, q2, q3, q4, q6, q7, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q6 < q1 && q6 < q2 && q6 < q3 && q6 < q4 && q6 < q5 && q6 < q7 && q6 < q8 && q6 < q9 && q6 < q10 && midterm < final)// exclude quiz 6
	{
		result = final_mark_25_50 (q1, q2, q3, q4, q5, q7, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q7 < q1 && q7 < q2 && q7 < q3 && q7 < q4 && q7 < q5 && q7 < q6 && q7 < q8 && q7 < q9 && q7 < q10 && midterm < final)// exclude quiz 7
	{
		result = final_mark_25_50 (q1, q2, q3, q4, q5, q6, q8, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q8 < q1 && q8 < q2 && q8 < q3 && q8 < q4 && q8 < q5 && q8 < q6 && q8 < q7 && q8 < q9 && q8 < q10 && midterm < final)// exclude quiz 8
	{
		result = final_mark_25_50 (q1, q2, q3, q4, q5, q6, q7, q9, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q9 < q1 && q9 < q2 && q9 < q3 && q9 < q4 && q9 < q5 && q9 < q6 && q9 < q7 && q9 < q8 && q9 < q10 && midterm < final)// exclude quiz 9
	{
		result = final_mark_25_50 (q1, q2, q3, q4, q5, q6, q7, q8, q10, midterm, final);
		printf("The final grade is %lf", result);
	}
	else if (q10 < q1 && q10 < q2 && q10 < q3 && q10 < q4 && q10 < q5 && q10 < q6 && q10 < q7 && q10 < q8 && q10 < q9 && midterm < final)// exclude quiz 10
	{
		result = final_mark_25_50 (q1, q2, q3, q4, q5, q6, q7, q8, q9, midterm, final);
		printf("The final grade is %lf", result);
	}
}
