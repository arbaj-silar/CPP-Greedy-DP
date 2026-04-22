#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int sdj(vector<int>& bt) {
    sort(bt.begin(), bt.end());
    int time = 0, waitTm = 0;

    for(int i=0; i<bt.size(); i++) {
        waitTm += time;
        time += bt[i];
    }

    return waitTm/bt.size();
} 

int main() {
    vector<int> bt = {4, 3, 7, 1, 2};

    cout<<sdj(bt);
    return 0;
}