# Zoho-assignments.c
//
//  main.c
//  binary_tree
//
//  Created by R.M.D. Engineering College on 05/03/16.
//  Copyright © 2016 R.M.D. Engineering College. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct binarytree
{
    int data;
    struct binarytree *rightnext;
    struct binarytree *leftnext;
};
int main(int argc, const char * argv[]) {
    struct binarytree *newnode=NULL;
    struct binarytree *head=NULL;
    newnode=(struct binarytree*)malloc(sizeof(struct binarytree));
    head=(struct binarytree*)malloc(sizeof(struct binarytree));
    printf("Enter the rootnode:\n");
    int rootnode,element;
    scanf("%d",&rootnode);
    newnode->data=rootnode;
    head=newnode;
    printf("Enter the number of nodes apart from root node in left and right subtree: \n");
    int leftcount,rightcount;
    scanf("%d",&leftcount);
    scanf("%d",&rightcount);
    int i,choice;
    for(i=0;i<leftcount;i++)
    {
        if(i==0)
        {
            scanf("%d",element);
            newnode->leftnext=(struct binarytree*)malloc(sizeof(struct binarytree));
            newnode->leftnext->data=element;
            newnode=newnode->leftnext;
        }
        printf("Where u want to fix the element in the tree(1 for left and 0 for right) and enter the element :\n");
        scanf("%d",&choice);
        scanf("%d",&element);
        if(choice==0)
        {
            newnode->rightnext=(struct binarytree*)malloc(sizeof(struct binarytree));
            newnode->rightnext->data=element;
            newnode=
        }
    }
    
    return 0;
}
