/* Project Euler: Problem 18 Solution
 * Author: Manohar Mukku
 * Date: 28.05.2015
 * References: None
 * Answer: 1074
 */


#include <stdio.h>

#define N 15

int main (void)
{
	int trngl[N][N];
	int count[N][N];
	int i, j;
	
	FILE * in = fopen("triangle.txt","r");
	
	for (i = 0; i < N; i++){
		for (j = 0; j <= i; j++){
			fscanf (in, "%d", &trngl[i][j]);
		}
	}
	
	for (j = 0; j < N; j++){
		count[N-1][j] = trngl[N-1][j];
	}
	
	for (i = N-2; i >= 0; i--){
		for (j = 0; j <= i; j++){
			if (count[i+1][j] > count[i+1][j+1])
				count[i][j] = trngl[i][j] + count[i+1][j];
			else
				count[i][j] = trngl[i][j] + count[i+1][j+1];
		}
	}
	
	printf ("The maximum sum is %d\n", count[0][0]);
	
	return 0;
}
