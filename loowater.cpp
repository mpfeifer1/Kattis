#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k, h;
    while(cin >> h >> k && k != 0 && h != 0) {
        vector<int> knights;
        vector<int> heads;

        for(int i = 0; i < h; i++) {
            int temp;
            cin >> temp;
            heads.push_back(temp);
        }

        for(int i = 0; i < k; i++) {
            int temp;
            cin >> temp;
            knights.push_back(temp);
        }

        int total = 0;
        sort(knights.begin(), knights.end());
        sort(heads.begin(), heads.end());

        while(knights.size() > 0 && heads.size() > 0) {
            if(knights[0] >= heads[0]) {
                heads.erase(heads.begin());
                total += knights[0];
            }
            knights.erase(knights.begin());
        }

        if(heads.size() > 0) {
            cout << "Loowater is doomed!" << endl;
        }
        else {
            cout << total << endl;
        }
    }
}
