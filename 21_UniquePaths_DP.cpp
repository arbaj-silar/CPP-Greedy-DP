#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int i, int j) {
    if(i == 0 & j == 0) return 1;
    if(i < 0 || j < 0) return 0;

    return uniquePaths(i-1, j)+uniquePaths(i, j-1);
}

int paths(int i, int j) {
    int total = i+j-2;
    int down = i-1;
    if(down > total -down) down = total-down;

    int res = 1;
    for(int k =1; k<=down; k++) {
        res = res * (total-down+k);
    }
    return res;
}

int pathDP(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for(int i=1; i<m; i++) {
        for(int j = 1; j<n; j++) {
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

int uniqueDP(int m, int n) {
    vector<int> dp(n, 1);

    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            dp[j] = dp[j]+dp[j-1];
        }
    }

    return dp[n-1];
}

int main() {
    cout<<paths(3, 7)<<endl;

    return 0;
}