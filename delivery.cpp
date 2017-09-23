#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long solve(vector<pair<long long, long long>>& v, long long letters) {
    long long lettersleft = letters;
    long long traveled = v[v.size()-1].first * 2;
    for(int i = v.size()-1; i >= 0; i--) {
        if(lettersleft >= v[i].second) {
            lettersleft -= v[i].second;
            v.pop_back();
        }
        else {
            v[i].second -= lettersleft;
            break;
        }
    }
    return traveled;
}

int main() {
    long long stops, letters;
    cin >> stops >> letters;

    vector<pair<long long, long long>> v_pos;
    vector<pair<long long, long long>> v_neg;

    for(int i = 0; i < stops; i++) {
        long long dist, l;
        cin >> dist >> l;

        if(dist < 0) {
            v_neg.push_back({-dist, l});
        }
        else {
            v_pos.push_back({dist, l});
        }
    }

    sort(v_neg.begin(), v_neg.end());
    sort(v_pos.begin(), v_pos.end());

    long long total = 0;

    while(v_neg.size() > 0) {
        total += solve(v_neg, letters);
    }
    while(v_pos.size() > 0) {
        total += solve(v_pos, letters);
    }

    cout << total << endl;
}
