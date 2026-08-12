#include<bits/stdc++.h>
using namespace std;

vector<int> dp(1000000,-1); // Initialize a vector for memoization with -1
int fibonacci(int n)
{
    if(dp[n]!=-1) return dp[n];
    int res=fibonacci(n-1)+fibonacci(n-2);
    dp[n]=res;
    return res;
}
int main ()
{
dp[0]=0;
dp[1]=1;
cout<< fibonacci(20)<<endl; // Output the 20th Fibonacci number
}