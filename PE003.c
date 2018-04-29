/* Author : Manohar Mukku
 * Date : 27.11.2014
 * References : Wikipedia - Primality test 
 * Answer : 6857*/

#include <stdio.h>
#include <stdbool.h>

#define N 600851475143

bool isPrime(unsigned long n)
{
	unsigned short i;
	if (n<=3)
	    return n>1;
	else if (n%2==0 || n%3==0)
	    return false;
	else
	{
		for (i=5;i*i<=n;i+=6)
		    if (n%i==0 || n%(i+2)==0)
		        return false;
		return true;
	}
}

int main(void)
{
    unsigned long i;
    for (i=N;i>=2;i-=2)
    {
    	if (N%i==0 && isPrime(i))
    	{
    		printf("\nLargest Prime Factor of %llu is %lu",N,i);
    		break;
    	}
    }
		
	return 0;
}
