#include <stdio.h>
#include <stdlib.h>

int main()
{
    int testcases,k;
    printf("Enter the number of testcases :\n");
    
    scanf("%d",&testcases);
    for(k=0;k<testcases;k++)
    {
        int keystrokes,i,j;
        printf("Enter the number of keystrokes :\n");
        scanf("%d",&keystrokes);
        if(keystrokes<=6)
        {
            printf("The maximum A's that can be printed for %d keystrokes is %d\n",keystrokes,keystrokes);
            continue;
        }
        int *solution;
        solution=(int *)calloc(keystrokes,sizeof(int));
        for(i=1;i<=6;i++)
        {
            solution[i-1]=i;
        }
        
        //To find the break point after which ctrl+V are to be continuosly pressed ;breaker refers to break point position where ctrl+A followed by ctrl+C followed by ctrl+v is to be pressed
        
        for(i=7;i<=keystrokes;i++)
        {
            
            for(j=i-3;j>=1;j--)
            {
                int breaker=i-j-1;
                int optimalfinder=breaker*solution[j-1];
                    //printf("The optimal finder :%d\n",optimalfinder);
                if(optimalfinder>solution[i-1])
                {
                    solution[i-1]=optimalfinder;
                }
            }
        }
        /* The breakpoint solution of 7 are :
            A A ctrl+A ctrl+C ctrl+V ctrl+V ctrl+V  -> optimalfinder=8
            A A A ctrl+A ctrl+C ctrl+V ctrl+V   -> optimalfinder=9
            A A A A ctrl+A ctrl+C ctrl+V ->optimalfinder=8 
            A A A A A ctrl+A ctrl+C ctrl+V ->optimalfinder=9*/
        
        //------------SOLUTION---------------------------
        printf("The maximum As that can be printed using %d keystrokes is %d\n",keystrokes,solution[keystrokes-1]);
    }
    return 0;
}
