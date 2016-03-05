# Zoho-assignments.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct date
{
    int days;
    int month;
    int year;
};
char *monthnames[]={"January","Febrauary","March","April","May","June","July","August","September","October","November","December"};
char *daynames[]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int previous_year(struct date dateobj)
{
    int prev_year=dateobj.year-1;
    return prev_year;
}
int present_month(struct date dateobj)
{
    int pres_month=dateobj.month;
    return pres_month;
}
char *present_month_name(struct date dateobj)
{
    char *month_name;
    month_name=(char *)malloc(10*sizeof(char));
    int temp=dateobj.month;
    strcpy(month_name,monthnames[temp-1]);
    return (char *)month_name;
}
char *previous_month_name(struct date dateobj)
{
    char *month_name;
    month_name=(char *)malloc(10*sizeof(char));
    int temp=dateobj.month;
    if(temp==1)
    {
        strcpy(month_name,monthnames[11]);
    }
    else
    {
        temp=temp-1;
        strcpy(month_name,monthnames[temp-1]);
    }
    return (char *)month_name;
}
int pres_date(struct date dateobj)
{
    int date=dateobj.days;
    return date;
}
char *present_day(struct date dateobj)
{
    char *day_name;
    day_name=(char *)malloc(10*sizeof(char));
    int tempday=dateobj.days;
    int tempmonth=dateobj.month;
    int tempyear=dateobj.year;
    int computeddate;
    computeddate=tempday;
    if(tempmonth<3)
    {
        tempmonth=tempmonth+12;
        tempyear=tempyear-1;
    }
    int divadjustment=tempyear/100;
    int modulasadjustment=tempyear%100;
    computeddate=computeddate+(int)((13*(tempmonth+1))/5)+modulasadjustment+(int)(modulasadjustment/4)+(5*divadjustment)+(int)(divadjustment/4);
    computeddate=computeddate%7;
    day_name=strcpy(day_name,daynames[computeddate]);
    return (char *)day_name;
}
void date_finder(struct date dateobj,int skip)
{
    struct tm date_find={.tm_year=(dateobj.year-(dateobj.year-(dateobj.year%100))+100),.tm_mon=dateobj.month-1,.tm_mday=dateobj.days};
    date_find.tm_mday+=skip;
    mktime(&date_find);
    printf("%s\n",asctime(&date_find));
}
int main()
{
    struct date dateobj;
    char date[11];
    printf("Enter the input date: \n");
    scanf("%s",date);
    int multiplier=1000,i=0,temp;
    while(date[i]!='\0')
    {
        if(i<4)
        {
            temp=(int)(date[i]-'0');
            if(i==0)
            {
                dateobj.year=(temp*multiplier);
                multiplier=multiplier/10;
                i++;
                continue;
            }
            dateobj.year=(dateobj.year)+temp*multiplier;
            multiplier=multiplier/10;
            i++;
            continue;
        }
        if(i==4)
        {
            i++;
            continue;
        }
        if(i<7)
        {
            temp=(int)(date[i]-'0');
            if(i==5)
            {
                dateobj.month=(temp*10);
                i++;
                continue;
            }
            else
            {
                dateobj.month=dateobj.month+temp;
                i++;
                continue;
            }
        }
        if(i==7)
        {
            i++;
            continue;
        }
        if(i<10)
        {
            temp=(int)(date[i]-'0');
            if(i==8)
            {
                dateobj.days=temp*10;
                i++;
                continue;
            }
            else
            {
                dateobj.days=dateobj.days+temp;
                i++;
                continue;
            }
        }
    }
    /*printf("%d\n",dateobj.year);
    printf("%d\n",dateobj.month);
    printf("%d\n",dateobj.days);*/
    int prev_year=previous_year(dateobj);
    printf("The previous year is %d\n",prev_year);
    int pres_month=present_month(dateobj);
    printf("The present month is %d\n",pres_month);
    char *month_name;
    month_name=(char *)malloc(10*sizeof(char));
    month_name=present_month_name(dateobj);
    printf("The present month is %s\n",month_name);
    month_name=previous_month_name(dateobj);
    printf("The previous month is %s\n",month_name);
    int present_date=pres_date(dateobj);
    printf("The present date is %d\n",present_date);
    char *day_name;
    day_name=(char *)malloc(10*sizeof(char));
    day_name=present_day(dateobj);
    printf("The day is %s\n",day_name);
    int skipper;
    printf("Give the number of days to skip: \n");
    scanf("%d",&skipper);
    date_finder(dateobj,skipper);
    return 0;
}
