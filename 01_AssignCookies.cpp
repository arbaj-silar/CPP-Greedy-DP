#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

// Greedy Approach
int assignCookies(vector<int>& need, vector<int>& cookie) {
    sort(need.begin(), need.end());
    sort(cookie.begin(), cookie.end());
    int l = 0, r = 0;

    while(l<cookie.size() && r<need.size()) {
        if(need[r] <= cookie[l]) {
            r++;
        }

        l++;
    }

    return r;
}

int main() {
    vector<int> cookie = {4, 2, 1, 2, 1, 3};
    vector<int> need = {1, 5, 3, 3, 4};

    cout<<"Satisfied Kid: "<<assignCookies(need, cookie)<<endl;
}