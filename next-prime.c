# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int input,n,duplicate,duplicate1,flagship,i=3;
	int *prime;
	printf("Enter the input : \n");
	scanf("%d",&input);
	prime=(int*)malloc(1*sizeof(int));
	prime[0]=2;
	n=0;
	while(1)
	{
		flagship=1;;
		if(prime[n]>input)
		{
			printf("The next prime is %d\n",prime[n]);
			break;
		}
		else
		{
			duplicate=n;
			duplicate1=duplicate+1;
			while(duplicate1--)
			{
				if(i%prime[duplicate]==0)
				{
					flagship=0;
					break;
				}
				duplicate--;
			}
			if(flagship==1)
			{
				n++;
				prime=(int*)realloc(prime,((n+1)*sizeof(int)));
				prime[n]=i;
				if(prime[n]>input)
				{
					printf("The next prime is %d",prime[n]);
					break;
				}
			}
			i+=2;
		}
	}
	
	// your code goes here
	return 0;
}
