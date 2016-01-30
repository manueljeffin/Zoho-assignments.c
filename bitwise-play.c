# Zoho-assignments.c
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
unsigned char bitset(int number1,int bitindex)
{
    int x=1;
    number1 ^= (-x ^ number1) & (1 << bitindex);
    return number1;
}
unsigned char bitreset(int number1,int bitindex)
{
    int x=0;
    number1 ^= (-x ^ number1) & (1 << bitindex);
    return number1;
}
unsigned char leftrotate(int number1)
{
    int res;
    int moves=1;
    res=(number1<<moves)|(number1>>(8 - moves));
    return res; 
}
unsigned char rightrotate(int number1)
{
    int res;
    int moves=1;
    res=(number1>>moves)|(number1<<(8 - moves));
    return res; 
}
unsigned char toggle(int number1,int bitindex)
{
    int x=bitindex;
    number1^= 1 << x;
    return number1;
}
unsigned char toggleexcept(int number1,int bitindex)
{
    int x=bitindex;
    number1=(~number1)^(1 << x);
    return number1;
}
unsigned char swapnibble(int number1)
{
   number1=((number1 & 0x0F)<<4 | (number1 & 0xF0)>>4); 
   return number1;
}
void display(int number)
{
    	int i;
        int n=128;
	    for(i=0;i<8;i++)
	    {
		        if(n>number)
		        {
			         printf("0");
		        }
		        else
		        {
			         printf("1");
			         number=number%n;
		        }
		        n=n/2;
	    }
        printf("\t");
}


int main() {
    int number,bitindex,result;
    printf("Enter a number: \n");
    scanf("%d",&number);
    printf("Enter the bit index: \n");
    scanf("%d",&bitindex);
    printf("The given number is :");
    display(number);
    printf("\t");
    printf("Decimal equivalent :%d\n",number);
    printf("Bit %d set to one: ",bitindex);
    result=bitset(number,bitindex);
    display(result);
    printf("\t");
    printf("Decimal equivalent :%d\n",result);
    printf("Bit %d set to zero: ",bitindex);
    result=bitreset(number,bitindex);
    display(result);
    printf("\t");
    printf("Decimal equivalent :%d\n",result);
    printf("Toggling bit %d :",bitindex);
    result=toggle(number,bitindex);
    display(result);
    printf("\t");
    printf("Decimal equivalent :%d\n",result);
    printf("Toggling except bit %d :",bitindex);
    result=toggleexcept(number,bitindex);
    display(result);
    printf("\t");
    printf("Decimal equivalent :%d\n",result);
    printf("Left rotate :");
    result=leftrotate(number);
    display(result);
    printf("\t\t");
    printf("Decimal equivalent :%d\n",result);
    printf("Right rotate :");
    result=rightrotate(number);
    display(result);
    printf("\t\t");
    printf("Decimal equivalent :%d\n",result);
    printf("swap nibble :");
    result=swapnibble(number);
    display(result);
    printf("\t\t");
    printf("Decimal equivalent :%d\n",result);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
