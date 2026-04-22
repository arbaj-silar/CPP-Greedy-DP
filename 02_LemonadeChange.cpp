#include<iostream>
#include<vector>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;

    for(int bill: bills) {
        if(bill == 5) {
            five++; 
        } else if(bill == 10) {
            if(five == 0) {
                return false;
            }

            five--;
            ten++;
        } else {
            if(five > 0 && ten > 0) {
                ten--;
                five--;
            } else if(five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};

    cout<<"Can give Change: "<<lemonadeChange(bills)<<endl;
    return 0;
}