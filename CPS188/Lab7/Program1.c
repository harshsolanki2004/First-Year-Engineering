#include <stdio.h>
#include <string.h>


void clean (char before[], char after[])
{
    int l=0, k=0, length;
    
    length=strlen(before);
    
    for(l=0; l <= length; ++l) 
    {
        if(before[l]>=65 && before[l]<=90)
        {
            after[k] = before[k] + 32;
            ++k;
        }
        else if(before[l]>=97 && before[l]<= 122)
        {
            after[k] = before[l];
            ++k;
        }
    }
}

void reverse (char before[], char after[])
{
    static int k=0, length;
    length = strlen(before);
    
    if(k<=length/2)
    {
        after[k] = before[length-k-1];
        after[length-k-1] = before[k];
        ++k;
        reverse(before, after);
    }
}

int 
main(void)
{
    char h[200], u[200], p[200];
    int i=0, length;
    
    printf("Enter a string: ");
    fgets(h, 200, stdin);
    
    clean (h, u);
    reverse (u, p);
    
    length = strlen(u);
    
    while(u[i]==p[i] && i<length)
    {
        ++i;
    }
    
    printf("\nThe string you entered is: \n%sThe cleaned string in reverse is: \n%s", h, p);
    
    if(i==length)
    {
        printf("\n\nThis string is a palindrome. ");
    }
    else
    {
        printf("\n\nThis string is not a palindrome. ");
    }
    
    return 0;
}
