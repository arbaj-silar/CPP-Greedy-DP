#include<iostream>
#include<vector>
using namespace std;

int robLinear(vector<int> &nums, int st, int end) {
    int prev2 = 0, prev1 = 0;

    for(int i=st; i<=end; i++) {
        int curr = max(prev1, nums[i]+prev2);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int robCirculation(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];
    if(n == 2) return max(nums[1], nums[0]);

    int case1 = robLinear(nums, 0, n-2);
    int case2 = robLinear(nums, 1, n-1);

    return max(case1, case2);
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    cout<<robCirculation(nums);
    return 0;
}