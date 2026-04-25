#include<iostream>
#include<vector>
using namespace std;

int fibonacci(int n) {
    if(n == 1 || n == 0) {
        return n;
    }

    return fibonacci(n-1)+fibonacci(n-2);
}

int fibonacci_DP(int n, vector<int>& DP) {
    if(n<=1) {
        return n;
    }
    if(DP[n] != -1) return DP[n];

    return DP[n] = fibonacci_DP(n-1, DP)+fibonacci_DP(n-2, DP);
}

int fibonacciTebulation(int n) {
    vector<int> dp(n+1, -1);
    dp[0] = 0, dp[1] = 1;
    
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}

int fib(int n) {
    if(n == 0) return 0;
    int pre1 = 0, pre2 = 1;

    for(int i=2; i<=n; i++) {
       int curr = pre1+pre2;

       pre1 = pre2;
       pre2 = curr;
    }

    return pre2;
}

int main() {
    int n = 10;

    
    for(int i=0; i<n; i++) {
        cout<<fib(i)<<endl;
    }
    return 0;
}