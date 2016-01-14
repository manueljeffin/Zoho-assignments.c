# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
		char *name,initializer,i=0;
		int k=1,j=0;
		name=(char*)malloc(sizeof(char));
		printf("Enter the string you want to display with delay : \n");
		while(1)
		{
			initializer=getc(stdin);
			if((initializer==EOF)||(initializer=='\n'))
			{
				j++;
				break;
			}
			name=(char*)realloc(name,(k+1)*sizeof(char));
			name[j]=initializer;
			j++;
			k++;
		}
		name[j]='\0';
		//printf("the string is : %s\n",name);
		while(name[i]!='\0')
		{
			putchar(name[i]);
			fflush(stdout);
			usleep(100000);
			i+=1;
		}
		
		
		
		
	// your code goes here
	return 0;
}
