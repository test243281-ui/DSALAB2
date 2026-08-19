#include<bits/stdc++.h>
using namespace std;
int main ()
{
    vector<int> nums = {4, 2, 1, 10};
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = max(nums[0], 0);
    for(int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    cout << dp[n] << endl;
}