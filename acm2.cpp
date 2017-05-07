#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> v;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int currentTime = 0;
    int timeTaken = 0;

    if(v[p] >= 300) {
        cout << "0 0" << endl;
        return 0;
    }

    currentTime = v[p];
    timeTaken = v[p];

    v.erase(v.begin() + p);
    sort(v.begin(), v.end());

    int solved;
    for(int i = 0; i < v.size(); i++) {
        solved = i;
        currentTime += v[i];
        if(currentTime > 300) {
            cout << i + 1 << " " << timeTaken << endl;
            return 0;
        }
        timeTaken += currentTime;
    }

    cout << solved + 2 << " " << timeTaken << endl;
}
