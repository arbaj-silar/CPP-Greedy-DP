#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Job {

public:
    char id;
    int deadline, profit;

    Job(char id, int deadline, int profit) {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

pair<int, int> jobScheduling(vector<Job> jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for(Job j: jobs) {
        maxDeadline = max(maxDeadline, j.deadline);
    }

    vector<int> slot(maxDeadline+1, -1);

    int countJobs = 0, totalProfit = 0;
    for(Job j: jobs) {
        for(int k=j.deadline; k>=1; k--) {
            if(slot[k] == -1) {
                slot[k] = j.id;
                countJobs++;
                totalProfit += j.profit;
                break;
            }
        } 
    }
    for(int i=1; i<slot.size(); i++) {
        if(slot[i] != -1) {
            cout<<(char)slot[i]<<" ";
        }
    }
    
    cout<<endl;

    return {countJobs, totalProfit};
}

int main() {
    vector<Job> jobs = {
        Job('A', 2, 100),
        Job('B', 1, 19),
        Job('C', 2, 27),
        Job('D', 1, 25),
        Job('E', 3, 15)
    };

    pair<int, int> res = jobScheduling(jobs);

    cout<<"Number Of Job: "<<res.first<<endl;
    cout<<"Total Profit: "<<res.second<<endl;

    return 0;
}