#include <iostream>
#include <vector>
using namespace std;

// Knapsack by Dynamic Programming
// Time Complexity : O(n*w)
// Space Complexity : O(n*w)

int knapsack(int n, vector<int> profits, vector<int> weights, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    
    // Initialize 1st row by 0, as bag is full
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    
    // Intialize 1st column by 0, as no items are left for picking
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // Case 1 : Pick current item and put it in bag
            if (j >= weights[i - 1])
            {
                dp[i][j] = max(dp[i][j], profits[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }

            // Case 2 : Don't pick current item
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    
    // Return calculated maximum profit possible
    return dp[n][m];
}

int main()
{
    // Items with their profits and weights
    int n = 3;
    vector<int> profits = {60, 100, 120};
    vector<int> weights = {10, 20, 30};

    // Maximum weight the bag can hold
    int m = 50;

    // Invoke knapsack by Dynamic Programming function to calculate maximum profit possible with bag of size w
    cout << "Max Profit : " << knapsack(n, profits, weights, m) << endl;

    return 0;
}