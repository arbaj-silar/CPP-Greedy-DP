#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double fractionalKnapsack(vector<vector<int>> &items, int capacity)
{
   sort(items.begin(), items.end(), [](const vector<int> &a, const vector<int> &b)
         {
             double r1 = (double)a[0] / a[1]; 
             double r2 = (double)b[0] / b[1]; 
             return r1 > r2;                  
         });

    double totalValue = 0.0;

    for (auto &item : items)
    {
        int value = item[0];
        int weight = item[1];

        if (capacity == 0)
            break; 

        if (weight <= capacity)
        {
            totalValue += value;
            capacity -= weight;
        }
        else
        {
            totalValue += value * ((double)capacity / weight);
            capacity = 0;
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<vector<int>> items = {{100, 20}, {200, 50}, {60 , 10}, {200, 50}};
    int capacity = 90;

    cout<<"Tatal value: "<<fractionalKnapsack(items, capacity)<<endl;
    return 0;
}