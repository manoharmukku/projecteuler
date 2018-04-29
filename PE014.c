/* Project Euler: Problem 14 Solution
 * Author : Manohar Mukku
 * Date : 28.11.2014
 * References : None
 * Answer : 837799*/

#include <stdio.h>

#define N 1000000    // 1 million

unsigned long countLength(unsigned long i)
{
    unsigned long count=1;
    while (i != 1)
    {
    	if (i%2 == 0)
    	{
    		i = i/2;
    		count++;
    	}
    	else
    	{
    		i = 3*i + 1;
    		count++;
    	}
    }
    
    return count+1;
}

int main(void)
{
	unsigned long i,n;
	unsigned long max = 0;
	unsigned long length;
	
	for (i=N;i>=2;i--)
	{
	    length = countLength(i);
	    if (length > max)
	    {
	    	max = length;
	    	n = i;
	    }
	}
	
	printf("Starting number %lu produces longest chain with length %lu",n,max);
	
	return 0;
}
