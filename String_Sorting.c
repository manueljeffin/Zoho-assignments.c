# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	int i,j;
	int runtimevalue=0;
	char ***values;
	int *lengthchecker,length;
	char str[100];
    char tempstr[100];
    int maxlength=0;
    int k,strcomparer;
	lengthchecker=(int *)calloc(10,sizeof(int));
	printf("Enter the values: \n");
	values=(char ***)malloc(10*sizeof(char **));
	for(i=0;i<10;i++)
	{
		values[i]=(char **)malloc(10*sizeof(char));
		for(j=0;j<10;j++)
		{
			values[i][j]=(char *)malloc(20*sizeof(char));
		}
	}
	printf("Enter the strings :\n");
	while(1)
	{
        str[0]='\0';
		scanf("%s",str);
		if(str[0]=='\0')
		{
			break;
		}
		length=strlen(str);
        strcpy(values[length][lengthchecker[length]++],str);
		if(length>maxlength)
		{
			maxlength=length;
		}
	}
	for(i=0;i<=maxlength;i++)
	{
		if(lengthchecker[i]==0)
		{
			continue;
		}
        if(lengthchecker[i]!=1)
        {
            for(j=0;j<lengthchecker[i];j++)
            {
                for(k=j+1;k<lengthchecker[i];k++)
                {
                    strcomparer=strcmp(values[i][j],values[i][k]);
                    if(strcomparer>0)
                    {
                        strcpy(tempstr,values[i][j]);
                        strcpy(values[i][j],values[i][k]);
                        strcpy(values[i][k],tempstr);
                    }
                }
            }
        }
		for(j=0;j<lengthchecker[i];j++)
		{
			printf("%s\n",values[i][j]);
		}
	}
	// your code goes here
	return 0;
}
