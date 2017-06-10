#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void strToNums(string s, vector<string>& nums, int n) {
    for(int i = 0; i < n; i++) {
        nums[i].push_back(s[i*4]);
        nums[i].push_back(s[i*4+1]);
        nums[i].push_back(s[i*4+2]);
    }
}

int main() {
    map<string, int> m = {
        {"**** ** ** ****", 0},
        {"  *  *  *  *  *", 1},
        {"***  *****  ***", 2},
        {"***  ****  ****", 3},
        {"* ** ****  *  *", 4},
        {"****  ***  ****", 5},
        {"****  **** ****", 6},
        {"***  *  *  *  *", 7},
        {"**** ***** ****", 8},
        {"**** ****  ****", 9}};

    vector<string> nums;

    string s;
    getline(cin, s);

    int n = s.length() / 4 + 1;
    nums.resize(n, "");

    strToNums(s, nums, n);

    for(int i = 0; i < 4; i++) {
        getline(cin, s);
        strToNums(s, nums, n);
    }

    int num = 0;
    for(auto str : nums) {
        if(m.count(str) < 1) {
            cout << "BOOM!!" << endl;
            return 0;
        }
        num *= 10;
        num += m.find(str)->second;
    }

    if(num % 6 == 0) {
        cout << "BEER!!" << endl;
        return 0;
    }

    cout << "BOOM!!" << endl;
}
