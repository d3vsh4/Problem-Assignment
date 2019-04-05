/* Write a program to print sum of the following series:

      1 3 5 7 9 11......

      up to n numbers taking only an integer n as input. */

#include <stdio.h>

int sum_of_series()
{
	int i,n;
	int sum=0; //initial value of sum
	scanf("%d", &n);
	for(i=1; i<=2*n; i+=2) 
	{
		sum=sum+i;
	}
return sum;
}
void main() 
{
int sum= sum_of_series();
printf("Sum of Given series is %d",sum);
}
