# Zoho-assignments.c
#include <stdio.h>
int main(void) {
	int a[100][100]={0},rows,columns,i,j,temp;
	printf("enter the number of rows and columns: \n");
	scanf("%d",&rows);
	scanf("%d",&columns);
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	if(rows>=columns)
	{
		
		for(i=0;i<rows;i++)
		{
			for(j=i;j<rows;j++)
			{
				temp=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=temp;
			}
		}
		
	}
	else
	{
		
		for(i=0;i<columns;i++)
		{
			for(j=i;j<columns;j++)
			{
				temp=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=temp;
			}
		}
	}
	for(i=0;i<columns;i++)
	{
		for(j=0;j<rows;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	// your code goes here
	return 0;
}
