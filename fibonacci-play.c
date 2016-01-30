# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int element,n,length,i,duplicateelement;
	int *fibo;
	printf("Enter the number: \n");
	scanf("%d",&element);
	duplicateelement=element;
	fibo=(int*)malloc(2*sizeof(int));
	fibo[0]=1;
	fibo[1]=1;
	n=1;
	while(1)
	{
		if(fibo[n]>duplicateelement)
		{
			break;
			printf("%d ",fibo[n-1]);
			duplicateelement=element-fibo[n-1];
			length=length-2;
		}
		else if(fibo[n]==duplicateelement)
		{
			printf("The given element %d is itself present in fibonacci series\n",element);
			return 0;
		}
		else
		{
			n++;
			length=n+1;
			fibo=(int*)realloc(fibo,(length*sizeof(int)));
			fibo[n]=fibo[n-1]+fibo[n-2];
		}
	}
	for(i=1;i<length;i++)
	{
		if(fibo[i]==duplicateelement)
		{
			printf("%d -These are the fibonacci elements present in the given element %d\n",fibo[i],element);
			break;
		}
		else if(fibo[i]>duplicateelement)
		{
			printf("%d ",fibo[i-1]);
			duplicateelement=duplicateelement-fibo[i-1];
			length=length-2;
			i=0;
		}
		
	}
	
	// your code goes here
	return 0;
}
