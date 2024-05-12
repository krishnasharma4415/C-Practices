#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool checkPalindrome(char *str)
{
    int len = strlen(str);
    for(int i=0,j=len-1;i<j;i++,j--)
    {
        if(str[i]!=str[j])
            return false;
    }
    return true;
}
bool recheckPalindrome(char *str)
{
    int len = strlen(str);
    char revstr[len];
    for(int i=0,j=len-1;i<len,j>=0;i++,j--)
    {
        revstr[i]=str[j];
    }
    if(strcmp(str,revstr)==0)
        return true;
    return false;
}
int main()
{
    char str[100];
    printf("Enter the String: ");
    gets(str);
    bool check = checkPalindrome(str);
    bool recheck = recheckPalindrome(str);
    printf("check: %d recheck: %d",check,recheck);
    return 0;
}