# Zoho-assignments.c
#include<stdio.h>
#include<stdlib.h>

struct listnode1
{
    int data;
    struct listnode1* next;
};
struct listnode2
{
    int data;
    struct listnode2* next;
};
int main()
{
    int flagship=1,value=0;
    int number1,number2;
    int num1[15],num2[15],solutionarray[15];
    int noofele1=0,noofele2=0,temp,flag=0,i;
    struct listnode1 *newnode1=NULL;
    struct listnode1 *head1=NULL;
    struct listnode1 *solution=NULL;
    struct listnode1 *protohead1=NULL;
    struct listnode1 *solutionhead=NULL;
    struct listnode2 *newnode2=NULL;
    struct listnode2 *head2=NULL;
    struct listnode2 *protohead2=NULL;
    newnode1=(struct listnode1*)malloc(sizeof(struct listnode1));
    head1=(struct listnode1*)malloc(sizeof(struct listnode1));
    protohead1=(struct listnode1*)malloc(sizeof(struct listnode1));
    solution=(struct listnode1*)malloc(sizeof(struct listnode1));
    solutionhead=(struct listnode1*)malloc(sizeof(struct listnode1));
    newnode2=(struct listnode2*)malloc(sizeof(struct listnode2));
    head2=(struct listnode2*)malloc(sizeof(struct listnode2));
    protohead2=(struct listnode2*)malloc(sizeof(struct listnode2));
    printf("Enter the numbers which are to be added :\n");
    scanf("%d%d",&number1,&number2);
    while(number1>0)
    {
        temp=number1%10;
        num1[noofele1]=temp;
        noofele1++;
        number1=number1/10;
    }
    while(number2>0)
    {
        temp=number2%10;
        num2[noofele2]=temp;
        noofele2++;
        number2=number2/10;
    }
    for(i=0;i<noofele1;i++)
    {
        if(i==0)
        {
            newnode1->data=num1[i];
            newnode1->next=(struct listnode1*)malloc(sizeof(struct listnode1));
            head1=newnode1;
            protohead1=newnode1;
            newnode1=newnode1->next;
            continue;
        }
        else if(i==(noofele1-1))
        {
            newnode1->data=num1[i];
            newnode1->next=NULL;
            continue;
        }
        else
        {
            newnode1->data=num1[i];
            newnode1->next=(struct listnode1*)malloc(sizeof(struct listnode1));
            newnode1=newnode1->next;
            continue;
        }
    }
    for(i=0;i<noofele2;i++)
    {
        if(i==0)
        {
            newnode2->data=num2[i];
            newnode2->next=(struct listnode2*)malloc(sizeof(struct listnode2));
            head2=newnode2;
            protohead2=newnode2;
            newnode2=newnode2->next;
            continue;
        }
        else if(i==(noofele2-1))
        {
            newnode2->data=num2[i];
            newnode2->next=NULL;
            continue;
        }
        else
        {
            newnode2->data=num2[i];
            newnode2->next=(struct listnode2*)malloc(sizeof(struct listnode2));
            newnode2=newnode2->next;
            continue;
        }
    }
    while((head1!=NULL)&&(head2!=NULL))
    {
        temp=(head1->data+value)+head2->data;
        value=0;
        if(temp>=10)
        {
            value=1;
            temp=temp-10;
        }
        solution->data=temp;
        solution->next=(struct listnode1*)malloc(sizeof(struct listnode1));
        if(flagship==1)
        {
            solutionhead=solution;
            flagship=0;
        }
        solution=solution->next;
        head1=head1->next;
        head2=head2->next;
    }
    if((head1==NULL)&&(head2!=NULL))
    {
        flag=1;
    }
    if((head1!=NULL)&&(head2==NULL))
    {
        flag=2;
    }
    if(flag==1)
    {
        while((head2->next)!=NULL)
        {
            solution->data=(head2->data+value);
            temp=solution->data;
            value=0;
            if(temp>=10)
            {
                value=1;
                temp=temp-10;
            }
            solution->next=(struct listnode1*)malloc(sizeof(struct listnode1));
            head2=head2->next;
            solution=solution->next;
        }
        solution->data=(head2->data+value);
        solution->next=NULL;
    }
    if(flag==2)
    {
        while((head1->next)!=NULL)
        {
            solution->data=(head1->data+value);
            temp=solution->data;
            value=0;
            if(temp>=10)
            {
                value=1;
                temp=temp-10;
            }
            solution->next=(struct listnode1*)malloc(sizeof(struct listnode1));
            head1=head1->next;
            solution=solution->next;
        }
        solution->data=(head1->data+value);
        solution->next=NULL;
    }
    i=0;
    while(solutionhead!=NULL)
    {
        if(flag==0)
        {
            if(solutionhead->next==NULL)
            {
                temp=((solutionhead->data)+value);
                solutionarray[i]=temp;
                i++;
                solutionhead=solutionhead->next;
                break;
            }
            else
            {
                temp=solutionhead->data;
                solutionarray[i]=temp;
                i++;
                solutionhead=solutionhead->next;
                continue;
            }
        }
        temp=solutionhead->data;
        solutionarray[i]=temp;
        i++;
        solutionhead=solutionhead->next;
        continue;
    }
    printf("The solution is :\n");
    while(i--)
    {
        printf("%d",solutionarray[i]);
    }
    return 0;
}
