#include<iostream>
#include<vector>
using namespace std;

int kJump(vector<int>& height, int k) {
    int n = height.size();
    if(n == 1) return 0;
    vector<int> dp(n, INT32_MAX);
    dp[0] = 0;

    for(int i=1; i<n; i++) {
        for(int j=1; j<=k; j++) {
            if(i-j >= 0) {
                int cost = abs(height[i] - height[i-j]);
                dp[i] = min(dp[i], dp[i-j]+cost);
            }
        }
    }

    return dp[n-1];
}

int main() {
    vector<int> height = {10, 30, 50, 20, 10, 70, 70, 30};

    cout<<kJump(height, 3);
    return 0;
}
