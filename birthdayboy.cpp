#include <bits/stdc++.h>

using namespace std;

struct date {
    int m, d;
};

bool operator<(const date& d1, const date& d2) {
    if(d1.m == d2.m) {
        return d1.d < d2.d;
    }
    return d1.m < d2.m;
}

bool operator==(const date& d1, const date& d2) {
    return (d1.m == d2.m) && (d1.d == d2.d);
}

int main() {
    vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

    set<date> all;
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < days[i]; j++) {
            date d;
            d.m = i+1;
            d.d = j+1;
            all.insert(d);
        }
    }

    set<date> coworker;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        date d;
        cin >> d.m;
        cin.ignore();
        cin >> d.d;
        coworker.insert(d);
    }


    int ans = 0;
    set<date> best;

    // for each start point
    for(auto i : all) {
        auto it = all.find(i);
        if(coworker.count(i)) {
            continue;
        }

        int dayswithout = 0;

        while(true) {
            it = next(it);
            if(it == all.end()) {
                it = all.begin();
            }
            date d = *(it);

            if(coworker.count(d)) {
                break;
            }

            // process here
            dayswithout++;
            if(dayswithout > ans) {
                best.clear();
            }
            if(dayswithout >= ans) {
                ans = dayswithout;
                best.insert(d);
            }

            if(d == i) {
                break;
            }
        }

    }

    auto d1 = best.lower_bound({10,28});
    auto d2 = best.begin();
    date d;
    if(d1 != best.end()) {
        d = *d1;
    }
    else {
        d = *d2;
    }

    if(d.m < 10) cout << "0";
    cout << d.m;
    cout << "-";
    if(d.d < 10) cout << "0";
    cout << d.d;
    cout << endl;
}
