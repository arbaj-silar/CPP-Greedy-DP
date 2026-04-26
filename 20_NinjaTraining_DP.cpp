#include<iostream>
#include<vector>
using namespace std;

int ninjaTraining(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    
    for(int i=1; i<n; i++) {
        dp[i][0] = points[i][0]+max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = points[i][1]+max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = points[i][2]+max(dp[i-1][0], dp[i-1][1]);
    }

    return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}

int ninja(vector<vector<int>>& points) {
    int n = points.size();
    vector<int> prev(3, 0);

    prev[0] = points[0][0];
    prev[1] = points[0][1];
    prev[2] = points[0][2];

    for(int i=1; i<n; i++) {
        vector<int> temp(3, 0);

        for(int j=0; j<3; j++) {
            int maxPrev = 0;
            for(int k = 0; k<3; k++) {
                if(k != j) {
                    maxPrev = max(maxPrev, prev[k]);
                }
            }
            temp[j] = points[i][j]+maxPrev;
        }

        prev = temp;
    }

    return max(prev[0], max(prev[1], prev[2]));
}

int main() {
    vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};

    cout<<ninja(points)<<endl;
    return 0;
}