#include<iostream>
#include<vector>
using namespace std;

int countWayToNthStair_DP(int n) {
    vector<int> dp(n+1);
    dp[0] = 1, dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}

int countWay(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }

    int prev1 = 1;
    int prev2 = 1;

    for(int i=2; i<=n; i++) {
        int curr = prev1+prev2;

        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}

int main() {
    int n = 10;

    for(int i=0; i<=n; i++) {
        cout<<countWay(i)<<"  ";
    }
    cout<<endl;
    return 0;
}