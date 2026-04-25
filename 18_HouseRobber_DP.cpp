#include<iostream>
#include<vector>
using namespace std;

int maxNonAdjecentSum(vector<int>& arr) {
    int n = arr.size();
    if(n == 0) return 0;
    if(n == 1) return arr[0];

    int prev2 = arr[0];
    int prev1 = max(arr[0], arr[1]);

    for(int i=2; i<n; i++) {
        int pick = arr[i]+prev2;
        int curr = max(pick, prev1);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int maxSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n+1, 0);
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);

    for(int i=3; i<=n; i++) {
        int pick = arr[i-1]+dp[i-2];
        dp[i] = max(pick, dp[i-1]);
    }

    return dp[n];
}

int main() {
    vector<int> arr = {2, 1, 4, 9};

    cout<<maxSum(arr)<<endl;
    return 0;
}