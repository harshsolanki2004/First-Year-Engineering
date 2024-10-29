#include <stdio.h>

int main(void)
{
	int row,t; //define variables row for the row number, and t for the for loop's cycle counter
	for (row = 0; row<9; row++) //for loop that runs until the row number is less than 9, increments of 1
	{	
		int column_digit = 1, numerator = row, denominator = 1; //define variables
		for (t=0;t<=row;t++) //loop that calculates the number at each column in each row by using the nCr formula*/
		{
			printf(" %d", column_digit);
			column_digit=column_digit*numerator;
			column_digit=column_digit/denominator;
			numerator--;
			denominator++;
		}
		printf("\n");
	}
}
