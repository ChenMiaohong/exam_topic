#include<iostream>
using namespace std;
int main()
{
    int m,i;
    int a=1;
    i=0;
    cin>>m;
    while(m>0)
    {
        if(m%2==1)
            a|=1<<i;
        else
            a&=0<<i;
        ++i;
        m/=2;
    }
    for (int i=sizeof(int)*8-1;i>=0;i--)
        {
            int mask=1<<i;//¶þ½øÖÆÑÚÂë
            if (mask & a)
                cout<<"1";
            else
                cout<<"0";
            if(i%8==0)
                cout<<" ";
        }
}
