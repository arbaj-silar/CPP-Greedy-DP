#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    if (n == 0)
        return 0;

    vector<int> candies(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    
    int total = 0;
    for (int c : candies)
        total += c;
    return total;
}

int main() {
    vector<int> ratings = {0, 2, 4, 3, 2, 1, 1, 3, 5, 6, 4, 0, 0};

    cout<<"Minimum Candies: "<<candy(ratings)<<endl;
    return 0;
}