/* Project Euler: Problem 10 Solution
 * Author : Manohar Mukku
 * Date : 27.11.2014
 * References : Wikipedia - Primality test
 * Answer : 142913828922*/

#include <stdio.h>
#include <stdbool.h>

#define N 2000000     //2 million

bool isPrime(unsigned long n)
{
	unsigned short i;
	if (n<=3) return n>1;
	else if (n%2==0 || n%3==0) return false;
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
	unsigned long long sum=0;
	unsigned long i;
	
	for (i=N-1;i>2;i-=2)
	{
		if (isPrime(i))
		    sum+=i;
	}
	
	sum+=2; // For i=2
	
	printf("Sum of first %lu primes is %llu",N,sum);
	return 0;
}
