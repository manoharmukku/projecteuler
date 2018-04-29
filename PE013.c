/* Project Euler: Problem 13 Solution
 * Author : Manohar Mukku
 * Date : 28.11.2014
 * References : None
 * Answer : 5537376230*/

#include <stdio.h>

#define X 100  // Total number of numbers
#define Y 50   // Length of each number

int main(void)
{
	char a[X][Y];
	int i,j;
	int sum;
	int answer[Y+3];   // contains sum in reverse order
	int k;    // count of total number of digits in answer
	
	//  Save data in file "test.txt" as it is from question
	
	FILE* fin = fopen("test.txt","r");
	for (i=0;i<X;i++)
	{
		
			fscanf(fin, "%s",a[i]);
		
	}
	fclose(fin);
	
	sum = 0;
	k = -1;
	for (j=Y-1;j>=0;j--)
	{
		for (i=0;i<X;i++)
		{
			sum = sum + (a[i][j]-48);
		}
		
		answer[++k] = sum%10; // last digit of sum
		sum = sum/10; //carry
	}
	
	while (sum != 0)
	{
		answer[++k] = sum%10;
		sum = sum/10;
	}
	
	printf("The first 10 digits of sum is ");
	for (i=k;i>k-10;i--)
	{
		printf("%d",answer[i]);
	}
	
	return 0;
}
