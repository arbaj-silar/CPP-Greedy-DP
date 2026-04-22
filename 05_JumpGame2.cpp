#include<iostream>
#include<vector>
using namespace std;

int jumpProblem(vector<int>& nums) {
    if(nums.size() == 1) return 0;

    int jumps = 0, currEnd = 0;
    int farthest = 0;

    for(int i=0; i<nums.size(); i++) {
        farthest = max(farthest, i+nums[i]);

        if(i == currEnd) {
            jumps++;
            currEnd = farthest;

            if(currEnd >= nums.size()-1) break;
        }
    }

    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 4, 1, 1, 1, 2};

    cout<<"Minimum jumps: "<<jumpProblem(nums);
    return 0;
}