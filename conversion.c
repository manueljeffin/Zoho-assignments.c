# Zoho-assignments.c
#include <stdio.h>
#include <string.h>
int main(void) {
	int inputnumber,base,copy,temp,i=0,temp1,j,flag[100];
	char *solution[100];
	char buf[100],a='[',b=']';
	printf("Enter the input number\n");
	scanf("%d",&inputnumber);
	printf("Enter the base to be converted into :\n");
	scanf("%d",&base);
	copy=inputnumber;
	while(copy>0)
	{
		temp=copy%base;
		if(temp<=9)
		{
			solution[i]=(char)(temp+'0');
			flag[i]=0;
		}
		else if((temp+65)<=90)
		{
			solution[i]=(char)('A'+temp-10);
			flag[i]=0;
		}
		else
		{
			sprintf(buf,"%c%d%c",a,temp,b);
			solution[i]=buf;
			flag[i]=1;
		}
		i++;
		copy=copy/base;
		
	}
	for(j=i-1;j>=0;j--)
	{
		if(flag[j]==1)
		{
			printf("%s",solution[j]);
		}
		else
		{
			printf("%c",solution[j]);
		}
	}
	
	// your code goes here
	return 0;
}
