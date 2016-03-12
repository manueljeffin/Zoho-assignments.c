# Zoho-assignments.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct binarytreenode
{
    int data;
    struct binarytreenode *leftnext;
    struct binarytreenode *rightnext;
};
int check(struct binarytreenode* node)
{
    int k,k1,k2,sum1;
    if((node->leftnext==NULL)&&(node->rightnext==NULL))
    {
        return 1;
    }
    else
    {
        k=node->data;
        k1=check(node->leftnext);
        k2=check(node->rightnext);
        if((k1==1)&&(k2==1))
        {
            sum1=sum(node->leftnext)+sum(node->rightnext);
        }
        if(k==sum1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int main()
{
    int leftcount,rightcount,i;
    int element;
    int fixer;
    struct binarytreenode *rootnode=NULL;
    struct binarytreenode *lefthead=NULL;
    struct binarytreenode *righthead=NULL;
    struct binarytreenode *temp=NULL;
    struct binarytreenode *temp1=NULL;
    temp1=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
    temp=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
    printf("is the tree empty:press 1 for no and 0  for yes \n");
    scanf("%d",&fixer);
    if(fixer==0)
    {
        printf("The tree is empty and hence it is a sumtree\n");
        return 0;
    }
    printf("Enter the rootnode element :\n");
    scanf("%d",&element);
    rootnode=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
    rootnode->data=element;
    temp1=rootnode;
    printf("Enter the number of elements in left subtree of rootnode:\n");
    scanf("%d",&leftcount);
    if(leftcount!=0)
    {
        printf("Enter the elements of left subtree:\n");
    }
    for(i=0;i<leftcount;i++)
    {
        if(i==0)
        {
            printf("Enter the first element:\n");
            lefthead=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
            scanf("%d",&element);
            lefthead->data=element;
            lefthead->leftnext=NULL;
            lefthead->rightnext=NULL;
            rootnode->leftnext=lefthead;
            continue;
        }
        else
        {
            temp=lefthead;
            while(1)
            {
                printf("Which side u want to traverse:0 for left and 1 for right\n");
                scanf("%d",&fixer);
                if(fixer==0)
                {
                    if(temp->leftnext!=NULL)
                    {
                        temp=temp->leftnext;
                    }
                    else
                    {
                        temp->leftnext=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
                        temp=temp->leftnext;
                        break;
                    }
                }
                else
                {
                    if(temp->rightnext!=NULL)
                    {
                        temp=temp->rightnext;
                    }
                    else
                    {
                        temp->rightnext=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
                        temp=temp->rightnext;
                        break;
                    }
                }
            }
            printf("Enter the element:\n");
            scanf("%d",&element);
            temp->data=element;
            temp->leftnext=NULL;
            temp->rightnext=NULL;
        }
    }
    printf("Enter the number of elements in right subtree: \n");
    scanf("%d",&rightcount);
    if(rightcount!=0)
    {
        printf("Enter the elements of right subtree: \n");
    }
    for(i=0;i<rightcount;i++)
    {
        if(i==0)
        {
            printf("Enter the first element: \n");
            scanf("%d",&element);
            righthead=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
            righthead->data=element;
            righthead->leftnext=NULL;
            righthead->rightnext=NULL;
            rootnode->rightnext=righthead;
            continue;
        }
        else
        {
            temp=righthead;
            while(1)
            {
                printf("Which side u want to traverse:0 for left and 1 for right\n");
                scanf("%d",&fixer);
                if(fixer==0)
                {
                    if(temp->leftnext!=NULL)
                    {
                        temp=temp->leftnext;
                    }
                    else
                    {
                        temp->leftnext=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
                        temp=temp->leftnext;
                        break;
                    }
                }
                else
                {
                    if(temp->rightnext!=NULL)
                    {
                        temp=temp->rightnext;
                    }
                    else
                    {
                        temp->rightnext=(struct binarytreenode*)malloc(sizeof(struct binarytreenode));
                        temp=temp->rightnext;
                        break;
                    }
                }
            }
            printf("Enter the element:\n");
            scanf("%d",&element);
            temp->data=element;
            temp->rightnext=NULL;
            temp->leftnext=NULL;
        }
    }
    int answer;
    answer=check(temp1);
    return 0;
}
