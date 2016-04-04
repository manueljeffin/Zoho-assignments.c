#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int numberofwords(char *string,int length)
{
    int k;
    int length1=0;
    for(k=0;k<length;k++)
    {
        if((string[k]==' ')||(string[k]=='\n'))
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
       if(!(((value>=65)&&(value<=90))||((value>=97)&&(value<=122))||((value>=48)&&(value<=57))||(string[k]==' ')||(string[k]=='\n')))
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
    int *duplicatecountcheck;
    wordstorage=(char **)malloc(100*sizeof(char *));
    countcheck=(int *)malloc(100*sizeof(int));
    flagship=(int *)malloc(100*sizeof(int));
    duplicatecountcheck=(int *)malloc(100*sizeof(int));
    for(k=0;k<100;k++)
    {
        wordstorage[k]=(char *)malloc(15*sizeof(char));
    }
    countcheck[0]=1;
    duplicatecountcheck[0]=1;
    flagship[0]=0;
    int i=0,j=0;
    for(k=0;k<length;k++)
    {
        if((string[k]==' ')||(string[k]=='\n'))
        {
            wordstorage[i][j]='\0';
            i++;
            j=0;
            countcheck[i]=1;
            duplicatecountcheck[i]=1;
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
                duplicatecountcheck[k]=duplicatecountcheck[k]+1;
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
    printf("\n");
    for(i=0;i<numberofwords;i++)
    {
        if((duplicatecountcheck[i]==1)&&(strcmp(wordstorage[i],"\0")!=0))
        {
            printf("The word %s occurs only one in the given file\n",wordstorage[i]);
        }
    }
    printf("\n");
    return;
}
void mostcommonletters(char *string,int length)
{
    int i,j;
    int value;
    int charactercounter[26]={0};
    int duplicatecharactercount[26]={0};
    int flagship[26];
    int temp;
    char tempchar;
    for(i=0;i<length-1;i++)
    {
        j=string[i]-'a';
        if((j<=25)&&(j>=0))
        {
            charactercounter[j]++;
            duplicatecharactercount[j]++;
            continue;
        }
        j=string[i]-'A';
        if((j<=25)&&(j>=0))
        {
            duplicatecharactercount[j]++;
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
    printf("\n");
    for(i=0;i<26;i++)
    {
        if(duplicatecharactercount[i]==0)
        {
            tempchar='a'+i;
            printf("The letter %c is not used in this file anywhere\n",tempchar);
        }
    }
    printf("\n");
    return;
}
void mostcommonfirstword(char *string,int length)
{
    int i,j,l,k;
    char **wordstorage;
    int *count;
    int *flagship;
    count=(int *)malloc(100*sizeof(int));
    flagship=(int *)malloc(100*sizeof(int));
    wordstorage=(char **)malloc(100*sizeof(char *));
    for(i=0;i<100;i++)
    {
        wordstorage[i]=(char *)malloc(15*sizeof(char));
    }
    i=0;
    for(k=0;k<length;k++)
    {
        if(string[k]=='\n')
        {
            count[i]=0;
            for(j=k+1,l=0;string[j]!=' ';j++,l++)
            {
                wordstorage[i][l]=string[j];
            }
            wordstorage[i][l]='\0';
            i++;
        }
    }
    int numberofwords;
    numberofwords=i;
    for(i=0;i<numberofwords;i++)
    {
        if(strcmp(wordstorage[i],"\0")==0)
        {
            continue;
        }
        for(j=i+1;j<numberofwords;j++)
        {
            if(strcmp(wordstorage[i],wordstorage[j])==0)
            {
                count[i]=count[i]+1;
                wordstorage[j]="\0";
            }
        }
    }
    for(i=0;i<numberofwords;i++)
    {
        flagship[i]=i;
    }
    int temp;
    for(i=0;i<numberofwords;i++)
    {
        for(j=i+1;j<numberofwords;j++)
        {
            if(count[i]<count[j])
            {
                temp=count[i];
                count[i]=count[j];
                count[j]=temp;
                temp=flagship[i];
                flagship[i]=flagship[j];
                flagship[j]=temp;
            }
        }
    }
    printf("The most common first word of the paragraphs is %s\n",wordstorage[flagship[0]]);
    printf("\n");
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
    printf("\nThe number of words is %d\n",noofwords);
    printf("\n");
    int noofletters;
    noofletters=numberofletters(string,length);
    printf("The number of valid letters is %d\n",noofletters);
    printf("\n");
    int alphanumerals;
    alphanumerals=numberofalphas(string,length);
    printf("The number of symbols is %d\n",alphanumerals);
    printf("\n");
    maximumusedwords(string,length);
    mostcommonletters(string,length);
    mostcommonfirstword(string,length);
    return 0;
}
