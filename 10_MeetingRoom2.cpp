#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPlatform(vector<int> &arrival, vector<int> &departure)
{
    int n = arrival.size();

    // Sort both arrays
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int platforms = 0;
    int maxPlatforms = 0;
    int i = 0, j = 0; 

    while (i < n && j < n)
    {
        if (arrival[i] <= departure[j])
        {
            platforms++;
            i++;
        }
        else
        {
            platforms--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
    }

    return maxPlatforms;
}

int main() {
    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

    cout<<"Minimum Platform: "<<findPlatform(arrival, departure);
    return 0;
}