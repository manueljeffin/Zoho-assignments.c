# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int testcases,k;
    printf("Enter the number of testcases :\n");
    
    scanf("%d",&testcases);
    for(k=0;k<testcases;k++)
    {
        int keystrokes;
        int solution=0;
        int finisher;
        printf("Enter the number of keystrokes :\n");
        
        scanf("%d",&keystrokes);
        
        while(keystrokes>0)
        {
            if((keystrokes>3)&&(solution<3))
            {
                finisher=solution;
                solution=3;
                keystrokes=keystrokes-3;
                continue;
            }
            if((solution<3)&&(keystrokes<=3))
            {
                solution=keystrokes;
                break;
            }
            if((solution>=3)&&(keystrokes>=4))
            {
                finisher=solution;
                solution=solution+solution*2;
                keystrokes=keystrokes-4;
                continue;
            }
            if((solution>3)&&(keystrokes<4))
            {
                solution=solution+finisher*keystrokes;
                break;
            }
            if((solution==3)&&(keystrokes<4))
            {
                solution=solution+keystrokes;
                break;
            }
        }
        
        //------------SOLUTION---------------------------
        printf("The maximum number of A's that can be printed using the given keystrokes is : %d\n",solution);
    }
    return 0;
}
