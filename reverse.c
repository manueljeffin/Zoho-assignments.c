# Zoho-assignments.c
#include <stdio.h>
int main(void) {
	int num,digitcounter=0,reverse=0;
	printf("enter the number: \n");
	scanf("%d",&num);
	while(num>0)
	{
		reverse=reverse*10+num%10;
		num=num/10;
		digitcounter++;
	}
	printf("%0*d",digitcounter,reverse);
	// your code goes here
	return 0;
}
