#include<iostream>
#include<vector>
using namespace std;

int frogJump(vector<int>& height) {
    int n = height.size(); 
    vector<int> dp(n+1, INT32_MAX);
    dp[1] = 0;

    for(int i=2; i<=n; i++) {
        int oneStep = dp[i-1] + abs(height[i-1] - height[i-2]);
        int twoStep= INT32_MAX;
        if(i>2) {
            twoStep = dp[i-2] + abs(height[i-1]-height[i-3]);
        }

        dp[i] = min(oneStep, twoStep);
    }

    return dp[n];
}

int f(int idx, vector<int>& height, vector<int>& dp) {
    if(idx == 0) return 0;
    if(dp[idx] != -1) return dp[idx];

    int oneStep = f(idx-1, height, dp) + abs(height[idx]-height[idx-1]);
    int twoStep = INT32_MAX;
    if(idx > 1) {
        twoStep = f(idx-2, height, dp)+ abs(height[idx]-height[idx-2]);
    }

    return dp[idx] = min(oneStep, twoStep);
}

int frog(vector<int>& height) {
    int n = height.size();
    vector<int> dp(n+1, -1);

    return f(n-1, height, dp);
}

int newFrog(vector<int>& height) {
    int n = height.size();
    if(n <= 1) return 0;
    if(n == 2) return abs(height[1]-height[0]);

    int prev = 0, prev1 = abs(height[1]-height[0]);

    for(int i=3; i<=n; i++) {
        int curr = min(prev1 + abs(height[i-1] - height[i-2]),
                         prev + abs(height[i-1]-height[i-3]));

        prev = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    vector<int> height = {30, 10, 30, 10, 60, 50};

    cout<<newFrog(height);
    return 0;
}