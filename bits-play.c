# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void bitsettoone(int copyarray[],int bitindex)
{
    int value=0,i;
    printf("Bit %d set to 1 :",bitindex);
    copyarray[8-1-bitindex]=1;
    for(i=0;i<8;i++)
    {
        printf("%d",copyarray[i]);
        value=value+(copyarray[i]*(pow(2,(8-1-i))));
    }
    printf("\t");
    printf("Decimal equivalent: %d",value);
    printf("\n");
}
void bitsettozero(int copyarray[],int bitindex)
{
    int value=0,i;
    printf("Bit %d set to 1 :",bitindex);
    copyarray[8-1-bitindex]=0;
    for(i=0;i<8;i++)
    {
        printf("%d",copyarray[i]);
        value=value+(copyarray[i]*(pow(2,(8-1-i))));
    }
    printf("\t");
    printf("Decimal equivalent: %d",value);
    printf("\n");
}
void togglebit(int copyarray[],int bitindex)
{
    int copyarray2[8];
    int value=0,i;
    printf("Toggling bit %d :",bitindex);
    for(i=0;i<8;i++)
    {
        if(i==(8-1-bitindex))
        {
            if(copyarray[i]==1)
            {
                copyarray2[i]=0;
            }
            else
            {
                copyarray2[i]=1;
            }
        }
        else
        {
            copyarray2[i]=copyarray[i];
        }
        printf("%d",copyarray2[i]);
        value=value+(copyarray2[i]*(pow(2,(8-1-i))));
    }
    printf("\t");
    printf("Decimal equivalent :%d",value);
    printf("\n");
}
void toggleexceptbit(int copyarray[],int bitindex)
{
    int copyarray2[8];
    int value=0,i;
    printf("Toggling except bit %d :",bitindex);
    for(i=0;i<8;i++)
    {
        if(i!=(8-1-bitindex))
        {
            if(copyarray[i]==1)
            {
                copyarray2[i]=0;
            }
            else
            {
                copyarray2[i]=1;
            }
        }
        else if(i==(8-1-bitindex))
        {
            copyarray2[i]=copyarray[i];
        }
        printf("%d",copyarray2[i]);
        value=value+(copyarray2[i]*(pow(2,(8-1-i))));
    }
    printf("\t");
    printf("Decimal equivalent :%d",value);
    printf("\n");
}
void rotateright(int copyarray[],int bitindex)
{
    int copyarray2[8];
    int value=0,i;
    printf("Rotate Right :");
    for(i=1;i<=8;i++)
    {
        copyarray2[i%8]=copyarray[i-1];
    }
    for(i=0;i<8;i++)
    {
        printf("%d",copyarray2[i]);
        value=value+(copyarray2[i]*(pow(2,(8-1-i))));
    }
    printf("\t");
    printf("Decimal equivalent :%d",value);
    printf("\n");
}
void rotateleft(int copyarray[],int bitindex)
{
    int copyarray2[8];
    int value=0,i;
    printf("Rotate Left :");
    for(i=0;i<8;i++)
    {
        copyarray2[i]=copyarray[(i+1)%8];
        printf("%d",copyarray2[i]);
        value=value+(copyarray2[i]*(pow(2,(8-1-i))));
    }
    printf("\t");
    printf("Decimal equivalent :%d",value);
    printf("\n");
}
void swapnibble(int copyarray[])
{
    int value=0,i;
    printf("Swap Array: ");
    for(i=0;i<8;i++)
    {
        printf("%d",copyarray[i]);
        value=value+(copyarray[i]*(pow(2,(8-1-i))));
    }
    printf("\t");
    printf("Decimal equivalent: %d",value);
    printf("\n");
}
int main(void) {
	int number,i,temp,temparray[8],m=0,array[8],value,value1,valarray[8],bitindex,copyarray[8],value2=0;
    int copyarray2[8];
	printf("Enter a number within 255 : \n");
	scanf("%d",&number);
    printf("Enter the bit index : \n");
    scanf("%d",&bitindex);
	temp=number;
	if(temp<2)
	{
		temparray[m]=temp;
	}
	else
	{
		while(temp>1)
		{
			temparray[m]=temp%2;
			m++;
			temp=temp/2;
		}
		temparray[m]=temp;
	}
	value=m+1;
	for(i=0;i<value;i++)
	{
		array[i]=temparray[m];
		m--;
	}
	for(i=value;i<8;i++)
	{
		array[i]=0;
	}
	for(i=0;i<8;i++)
	{
		printf("%d",array[i]);
	}
	printf("\n");
	value1=4;
	/*for(i=0;i<4;i++)
	{
		temp=array[i];
		array[i]=array[value1];
		array[value1]=temp;
		value1--;
	}*/
	for(i=0;i<4;i++)
	{
		valarray[i]=array[value1];
        copyarray[i]=valarray[i];
		value1++;
	}
	value1=0;
	for(i=4;i<8;i++)
	{
		valarray[i]=array[value1];
        copyarray[i]=valarray[i];
		value1++;
	}
    printf("Given Number :");
	for(i=0;i<8;i++)
	{
		printf("%d",valarray[i]);
	}
    printf("\t");
    printf("decimal equivalent :%d\n",number);
    bitsettoone(valarray,bitindex);
    bitsettozero(valarray,bitindex);
    togglebit(valarray,bitindex);
    toggleexceptbit(valarray,bitindex);
    rotateright(valarray,bitindex);
    rotateleft(valarray,bitindex);
    swapnibble(array);
    
	// your code goes here
	return 0;
}
