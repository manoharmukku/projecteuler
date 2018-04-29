/* Project Euler: Problem 16 Solution
 * Author : Manohar Mukku
 * Date : 01.01.2015
 * References : None
 * Answer : 1366*/

#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 1000  // N = power of 2 => 2^N

int main(void)
{
	int answer[N] = {0};
	int i;
	int j;
	int product, carry, length;
	long sum;
	
	answer[0] = 2;
	length = 1;
	
	for (i = 2; i <= N; i++)
	{
		carry = 0;
		j = 0;
		
		while (j < length || carry != 0)
		{
			product = answer[j] * 2 + carry;
			answer[j] = product % 10;
			carry = product / 10;
			j++;
		}
		length = j;
	}
	
	sum = 0;
	for (i = 0; i < length; i++)
	    sum += answer[i];
	
	printf("The sum of the digits of 2^%d = %ld",N,sum);
	
	return 0;
}
