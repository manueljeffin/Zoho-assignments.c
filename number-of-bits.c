# Zoho-assignments.c
#include <stdio.h>
int main(void) {
	int number,n=2,count=1;
	printf("enter the decimal number: \n");
	scanf("%d",&number);
	while(number>=n)
	{
		count=count+1;
		n=n*2;
	}
	printf("the number of bits needed is : %d\n",count);
	// your code goes here
	return 0;
}
