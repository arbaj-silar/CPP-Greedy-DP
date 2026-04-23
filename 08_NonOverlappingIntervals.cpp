#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    if(a[0] == b[0])
    return a[1] < b[1];

    return  a[0]<b[0];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.empty()) return 0;

    sort(intervals.begin(), intervals.end(), compare);
    
    int count = 1;
    int end = intervals[0][1];

    for(int i=1; i<intervals.size(); i++) {
        if(intervals[i][0] >= end) {
            count++;
        }

        end = intervals[i][1];
    }

    return intervals.size()-count;
}

int main() {
    vector<vector<int>> intervals = {{1, 2}, {0, 5}, {3, 4}, {5, 9}, {5, 7}, {7, 9}};

    cout<<"Removal Needs: "<<eraseOverlapIntervals(intervals);
    return 0;
}