# Zoho-assignments.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int numberofwords(char *string,int length)
{
    int k;
    int length1=0;
    for(k=0;k<length;k++)
    {
        if(string[k]==' ')
        {
            length1++;
        }
    }
    length1++;//for the end word
    return length1;
}
int numberofletters(char *string,int length)
{
    int k;
    int value;
    int letters=0;
    for(k=0;k<length;k++)
    {
        value=string[k];
        if(((value>=65)&&(value<=90))||((value>=97)&&(value<=122)))
        {
            letters++;
        }
    }
    return letters-1;
}
int numberofalphas(char *string,int length)
{
    int k;
    int value;
    int nonalphas=0;
    for(k=0;k<length;k++)
    {
        value=string[k];
       if(!(((value>=65)&&(value<=90))||((value>=97)&&(value<=122))||((value>=48)&&(value<=57))||(string[k]==' ')))
       {
           nonalphas++;
       }
    }
    return nonalphas;
}
void maximumusedwords(char *string,int length)
{
    int k;
    int numberofwords;
    char **wordstorage;
    int *countcheck;
    int *flagship;
    wordstorage=(char **)malloc(100*sizeof(char *));
    countcheck=(int *)malloc(100*sizeof(int));
    flagship=(int *)malloc(100*sizeof(int));
    for(k=0;k<100;k++)
    {
        wordstorage[k]=(char *)malloc(15*sizeof(char));
    }
    countcheck[0]=1;
    flagship[0]=0;
    int i=0,j=0;
    for(k=0;k<length;k++)
    {
        if(string[k]==' ')
        {
            wordstorage[i][j]='\0';
            i++;
            j=0;
            countcheck[i]=1;
            flagship[i]=i;
            continue;
        }
        wordstorage[i][j]=string[k];
        j++;
    }
    numberofwords=i+1;
    for(k=0;k<numberofwords;k++)
    {
        if(strcmp(wordstorage[k],"\0")==0)
        {
            continue;
        }
        for(j=k+1;j<numberofwords;j++)
        {
            if(strcmp(wordstorage[k],wordstorage[j])==0)
            {
                countcheck[k]=countcheck[k]+1;
                wordstorage[j]="\0";
            }
        }
    }
    int temp;
    for(i=0;i<numberofwords;i++)
    {
        for(j=i+1;j<numberofwords;j++)
        {
            if(countcheck[i]>countcheck[j])
            {
                temp=countcheck[i];
                countcheck[i]=countcheck[j];
                countcheck[j]=temp;
                temp=flagship[i];
                flagship[i]=flagship[j];
                flagship[j]=temp;
            }
        }
    }
    printf("The top three used words: \n");
    int value;
    for(i=0;i<3;i++)
    {
        value=flagship[numberofwords-1-i];
        printf("%d.%s and their count is %d\n",i+1,wordstorage[value],countcheck[numberofwords-1-i]);
    }
    return;
}
void mostcommonletters(char *string,int length)
{
    int i,j;
    int value;
    int charactercounter[26]={0};
    int flagship[26];
    int temp;
    char tempchar;
    for(i=0;i<length-1;i++)
    {
        j=string[i]-'a';
        if((j<=25)&&(j>=0))
        {
            charactercounter[j]++;
            continue;
        }
        j=string[i]-'A';
        if((j<=25)&&(j>=0))
        {
            charactercounter[j]++;
            continue;
        }
    }
    for(i=0;i<26;i++)
    {
        flagship[i]=i;
    }
    for(i=0;i<26;i++)
    {
        for(j=i+1;j<26;j++)
        {
            if(charactercounter[i]<charactercounter[j])
            {
                temp=charactercounter[i];
                charactercounter[i]=charactercounter[j];
                charactercounter[j]=temp;
                temp=flagship[i];
                flagship[i]=flagship[j];
                flagship[j]=temp;
            }
        }
    }
    printf("The most used letters are :\n");
    for(i=0;i<3;i++)
    {
        tempchar=flagship[i]+'a';
        printf("%d. %c and their count is %d\n",i+1,tempchar,charactercounter[i]);
    }
    return;
}
int main()
{
    FILE *fp;
    char a;
    int length;
    char *string;
    string=(char *)malloc(400*sizeof(char));
    fp=fopen("karthik.txt","r");
    int i=0;
    if(fp==NULL)
    {
        printf("File is not read");
        return 0;
    }
    else
    {
        printf("The file contains :");
        while(!feof(fp))
        {
            fscanf(fp,"%c",&a);
            printf("%c",a);
            string[i++]=a;
        }
        printf("\n");
    }
    length=i;
    int noofwords;
    noofwords=numberofwords(string,length);
    printf("The number of words is %d\n",noofwords);
    int noofletters;
    noofletters=numberofletters(string,length);
    printf("The number of valid letters is %d\n",noofletters);
    int alphanumerals;
    alphanumerals=numberofalphas(string,length);
    printf("The number of symbols is %d\n",alphanumerals);
    maximumusedwords(string,length);
    mostcommonletters(string,length);

    return 0;
}
