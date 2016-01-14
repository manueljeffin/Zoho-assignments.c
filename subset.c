# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
	int elements,i,count,j,temp;
	char ch;
	printf("Enter the number of elements: \n");;
	scanf("%d",&elements);
	count=pow(2,elements);
	int *a[count];
	for(i=0;i<count;i++)
	{
		a[i]=(int*)malloc(elements*sizeof(int));
	}
	for(i=0;i<count;i++)
	{
		for(j=0;j<elements;j++)
		{
			a[i][j]=0;
		}
	}
	for(i=0;i<count;i++)
	{
		temp=i;
		if(temp<2)
		{
			j=0;
			a[i][j]=temp;
		}
		else
		{
			j=0;
			while(temp>1)
			{
				a[i][j]=temp%2;
				j++;
				temp=temp/2;
			}
			a[i][j]=temp;
		}
	}
	printf("In numerical form :\n");
	for(i=0;i<count;i++)
	{
		for(j=0;j<elements;j++)
		{
			if(a[i][j]==1)
			{
				printf("%d ",j+1);
			}
		}
		printf("\n");
	}
	printf("In alphabetical form :\n");
	for(i=0;i<count;i++)
	{
		for(j=0;j<elements;j++)
		{
			if(a[i][j]==1)
			{
				ch='A'+j;
				printf("%c",ch);
			}
		}
        printf("\n");
	}
	
	// your code goes here
	return 0;
}
