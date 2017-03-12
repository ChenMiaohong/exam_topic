#include<iostream>
using namespace std;
int checkPrime(int m)
{
   int i,j;
    if(m<2)
        return -1;
    else
        for(i=2;i<=m/2;i++)
            if(m%i==0)
                return -1;
        return 1;
}
int outputPrime(int m)
{
    int i,j;
    for(i=2;i<=m;i++)
    {
        for(j=2;j<=i/2;j++)
        if(i%j==0)
        {
            break;
        }
        if((i/2+1)==j)
            cout<<i<<" ";
    }

    return 0;
}
int main()
{
    int i,j,m;
    cin>>m;
    //if(checkPrime(m)==1)
        //cout<<m<<endl;
    outputPrime(m);


}
