#include<iostream>
#include<vector>
using namespace std;

int paths(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp) {
    if(i >= 0 && j>= 0 && arr[i][j] == -1) return 0;
    if(i == 0 && j == 0) return 1;
    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = paths(i-1, j, arr, dp)+paths(i, j-1, arr, dp);
}

int fun(vector<vector<int>>& arr) {
    int m = arr.size(), n = arr[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return paths(m-1, n-1, arr, dp);
}

int main() {
    vector<vector<int>> arr = {{0, 0, 0, 0},
                             {-1, 0, -1, 0},
                             {0, 0, -1, 0},
                             {-1, 0, 0, 0}};
            
    cout<<fun(arr);
    return 0;
}