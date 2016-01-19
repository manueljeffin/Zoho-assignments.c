# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printarray(int order,int *puzzle[])
{
	int i,j;
	for(i=0;i<order;i++)
	{
		for(j=0;j<order;j++)
		{
			if(puzzle[i][j]!=0)
			{
				printf("%d ",puzzle[i][j]);
			}
			else
			{
				char a=' ';
				printf("%c ",a);
			}
		}
		printf("\n");
	}
	printf("\n");
}
int solved(int order,int *puzzle[])
{
	int i,j,value=1;
	for(i=0;i<order;i++)
	{
		for(j=0;j<order;j++)
		{
			if((i==(order-1))&&(j==(order-1)))
			{
				return 1;
			}
			if(puzzle[i][j]!=value)
			{
				return 0;
			}
			
		}
	}
	
}

int main(void) {
	int order,i,size,j,temp,m,rowtobeeliminated,columntobeeliminated,number=1;
	int swaprow,swapcolumn,a;
	char enterchar;
	printf("Enter the order of the puzzle: ");
	scanf("%d",&order);
	size=order*order;
	int *temppuzzle[size];
	int *puzzle[order];
	for(i=0;i<size;i++)
	{
		temppuzzle[i]=(int)malloc(sizeof(int));
	}
	for(i=0;i<order;i++)
	{
		puzzle[i]=(int*)malloc(order*sizeof(int));
	}
	for(i=0;i<size;i++)
	{
		temppuzzle[i]=i+1;
	}
	srand(time(NULL));
	for(i=size-1;i>0;i--)
	{
		j=rand()%(i+1);
		temp=temppuzzle[i];
		temppuzzle[i]=temppuzzle[j];
		temppuzzle[j]=temp;
	}
	printf("\n");
	m=0;
	for(i=0;i<order;i++)
	{
		for(j=0;j<order;j++)
		{
			puzzle[i][j]=temppuzzle[m++];
			if(puzzle[i][j]==(order*order))
			{
				rowtobeeliminated=i;
				columntobeeliminated=j;
			}
			
		}
	}
	puzzle[rowtobeeliminated][columntobeeliminated]=0;
	printarray(order,puzzle);
	printf("Enter the characters D to move downwards, U to moveupwards, L to move left, R to move right and Q to quit\n");
	while(number)
	{
		scanf("%c",&enterchar);
		switch(enterchar)
		{
			case 'D':
			{
				if(rowtobeeliminated==(order-1))
				{
					printf("wrong choice,action cannot be performed\n");
				}
				else
				{
					swaprow=rowtobeeliminated+1;
					swapcolumn=columntobeeliminated;
					temp=puzzle[rowtobeeliminated][columntobeeliminated];
					puzzle[rowtobeeliminated][columntobeeliminated]=puzzle[swaprow][swapcolumn];
					puzzle[swaprow][swapcolumn]=temp;
					rowtobeeliminated=swaprow;
					columntobeeliminated=swapcolumn;
					printarray(order,puzzle);
				}
				
			}
			break;
			case 'U':
			{
				if(rowtobeeliminated==0)
				{
					printf("wrong choice,action cannot be performed\n");
				}
				else
				{
					swaprow=rowtobeeliminated-1;
					swapcolumn=columntobeeliminated;
					temp=puzzle[rowtobeeliminated][columntobeeliminated];
					puzzle[rowtobeeliminated][columntobeeliminated]=puzzle[swaprow][swapcolumn];
					puzzle[swaprow][swapcolumn]=temp;
					rowtobeeliminated=swaprow;
					columntobeeliminated=swapcolumn;
					printarray(order,puzzle);
				}
				
			}
			break;
			case 'L':
			{
				if(columntobeeliminated==0)
				{
					printf("wrong choice,action cannot be performed\n");
				}
				else
				{
					swaprow=rowtobeeliminated;
					swapcolumn=columntobeeliminated-1;
					temp=puzzle[rowtobeeliminated][columntobeeliminated];
					puzzle[rowtobeeliminated][columntobeeliminated]=puzzle[swaprow][swapcolumn];
					puzzle[swaprow][swapcolumn]=temp;
					rowtobeeliminated=swaprow;
					columntobeeliminated=swapcolumn;
					printarray(order,puzzle);
				}
				
			}
			break;
			case 'R':
			{
				if(columntobeeliminated==(order-1))
				{
					printf("wrong choice,action cannot be performed\n");
				}
				else
				{
					swaprow=rowtobeeliminated;
					swapcolumn=columntobeeliminated+1;
					temp=puzzle[rowtobeeliminated][columntobeeliminated];
					puzzle[rowtobeeliminated][columntobeeliminated]=puzzle[swaprow][swapcolumn];
					puzzle[swaprow][swapcolumn]=temp;
					rowtobeeliminated=swaprow;
					columntobeeliminated=swapcolumn;
					printarray(order,puzzle);
				}
				
			}
			break;
			case 'Q':
				number=0;
				printf("the game is terminated\n");
				break;
			case '\n':
				break;
			default:
				printf("Wrong choice, action cannot be performed\n");
				break;
		}
		if(number!=0)
		{
			a=solved(order,puzzle);
			if(a==1)
			{
				printf("Congrats!!! u have solved the puzzle \n");
				number=0;
			}
		}
	}
	
	// your code goes here
	return 0;
}
