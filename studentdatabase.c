# Zoho-assignments.c
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct student
{
	int marks[5];
	char name[50];
	int serialno;
}*studentstructobj;
void main()
{
    int i;
	char temp;
	int temporary;
	int nooflines=0;
	int flag;
	int j;
	float average[5]={0};
	int maximum;
	FILE *fp;
	fp=fopen("D:/studentdatabase.csv","r");
	if(fp==NULL)
	{
		printf("No such file\n");
	}
	else
	{
		temp=fgetc(fp);
		while(temp!=EOF)
		{
			if(temp=='\n')
			{
				nooflines++;
			}
			temp=fgetc(fp);
		}
		studentstructobj=(struct student*)malloc(nooflines*sizeof(struct student));
		rewind(fp);
		for(i=0;i<nooflines;i++)
		{
			fscanf(fp,"%d,%[^,],%d,%d,%d,%d,%d",&studentstructobj[i].serialno,studentstructobj[i].name,&studentstructobj[i].marks[0],&studentstructobj[i].marks[1],&studentstructobj[i].marks[2],&studentstructobj[i].marks[3],&studentstructobj[i].marks[4]);
		}
		for(i=0;i<5;i++)
		{
			for(j=0;j<nooflines;j++)
			{
				average[i]=average[i]+(float)(studentstructobj[j].marks[i]);
			}
			average[i]=average[i]/(float)nooflines;
		}
		for(i=0;i<5;i++)
		{
			printf("The average score in subject %d is %f\n",i+1,average[i]);
		}
		for(i=0;i<5;i++)
		{
			for(j=0;j<nooflines;j++)
			{
				if(j==0)
				{
					maximum=studentstructobj[j].marks[i];
					flag=j;
				}
				else
				{
					temporary=studentstructobj[j].marks[i];
					if(temporary>maximum)
					{
						maximum=temporary;
						flag=j;
					}
				}
			}
			printf("The student with maximum mark in subject %d is %s",i+1,studentstructobj[flag].name);
		}
	}
	getch();

}
