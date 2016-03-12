# Zoho-assignments.c
//
//  main.c
//  parsing
//
//  Created by R.M.D ENGINEERIN COLLEGE on 12/03/16.
//  Copyright © 2016 R.M.D ENGINEERIN COLLEGE. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct designation
{
    char *roll;
};
struct degrees
{
    char *certificates;
};
struct student
{
    char *id;
    char *name;
    struct designation p;
    struct degrees *q;
};
char *stringparsing(struct student s)
{
    char *string;
    string=(char*)malloc(30*sizeof(char));
    strcpy(string,"{");
    strcat(string,"id:");
    strcat(string,s.id);
    strcat(string,",");
    strcat(string,"name:");
    strcat(string,s.name);
    strcat(string,"}");
    return (char *)string;
}
char *formatting(struct student s)
{
    char *string;
    string=(char*)malloc(50*sizeof(string));
    strcpy(string,"\n{\n");
    strcat(string,"\tid:");
    strcat(string,s.id);
    strcat(string,"\n");
    strcat(string,"\tname:");
    strcat(string,s.name);
    strcat(string,"\n\t");
    strcat(string,s.p.roll);
    strcat(string,"\n}");
    return (char *)string;
}
int main(int argc, const char * argv[]) {
    int count;
    printf("enter the number of students: \n");
    scanf("%d",&count);
    struct student *s;
    s=(struct student*)malloc(count*sizeof(struct student));
    int i,j,degreecount;
    for(i=0;i<count;i++)
    {
        printf("Enter the name and id and designation:\n");
        s[i].id=(char*)malloc(10*sizeof(char));
        s[i].name=(char*)malloc(20*sizeof(char));
        s[i].p.roll=(char*)malloc(20*sizeof(char));
        scanf("%s%s%s",s[i].id,s[i].name,s[i].p.roll);
        printf("Enter the number of degrees obtained:\n");
        scanf("%d",&degreecount);
        for(j=0;j<degreecount;j++)
        {
            s[i].q[j].certificates=(char*)malloc(20*sizeof(char));
            printf("Enter the degree :\n");
            scanf("%s",s[i].q[j].certificates);
        }
        char *stringparsed;
        char *formattedstring;
        formattedstring=(char*)malloc(50*sizeof(char));
        stringparsed=(char*)malloc(50*sizeof(char));
        stringparsed=stringparsing(s[i]);
        formattedstring=formatting(s[i]);
        printf("%s",stringparsed);
        printf("%s",formattedstring);
    }
    return 0;
}
