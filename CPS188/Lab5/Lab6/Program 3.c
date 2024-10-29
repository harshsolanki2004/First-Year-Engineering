#include <stdio.h>
#define STACK_EMPTY '0'
#define STACK_SIZE 20

void
push(char stack[],char item,int  *top,int  max_size)
{
     if (*top < max_size-1) 
     {
         ++(*top);
         stack[*top] = item;
     }
}

char pop (char stack[],int *top)
{
    char item;

    if (*top >= 0) 
    {
        item = stack[*top];
        --(*top);
    }
    else 
    {
         item = STACK_EMPTY;
    }

    return (item);
}

int main (void)
{
   char s [STACK_SIZE];
   int s_top = -1;

   /* complete the program here */
   
   push(s, 'a', &s_top, STACK_SIZE);
   push(s, 'b', &s_top, STACK_SIZE);
   push(s, 'c', &s_top, STACK_SIZE);

	for (int i=0; i<s_top+1; i++)
	{
		printf("%c", s[i]);
	}
	
	printf("\n\n");
	
	printf("pop removed: %c\n", pop(s, &s_top));
	
	for(int i=0; i<s_top+1; i++)
	{
		printf("%c", s[i]);
	}
   return (0);
}
