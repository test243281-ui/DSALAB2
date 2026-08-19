#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] + 1 < dp[i]) {
                dp[i] = dp[i - coin] + 1;
            }
        }
    }

    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 3, 4};
    int amount = 6;

    int result = coinChange(coins, amount);
    cout << "Minimum coins needed: " << result << endl;

    return 0;
}
