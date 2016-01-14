# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int rows,i,j;
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
		for(j=0;j<rows;j++)
		{
			arr[i][j]=0;
		}
	}
	for(i=0;i<rows;i++)
	{
		for(j=0;j<=i;j++)
		{
			arr[i][j]=value;
			value++;
		}
	}
	for(i=0;i<rows;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	// your code goes here
	return 0;
}
