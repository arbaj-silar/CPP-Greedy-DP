#include<iostream>
#include<vector>
using namespace std;

bool jumpGame(vector<int>& jump) {
    int maxIdx = 0;

    for(int i=0; i<jump.size(); i++) {
        if(i>maxIdx) return false;

        maxIdx = max(maxIdx, i+jump[i]);
    }

    return true;
}

int main() {
    vector<int> jump = {2, 3, 1, 0, 4};

    cout<<"Reaching End: "<<jumpGame(jump)<<endl;
    return 0;
}