#include<iostream>
#include<vector>
using namespace std;

int minpathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    vector<int> dp(n, 0);
    dp[0] = grid[0][0];

    for(int i=1; i<n; i++) {
        dp[i] = dp[i-1]+grid[0][i]; 
    }

    for(int i=1; i<m; i++) {
        dp[0] += grid[i][0];
        for(int j=1; j<n; j++) {
            dp[j] = grid[i][j]+min(dp[j], dp[j-1]);
        }
    }

    return dp[n-1];
}

int main() {
    vector<vector<int>> grid = {{2, 8, 1,},
                                {10, 5, 100},
                                {6, 1, 10}};

    cout<<minpathSum(grid);
    return 0;
}