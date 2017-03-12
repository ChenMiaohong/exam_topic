#include<iostream>
#include<vector>
using namespace std;
vector ncount(10, 0);
vector dp(20, 0);
vector dp1(20,0);
//0~9999的情况
void solution1(int n){
    for (int j = n - 1; j >= 1; j--){
        for (int i = 1; i < 10; i++){
            for (int k = 0; k < 10; k++)
                ncount[k] += dp[j];
            ncount[i] += dp1[j];
        }
    }
    for (int i = 1; i < 10; i++)
        ncount[i] += 1;
}
//0000~9999的情况
void solution2(int n){
    if (n<10){
        for (int i = 0; i <= n; i++)
            ncount[i]++;
        return;
    }
    int count = 0, m, k;
    k = 1;
    m = n;
    while (n>=10){
        n = n / 10;
        count++;
        k *= 10;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++)
            ncount[j] += dp[count];
        ncount[i] += dp1[count];
    }
    int tt = m%k;
    int yy = k / 10;
    if (tt == 0){
        for (int i = 0; i < count; i++)
            ncount[0]++;
    }
    count = 0;
    while (tt&& tt < yy){
        count++;
        tt = tt * 10;
    }
    if (count){
        ncount[0] += ((m%k) + 1)*count;
    }
    ncount[n] += m - n*k + 1;
    if (m%k)
    solution2(m%k);
}
void solution(int n){
    int count = 0, m, k;
    m = n;
    k = 1;
    while (n >= 10){
        n = n / 10;
        count++;
        k *= 10;
    }
    for (int i = 1;  i < n; i++){
        for (int j = 0; j < 10; j++)
            ncount[j] += dp[count];
        ncount[i] += k;
    }
    solution1(count);
    int tt = m%k;
    int yy = k / 10;
    if (tt == 0)
        for (int i = 0; i < count; i++)
            ncount[0]++;
    count = 0;
    while (tt&& tt < yy){
        count++;
        tt = tt * 10;
    }
    if (count){
        ncount[0] += ((m%k) + 1)*count;
    }
    ncount[n] += m - n*k + 1;
    if (m%k)
        solution2(m%k);
}
int main(){
    int n, k;
    cin >> n;
    dp[1] = 1;
    k = 1;
    //0~9中有0-9分别有1
    //00~99中有0-9分别有20
    //000~999中有0-9分别有300
    for (int i = 2; i < 20; i++){
        k = k * 10;
        dp[i] = 10 * dp[i - 1] + k;
    }
    k = 1;
    for (int i = 1; i < 10; i++){
        k *= 10;
        dp1[i] = k;
    }
    solution(n);
    cout << ncount[0];
    for (int i = 1; i < 10; i++)
        cout << " " << ncount[i];

}
