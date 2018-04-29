/* Project Euler: Problem 11 Solution
 * Author : Manohar Mukku
 * Date : 27.11.2014
 * References : Wikipedia - Primality test
 * Answer : 70600674*/

#include <stdio.h>
#define N 20

int main(void)
{
	int a[N][N];
	int i,j;
	long product;
	long max = -1;
	
	// Save 20x20 array in file test.txt
	// Read input from file and store in 2D array a
	FILE* fin = fopen("test.txt","r");
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			fscanf(fin, "%d",&a[i][j]);
		}
	}
	fclose(fin);
	
	product = 1;
	
	// Horizontal (left right) sums
	
	for (i=0;i<N;i++)
	{
		for (j=0;j<=N-4;j++)
		{
			product = product * (a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j+3]);
			if (product > max) max = product;
			product = 1;
		}
	}
	
	// Vertical (up down) sums
	for (j=0;j<N;j++)
	{
		for (i=0;i<=N-4;i++)
		{
			product = product * (a[i][j] * a[i+1][j] * a[i+2][j] * a[i+3][j]);
			if (product > max) max = product;
			product = 1;
		}
	}
	
	// Diagonal Sums
	for (i=0;i<=N-4;i++)
	{
		for (j=0;j<=N-4;j++)
		{
			product = product * (a[i][j] * a[i+1][j+1] * a[i+2][j+2] * a[i+3][j+3]);
			if (product > max) max = product;
			product = 1;
		}
	}
	
	for (i=N-1;i>=3;i--)
	{
		for (j=0;j<=N-4;j++)
		{
			product = product * (a[i][j] * a[i-1][j+1] * a[i-2][j+2] * a[i-3][j+3]);
			if (product > max) max = product;
			product = 1;
		}
	}
	
	printf("Greatest product of 4 adjacent numbers = %ld",max);
	
	return 0;
}
