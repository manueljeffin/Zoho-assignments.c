# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void) {
	int order,i,j,k,value,count,currentrow,currentcolumn,nextrow,nextcolumn;
	printf("enter the number order of matrix(odd order) :\n");
	scanf("%d",&order);
	int *a[order];
	for(i=0;i<order;i++)
	{
		a[i]=(int*)malloc(order*sizeof(int));
	}
	for(i=0;i<order;i++)
	{
		for(j=0;j<order;j++)
		{
			a[i][j]=0;
		}
	}
    if(order==1)
    {
        printf("1");
        return 0;
    }
	value=order/2;
	count=order*order;
	a[0][value]=1;
	currentrow=0;
	currentcolumn=value;
	for(k=2;k<=count;k++)
	{
		if(currentrow==0)
		{
			nextrow=order-1;
		}
		else
		{
			nextrow=currentrow-1;
		}
		if(currentcolumn==(order-1))
		{
			nextcolumn=0;
		}
		else
		{
			nextcolumn=currentcolumn+1;
		}
		if(a[nextrow][nextcolumn]==0)
		{
			a[nextrow][nextcolumn]=k;
		}
		else
		{
			nextrow=currentrow+1;
			nextcolumn=currentcolumn;
			a[nextrow][nextcolumn]=k;
		}
		currentrow=nextrow;
		currentcolumn=nextcolumn;
	}
	printf("the magic square is :\n");
	for(i=0;i<order;i++)
	{
		for(j=0;j<order;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	
	// your code goes here
	return 0;
}
