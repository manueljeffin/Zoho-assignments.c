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
struct student
{
    char *id;
    char *name;
}s;
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
    strcat(string,"\n");
    strcat(string,"}");
    return (char *)string;
}
int main(int argc, const char * argv[]) {
    s.id="123";
    s.name="karthik";
    char *stringparsed;
    char *formattedstring;
    formattedstring=(char*)malloc(sizeof(char));
    stringparsed=(char*)malloc(sizeof(char));
    stringparsed=stringparsing(s);
    formattedstring=formatting(s);
    printf("%s",stringparsed);
    printf("%s",formattedstring);
    return 0;
}
