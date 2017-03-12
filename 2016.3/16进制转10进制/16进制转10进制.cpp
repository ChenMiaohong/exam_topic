#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int hex_char_value(char c)
{
    int m;
    if(c>='0'&&c<='9')
        m=c-'0';
    else if(c>='a'&&c<='z')
        m=(c-'a'+10);
    else if(c>='A'&&c<='Z')
        m=(c-'A'+10);
    return m;
}
int hex_str_value(const char *hex,int len)
{
    int result=0;
    int i,j;
    for(i=0;i<len;i++)
    {
        result+=pow(16,i)*(hex_char_value(hex[i]));
    }
    return result;
}
int main()
{
     int m,n,j;
     char s[1024];
     //gets(s);
     n=strlen(s);
     m=hex_str_value(s,n);
     //cout<<m;
     sscanf()
}
