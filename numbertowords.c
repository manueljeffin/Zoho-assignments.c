# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *ones[]={"one","two","three","four","five","six","seven","eight","nine"};
char *tens[]={"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
char *teens[]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char *hundreds[]={"one hunderd","two hundred","three hundred","four hundred","five hundred","six hundred","seven hundred","eight hundred","nine hundred"};

char *compute(int number)
{
	char *answer;
	int flag=1;
	int flag1=1;
	int hundreds_place=number/100,length=0,tens_place,ones_place;
	if(hundreds_place>0)
	{
		length=length+strlen(hundreds[hundreds_place-1])+1;
		answer=(char *)malloc(length*sizeof(char));
		strcpy(answer,hundreds[hundreds_place-1]);
		if(number%100!=0)
		{
			length=length+5;
			answer=(char *)realloc(answer,length*sizeof(char));
			answer[strlen(hundreds[hundreds_place-1])]=' ';
			strcat(answer,"and ");
			flag=0;
			number=number-(hundreds_place)*100;
                //printf("the number is %d\n",number);
		}
		else
		{
			answer[strlen(hundreds[hundreds_place-1])]='\0';
			return (char *)answer;
		}
	}
	tens_place=number/10;
        //printf("the tens place is %d\n",tens_place);
	if(tens_place>0)
	{
		if((tens_place==1)&&(number%10!=0))
		{
			ones_place=number%10;
			length=length+strlen(teens[ones_place-1])+1;
			if(flag==0)
			{
				answer=(char *)realloc(answer,sizeof(char)*length);
				strcat(answer,teens[ones_place-1]);
				answer[length]='\0';
				return (char *)answer;
			}
			else
			{
				answer=(char *)malloc(sizeof(char)*strlen(teens[ones_place-1]));
				strcpy(answer,teens[ones_place-1]);
				answer[strlen(teens[ones_place-1])]='\0';
				return (char*)answer;
			}
		}
		else
		{
			length=length+strlen(tens[tens_place-1]);
			if(flag==0)
			{
				answer=(char *)realloc(answer,sizeof(char)*(length));
				strcat(answer,tens[tens_place-1]);
				if(number%10==0)
				{
					answer[length]='\0';
					return (char *)answer;
				}
				else
				{
					flag1=0;
					strcat(answer," ");
					number=number-tens_place*10;
                        //printf("The ones is %d\n",number);
				}
			}
			else
			{
				answer=(char *)malloc(sizeof(char)*(length));
				strcpy(answer,tens[tens_place-1]);
				if(number%10==0)
				{
					answer[length]='\0';
					return (char *)answer;
				}
				else
				{
					flag1=0;
					strcat(answer," ");
					number=number-tens_place*10;
				}
			}
		}
	}
	if(flag1==0)
	{
		ones_place=number;
		length=length+strlen(ones[ones_place-1]);
		answer=(char *)realloc(answer,sizeof(char)*(length+1));
		strcat(answer,ones[ones_place-1]);
		answer[length+1]='\0';
		return (char *)answer;
	}
	else
	{
		ones_place=number;
		length=length+strlen(ones[ones_place-1]);
		answer=(char *)malloc(sizeof(char)*(length+1));
		strcpy(answer,ones[ones_place-1]);
		answer[length]='\0';
		return (char *)answer; 
	}
}

int main(void) {
	int input;
	int i=0;
	char *solution;
	printf("Enter the number less than 1000\n");
	scanf("%d",&input);
	solution=(char *)malloc(25*sizeof(char));
	solution=compute(input);
	while(solution[i]!='\0')
	{
		printf("%c",solution[i]);
		i++;
	}
	// your code goes here
	return 0;
}
