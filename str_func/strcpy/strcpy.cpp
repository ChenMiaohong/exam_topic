#include<stdio.h>
#include<stdlib.h>
char * my_strcpy(char *dest,const char *src){
    char *temp=dest;
    while(*temp++=*src++);
    return (temp-1);

}

int main()
{
    char *a="hello world";
    char *b=(char *)malloc(100);
    my_strcpy(b,a);
    puts(b);
}
