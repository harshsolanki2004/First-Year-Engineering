#include <stdio.h>
int main(void)
{
    int i, shifts, hours, total; 
    double employee_num, wage, total_pay;
    FILE *text; /* opens text file with the employees' pay information*/
    text = fopen ("L4_data.txt", "r"); /* reads the file*/
    printf("Employee Number \t\tHours Worked\t\tTotal Pay \n"); //titles with indents to make output look like a table
    printf("---------------\t\t\t------------\t\t----------\n");
    while (fscanf (text, "%lf %d %lf", &employee_num, &shifts, &wage) == 3) // while loop runs until there are no more employee numbers or wages to read//
    {
        total = 0;
        for (i=1; i<=shifts; ++i) // for loop inside the while loop calculates the total pay based on the wages and the employees' hours
        {
            fscanf(text, "%d", &hours);
            total = total + hours;
        }
        if (total > 25){ // if statements based on the categories the employees fall into 
            wage = wage * 1.1;
        }
        else if (total > 15){
            wage = wage * 1.05;
        }
        total_pay = wage * total;
        printf("%.0lf \t\t\t\t%d\t\t\t$%.2lf \n", employee_num, total, total_pay);
    }
    fclose(text);
    return 0;
}
