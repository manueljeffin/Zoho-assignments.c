#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int input,n,duplicate,duplicate1,flagship,i=3;
	int *list;
	printf("Enter the input : \n");
	scanf("%d",&input);
	list=(int*)malloc(1*sizeof(int));
	list[0]=2;
	n=0;
	while(1)
	{
		flagship=1;;
		if(list[n]>input)
		{
			printf("The next prime is %d",list[n]);
			break;
		}
		else
		{
			duplicate=n;
			duplicate1=duplicate+1;
			while(duplicate1--)
			{
				if(i%list[duplicate]==0)
				{
					flagship=0;
					break;
				}
				duplicate--;
			}
			if(flagship==1)
			{
				n++;
				list=(int*)realloc(list,((n+1)*sizeof(int)));
				list[n]=i;
				if(list[n]>input)
				{
					printf("The next prime is %d",list[n]);
					break;
				}
			}
			i+=2;
		}
	}
	
	// your code goes here
	return 0;
}
