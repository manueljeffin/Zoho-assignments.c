# Zoho-assignments.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
	int i,stringlength=0,valueindex,duplicatevalueindex,maxstringlength=0,startingindex,endingindex;
	int index;
	char str[100];
	printf("Enter the string :\n");
	scanf("%s",str);
	int length=strlen(str);
	printf("The string length is %d\n",length);
	valueindex=(int)(str[0]-'a');
	index=0;
	int flagship=1;
	for(i=1;i<length;i++)
	{
		if(i==1)
		{
			stringlength++;
		}
		duplicatevalueindex=(int)(str[i]-'a');
		if(duplicatevalueindex==valueindex)
		{
			flagship=0;
			if(stringlength>maxstringlength)
			{
				maxstringlength=stringlength;
				startingindex=index;
				endingindex=i-1;
			}
			stringlength=1;
			index=i;
			valueindex=(int)(str[i]-'a');
		}
		else
		{
			stringlength++;
		}
	}
	if(flagship==0)
	{
		if(maxstringlength>stringlength)
		{
			printf("The max substring length is %d\n",maxstringlength);
			for(i=startingindex;i<=endingindex;i++)
			{
				printf("%c",str[i]);
			}
			printf("\n");
		}
		else
		{
			printf("The max substring length is %d\n",stringlength);
			endingindex=length-1;
			for(i=index;i<=endingindex;i++)
			{
				printf("%c",str[i]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("The max substring length is %d\n",stringlength);
		for(i=0;i<length;i++)
		{
			printf("%c",str[i]);
		}
		printf("\n");
	}
	// your code goes here
	return 0;
}
