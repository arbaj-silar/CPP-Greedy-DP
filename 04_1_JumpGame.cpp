#include<iostream>
#include<vector>
using namespace std;

int jumpProblem(vector<int>& nums, int i, int jums, int currEnd, int farthest) {
    if(currEnd >= nums.size()-1) return jums;

    farthest = max(farthest, i+nums[i]);

    if(i == currEnd) {
        return jumpProblem(nums, i+1, jums+1, farthest, farthest);
    }   
    return jumpProblem(nums, i+1, jums, currEnd, farthest);
}

int main() {
    vector<int> nums = {2, 3, 1, 4, 1, 1, 1, 2};
    
    cout<<jumpProblem(nums, 0, 0, 0, 0);
    return 0;
}