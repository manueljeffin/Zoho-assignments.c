# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>
int factorial(int num)
{
	int fact=1;
	int min=2;
	while(min<=num)
	{
		fact=fact*min;
		min++;
	}
	return fact;
}

int main(void) {
	int rows,i,j,number;
	int value=1;
	printf("enter the number of rows :\n");
	scanf("%d",&rows);
	int *arr[rows];
	for(i=0;i<rows;i++)
	{
		arr[i]=(int*)malloc(rows*sizeof(int));
	}
	for(i=0;i<rows;i++)
	{
		for(j=0;j<=i;j++)
		{
			number=(factorial(i)/(factorial(j)*factorial(i-j)));
			printf("%d ",number);
		}
		printf("\n");
	}
	// your code goes here
	return 0;
}
