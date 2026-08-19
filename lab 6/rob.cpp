#include<bits/stdc++.h>
using namespace std;
int rob(vector<int>& nums, int n)
{
    if(n < 0)
        return 0;
   return max(rob(nums, n - 1), rob(nums, n - 2) + nums[n]);     
}
int main ()
{
    vector<int> nums = {4, 2, 1, 10};
    cout << rob(nums, nums.size() - 1) << endl;
}