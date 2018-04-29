/* Project Euler: Problem 15 Solution
 * Author : Manohar Mukku
 * Date : 01.01.2015
 * References : None
 * Answer : 137846528820*/

#include <stdio.h>

#define N 20  //Size of the matrix 20x20

int main(void)
{
	long long count[N+1][N+1];
	int i,j;
	
	// There is only one way for the first row and first column points
	for (i = 0; i <= N; i++)
	{
		count[0][i] = 1;
		count[i][0] = 1;
	}
	
	// The ways for any point is the sum of the ways of its left point and its top point
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
		    count[i][j] = count[i-1][j]/*Top point*/ + count[i][j-1]/*Left point*/;	
		}
	}
	
	printf("count[%d][%d] = %lld", N,N,count[N][N]);
	
	return 0;
}
