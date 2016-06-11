#include <iostream>
using namespace std;

// calculate the number of ways to make amount with elements in coins[]
int permutation(int coins[], int n, int amount){
    int dp[n+1][amount+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= amount; j ++){
            int times = j / coins[i-1];
            dp[i][j] = 0;
            for (int k = 0; k <= times; k++){
                dp[i][j] += dp[i-1][j - k*coins[i-1]];
            }
        }
    }
    return dp[n][amount];
}



int main(int argNum, char *args[]){
    int coins[6] = {5, 10, 20, 50, 100, 200};
    int n = 6;
    int amount = 400;
    int ways = permutation(coins, n, amount);
    cout << "ways: "<< ways<<endl;

    return 0;
}