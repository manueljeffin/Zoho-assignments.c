//
//  main.c
//  studentid
//
//  Created by R.M.D. Engineering College on 05/03/16.
//  Copyright © 2016 R.M.D. Engineering College. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct id
{
    int serial_no;
    char name[30];
};
int main(int argc, const char * argv[]) {
    struct id *students;
    struct id *copystudent;
    int count,i;
    printf("Enter the number of students :\n");
    scanf("%d",&count);
    getchar();
    students=(struct id*)malloc(count*sizeof(struct id));
    copystudent=(struct id*)malloc(count*sizeof(struct id));
    printf("enter the name of students :\n");
    for(i=0;i<count;i++)
    {
        students[i].serial_no=i+1;
        copystudent[i].serial_no=i+1;
        scanf("%[^\n]s",students[i].name);
        getchar();
        //gets(students[i].name);
    }
    for(i=0;i<count;i++)
    {
        printf("%d %s\n",students[i].serial_no,students[i].name);
    }
    for(i=0;i<count;i++)
    {
        int j=0;
        int flagship=0;
        int dot_breaker=0;
        int space_breaker=0;
        int l=0;
        while(students[i].name[j]!='\0')
        {
            if(students[i].name[j]=='.')
            {
                flagship=1;
                dot_breaker=j;
                break;
            }
            if(students[i].name[j]==' ')
            {
                flagship=2;
                space_breaker=j;
                break;
            }
            j++;
        }
        if(flagship==0)
        {
            strcpy(copystudent[i].name,students[i].name);
        }
        if(flagship==1)
        {
            l=dot_breaker+1;
            int k=0;
            while((students[i].name[l]!='\0')&&(students[i].name[l]!=' '))
            {
                printf("%d %d\n",i,l);
                copystudent[i].name[k]=students[i].name[l];
                l++;
                k++;
            }
            copystudent[i].name[k]='\0';
        }
        if(flagship==2)
        {
            int k;
            for(k=0;k<space_breaker;k++)
            {
                copystudent[i].name[k]=students[i].name[k];
            }
            copystudent[i].name[k]='\0';
        }
    }
    for(i=0;i<count;i++)
    {
        printf("%s\n",copystudent[i].name);
    }
    int compare,j,k,counter1;
    int k1;
    int *terminator;
    int counter[10][10];
    terminator=(int *)malloc(count*sizeof(int));
    for(i=0;i<count;i++)
    {
        terminator[i]=1;
    }
    for(i=0;i<count;i++)
    {
        k=0;
        counter1=1;
        counter[i][k]=i+1;
        k++;
        if(terminator[i]==1)
        {
            printf("%s,",copystudent[i].name);
            for(j=i+1;j<count;j++)
            {
                compare=strcmp(copystudent[i].name,copystudent[j].name);
                if(compare==0)
                {
                    terminator[j]=0;
                    counter[i][k]=j+1;
                    counter1++;
                    k++;
                }
            }
            printf("%d,[",counter1);
            for(k1=0;k1<k;k1++)
            {
                if(k1==k-1)
                {
                    printf("%d",counter[i][k1]);
                    continue;
                }
                printf("%d,",counter[i][k1]);
            }
            printf("]\n");
        }
    }
    return 0;
}
