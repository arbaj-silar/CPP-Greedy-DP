#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Meeting {
public:
    int start, end, index;

    Meeting(int s, int e, int idx) {
        start = s;
        end = e;
        index = idx;
    }
};

bool compare(Meeting a, Meeting b) {
    if(a.end == b.end) return a.start < b.start;

    return a.end < b.end;
}

int maxMeeting(vector<int>& start, vector<int>& end) {
    vector<Meeting> meeting;

    for(int i=0; i<start.size(); i++) {
        meeting.push_back(Meeting(start[i], end[i], i));
    }

    sort(meeting.begin(), meeting.end(), compare);
    
    vector<int> select;
    int lastEnd = -1, count = 0;

    for(Meeting m: meeting) {
        if(m.start > lastEnd) {
            select.push_back(m.index);
            lastEnd = m.end;
            count++;
        }
    }

    cout<<"Selected meeting indices: ";
    for(int i: select) {
        cout<<i<<" ";
    }
    cout<<endl;

    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout<<"Max Meeting: "<<maxMeeting(start, end)<<endl;
    return 0;
}