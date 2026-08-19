#include<bits/stdc++.h>
using namespace std;
vector<int> dp(1000, -1);
int fib(int n)
{
    if(dp[n] != -1)
        return dp[n];
    if(n <= 1)
        return dp[n] = n;
    return dp[n] = fib(n - 1) + fib(n - 2);
}