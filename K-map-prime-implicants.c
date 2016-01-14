# Zoho-assignments.c
#include <stdio.h>


int main(void) {
	int noofvariables,number,input[100]={0},j=0,i,noofminterms,binaryofinput[100][100]={0},k,m,count;
	int group[100]={0},type[100]={0},b,c,primeimplicant[100][100]={0},x=0;
    int d=0,e=0,f=1,pairings[100][100][100]={0},secondlevel[100][100]={0},y;
	int groupings[100][100][100]={0},j2,copy[100][100][100]={0},pairs[100][100]={0},num[100]={0},flagship,n;
    int count1,group1[100]={0},type1[100]={0},groupings1[100][100][100]={0},num1[100]={0};
    int copy1[100][100][100]={0},pairs1[100][100]={0},pairings1[100][100][100]={0};
    int d1=0,thirdlevel[100][100],z,g=0,j1,fourthlevel[100][100]={0};
    char fourthlevelchar[100][100];
	printf("enter the number of variables : \n");
	scanf("%d",&noofvariables);
	printf("enter the minterms(after giving all the variables as inputs enter -1 to specify the end)) : \n");
	while(scanf("%d",&number)!=-1)
	{
		input[j]=number;
		j++;
	}
	noofminterms=j-2;
    printf("the minterms u entered are :\n");
	for(i=0;i<=noofminterms;i++)
	{
		printf("%d\n",input[i]);
	}
	
	for(i=0;i<=noofminterms;i++)
	{
		if(input[i]<2)
		{
			k=noofvariables-1;
			binaryofinput[i][k]=input[i];
		}
		else
		{
			k=noofvariables-1;
			while(input[i]>1)
			{
				binaryofinput[i][k]=input[i]%2;
				k=k-1;
				input[i]=input[i]/2;
			}
			binaryofinput[i][k]=input[i];
		}
	}
	for(i=0;i<=noofminterms;i++)
	{
		count=0;
		for(m=0;m<noofvariables;m++)
		{
			
			if(binaryofinput[i][m]==1)
			{
				count=count+1;
			}
			
		}
		group[count]=group[count]+1;
		type[i]=count;
		
	}
	for(i=0;i<=noofminterms;i++)
	{
		for(m=0;m<noofvariables;m++)
		{
			groupings[type[i]][num[type[i]]][m]=binaryofinput[i][m];
		}
		num[type[i]]=num[type[i]]+1;
		
	}
    printf("the groupings are :\n");
	for(i=0;i<=noofvariables;i++)
	{
		for(b=0;b<num[i];b++)
		{
			for(m=0;m<noofvariables;m++)
			{
				printf("%d",groupings[i][b][m]);
			}
			printf("\n");
		}
		
	}
	for(i=0;i<=noofvariables;i++)
	{
		for(b=0;b<num[i];b++)
		{
			for(m=0;m<noofvariables;m++)
			{
				copy[i][b][m]=groupings[i][b][m];
			}
			
		}
		
	}
	for(i=0;i<noofvariables;i++)
	{
		for(b=0;b<num[i];b++)
		{
			n=i+1;
			for(c=0;c<num[n];c++)
			{
				flagship=0;
				for(m=0;m<noofvariables;m++)
				{
					if(groupings[i][b][m]!=groupings[n][c][m])
					{
						flagship=flagship+1;
					}
				}
				if(flagship==1)
				{
					for(m=0;m<noofvariables;m++)
					{
						if(groupings[i][b][m]!=groupings[n][c][m])
						{
							copy[n][c][m]=-1;
							pairs[i][b]=1;
							pairs[n][c]=1;
						}
					}
				}
				
			}
			
		}
	}
	for(i=0;i<=noofvariables;i++)
	{
		for(b=0;b<num[i];b++)
		{
			if(pairs[i][b]!=1)
			{
				for(m=0;m<noofvariables;m++)
				{
					primeimplicant[x][m]=groupings[i][b][m];
				}
				x++;
			}
		}
		
	}
	for(i=0;i<noofvariables;i++)
	{
		for(b=0;b<num[i];b++)
		{
			n=i+1;
			for(c=0;c<num[n];c++)
			{
				flagship=0;
				for(m=0;m<noofvariables;m++)
				{
					if(groupings[i][b][m]!=groupings[n][c][m])
					{
						flagship=flagship+1;
					}
				}
				if(flagship==1)
				{
					for(m=0;m<noofvariables;m++)
					{
						pairings[d][e][m]=groupings[i][b][m];
					}
					
					
					for(m=0;m<noofvariables;m++)
					{
						pairings[d][f][m]=groupings[n][c][m];
					}
					
					d++;
				
				}
				
			}
			
		}
	}

    for(i=0;i<d;i++)
    {
        for(m=0;m<noofvariables;m++)
        {
            if(pairings[i][e][m]==pairings[i][f][m])
            {
                secondlevel[i][m]=pairings[i][f][m];
            }
            else
            {
                secondlevel[i][m]=-1;
            }
        }
    }
    y=i;
    printf("the second level of computation:\n");
    for(i=0;i<y;i++)
    {
        for(m=0;m<noofvariables;m++)
        {
            printf("%d",secondlevel[i][m]);
        }
        printf("\n");
    }
    for(i=0;i<y;i++)
    {
        count1=0;
        for(m=0;m<noofvariables;m++)
        {
            if(secondlevel[i][m]==1)
            {
                count1=count1+1;
            }
        }
        group1[count1]=group1[count1]+1;
        type1[i]=count1;
    }
    for(i=0;i<y;i++)
    {
        for(m=0;m<noofvariables;m++)
        {
            groupings1[type1[i]][num1[type1[i]]][m]=secondlevel[i][m];
        }
        num1[type1[i]]=num1[type1[i]]+1;
    }
    printf("the second level of groupings are:\n");
    for(i=0;i<=noofvariables;i++)
    {
        for(b=0;b<num1[i];b++)
        {
            for(m=0;m<noofvariables;m++)
            {
                printf("%d",groupings1[i][b][m]);
            }
            printf("\n");
        }
    }
    for(i=0;i<=noofvariables;i++)
    {
        for(b=0;b<num1[i];b++)
        {
            for(m=0;m<noofvariables;m++)
            {
                copy1[i][b][m]=groupings1[i][b][m];
            }
        }
    }
    for(i=0;i<noofvariables;i++)
    {
        for(b=0;b<num1[i];b++)
        {
            n=i+1;
            for(c=0;c<num1[n];c++)
            {
                flagship=0;
                for(m=0;m<noofvariables;m++)
                {
                    if(groupings1[i][b][m]!=groupings1[n][c][m])
                    {
                        flagship=flagship+1;
                    }
                }
                if(flagship==1)
                {
                    for(m=0;m<noofvariables;m++)
                    {
                        if(groupings1[i][b][m]!=groupings1[n][c][m])
                        {
                            copy1[n][c][m]=-1;
                            pairs1[i][b]=1;
                            pairs1[n][c]=1;
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<=noofvariables;i++)
    {
        for(b=0;b<num1[i];b++)
        {
            if(pairs1[i][b]!=1)
            {
                for(m=0;m<noofvariables;m++)
                {
                    primeimplicant[x][m]=groupings1[i][b][m];
                }
                x++;
            }
        }
    }
    for(i=0;i<noofvariables;i++)
    {
        for(b=0;b<num1[i];b++)
        {
            n=i+1;
            for(c=0;c<num1[n];c++)
            {
                flagship=0;
                for(m=0;m<noofvariables;m++)
                {
                    if(groupings1[i][b][m]!=groupings1[n][c][m])
                    {
                        flagship=flagship+1;
                    }
                }
                if(flagship==1)
                {
                    for(m=0;m<noofvariables;m++)
                    {
                        pairings1[d1][e][m]=groupings1[i][b][m];
                        pairings1[d1][f][m]=groupings1[n][c][m];
                    }
                    d1++;
                }
            }
        }
    }
    printf("the pairings are:\n");
    for(i=0;i<d1;i++)
    {
        for(m=0;m<noofvariables;m++)
        {
            printf("%d",pairings1[i][e][m]);
        }
        printf("\n");
        for(m=0;m<noofvariables;m++)
        {
            printf("%d",pairings1[i][f][m]);
        }
        printf("\n");
    }
    for(i=0;i<d1;i++)
    {
        for(m=0;m<noofvariables;m++)
        {
            if(pairings1[i][e][m]==pairings1[i][f][m])
            {
                thirdlevel[i][m]=pairings1[i][f][m];
            }
            else
            {
                thirdlevel[i][m]=-1;
            }
        }
    }
    z=i;
    printf("the thirdlevel of computation:\n");
    for(i=0;i<z;i++)
    {
        for(m=0;m<noofvariables;m++)
        {
            printf("%d",thirdlevel[i][m]);
        }
        printf("\n");
    }
    for(i=0;i<z-1;i++)
    {
        
        for(j1=i+1;j1<z;j1++)
        {
            flagship=0;   
            for(m=0;m<noofvariables;m++)
            {
               if(thirdlevel[i][m]!=thirdlevel[j1][m])
               {
                   flagship=1;
               }
            }
            if(flagship==0)
            {
                break;
            }
        }
        if(flagship==1)
        {
            for(m=0;m<noofvariables;m++)
            {
                fourthlevel[g][m]=thirdlevel[i][m];
            }
            g++;
        }
        
    }
    for(m=0;m<noofvariables;m++)
    {
        fourthlevel[g][m]=thirdlevel[z-1][m];
    }
    g++;
    for(i=0;i<g;i++)
    {
        for(m=0;m<noofvariables;m++)
        {
            if(fourthlevel[i][m]!=-1)
            {
                fourthlevelchar[i][m]=fourthlevel[i][m]+'0';
            }
            else
            {
                fourthlevelchar[i][m]='-';
            }
        }
    }
    
    
    printf("the grouped prime implicants are:\n");
    for(i=0;i<g;i++)
    {
        for(m=0;m<noofvariables;m++)
        {
            printf("%c",fourthlevelchar[i][m]);
        }
        printf("\n");
    }
    printf("the ungrouped prime implicants are :\n");
    j2=i;
    for(i=0;i<x;i++)
    {
        for(m=0;m<noofvariables;m++)
        {
            if(primeimplicant[i][m]!=-1)
            {
                fourthlevelchar[j2][m]=primeimplicant[i][m]+'0';
            }
            else
            {
                fourthlevelchar[j2][m]='-';
            }
        }
        
        for(m=0;m<noofvariables;m++)
        {
            printf("%c",fourthlevelchar[j2][m]);
        }
        printf("\n");
        j2++;
    }
    printf("the overall number of prime impicants are :\n");
    for(i=0;i<j2;i++)
    {
        for(m=0;m<noofvariables;m++)
        {
            printf("%c",fourthlevelchar[i][m]);
        }
        printf("\n");
    }
   
    return 0;	
}
