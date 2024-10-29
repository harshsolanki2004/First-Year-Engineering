#include <stdio.h>
#define ARRAY_SIZE 8

int get_min_range (int list[], int first, int last)
{
   int lowest = list[first];
   for (int i = first; i<=last; i++)
   {
	   if (list [i] < lowest)
	   {
		   lowest = list[i];
	   }
   }
	for (int x = first; x<last; x++)
	{
		if (list[x] == lowest)
		{
			return x;
		}
	}
	return 0;
}

void
select_sort(int list[], int n)    
{
     int fill, temp,index_of_min;

     for (fill = 0; fill < n-1; ++fill) 
     {
          index_of_min = get_min_range (list, fill, n-1);
          if (fill != index_of_min) 
          {
                temp = list[index_of_min];
                list[index_of_min] = list[fill];
                list[fill] = temp;
          }
     }
}

int 
main (void) 
{
    int array[] = {67, 98, 23, 11, 47, 13, 94, 58};
    int i;
    
    select_sort (array, ARRAY_SIZE);
    
    for (i=0; i < 8; ++i)
    {
        printf ("%d ", array[i]);
    }
    return (0);
}
