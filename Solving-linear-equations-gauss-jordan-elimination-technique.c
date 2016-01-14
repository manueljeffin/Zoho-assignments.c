# Zoho-assignments.c
#include <stdio.h>

int main(void) {
	int a[100][100]={0},dimension,i,j,k,pivotelement,n=1,solution1;
	float solution[100];
	solution[0]=0;
	printf("Enter the dimension of the square matrix : \n");
	scanf("%d",&dimension);
	printf("enter the elements of the matrix: \n");
	printf("enter the rhs of the equation as the extra column : \n");
	/* for example the linear EQUATIONS  2x+4y=19 and 3x+4y=65 are given input as 2 4 19  3 4 65 ... that is though the matrix is of order n*n an extra column element indicating rhs is given as input to each of the ith row element*/
	for(i=1;i<=dimension;i++)
	{
		for(j=1;j<=dimension+1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	if(dimension==1)
	{
		printf("the diagonal matrix using gauss jordon elimination method is : %d\n",a[1][1]);
		solution1=a[1][2]/a[1][1];
		printf("the solution of linear equation is : %d\n",solution1);
	}
	else
	{
		for(j=1;j<=dimension;j++)
		{
			pivotelement=a[j][j];
			for(i=1;i<=dimension;i++)
			{
				if(i==j)
				{
					continue;
				}
				else
				{
					for(k=1;k<=dimension+1;k++)
					{
						if(k==j)
						{
							continue;
						}
						else
						{
							a[i][k]=(pivotelement*a[i][k])-(a[j][k]*a[i][j]);
						}
					}
				}
			}
			for(i=1;i<=dimension;i++)
			{
				if(i==j)
				{
					continue;
				}
				else
				{
					a[i][j]=0;
				}
			}
		}
		printf("the diagonal matrix using gauss jordon elimination method is : \n");
		for(i=1;i<=dimension;i++)
		{
			for(j=1;j<=dimension+1;j++)
			{
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		printf("The solutions of linear equations: \n");
		for(i=1;i<=dimension;i++)
		{
			solution[n]=(float)a[i][dimension+1]/(float)a[i][i];
			n++;
		}
		for(i=1;i<n;i++)
		{
		
			printf("variable %d: %f\n",i,solution[i]);
		}
	
	}
	
	// your code goes here
	return 0;
}
