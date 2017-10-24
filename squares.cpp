#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct line {
    int top;
    int bot;
    bool negative;
    int x1;
    int y1;
    int x2;
    int y2;
};

pair<int, int> reduce(pair<int, int> key) {
    int div = __gcd(key.first, key.second);
    key.first /= div;
    key.second /= div;
    if(key.second < 0) {
        key.first *= -1;
        key.second *= -1;
    }
    return key;
}

void print(pair<int, int> p) {
    cout << p.first << "/" << p.second << endl;;
}

// "Hash" the slope
string slope_to_string(bool negative, pair<int, int> slope) {
    string s;
    if(negative) {
        s += '-';
    }
    else {
        s += '+';
    }

    if(slope.first == 0 || slope.second==0) {
        s[0] = '0';
    }

    s += '/';
    s += to_string(slope.first);
    s += '/';
    s += to_string(slope.second);
    return s;
}

int main() {
    int n;
    cin >> n;

    vector<line> v(n);
    for(auto& i : v) {
        cin >> i.x1 >> i.y1 >> i.x2 >> i.y2;
    }

    unordered_map<string, vector<line>> lines;
    unordered_map<string, string> reciprocals;



/************* INPUT *************/


    for(auto& i : v) {
        // Get top and bottom
        int top = i.y2 - i.y1;
        int bot = i.x2 - i.x1;

        // Get into lowest form
        if(top == 0) {
            bot = 1;
        }
        else if(bot == 0) {
            top = 1;
        }
        else {
            int div;
            while((div = __gcd(top, bot)) && div != 1) {
                top /= div;
                bot /= div;
            }
        }

        // Make sure both are positive
        bool negative = false;
        if(top < 0 && bot < 0) {
            negative = false;
        }
        else if(bot < 0) {
            negative = true;
        }
        else if(top < 0) {
            negative = true;
        }

        if(top < 0) {
            top = -top;
        }
        if(bot < 0) {
            bot = -bot;
        }

        // Add to lists
        string slope = slope_to_string(negative, {top, bot});
        string perp = slope_to_string(!negative, {bot, top});
        reciprocals[slope] = perp;
        reciprocals[perp] = slope;

        // Edit original line
        i.top = top;
        i.bot = bot;
        i.negative = negative;

        // Add line
        lines[slope].push_back(i);
    }

/************* LOOP *************/
    unordered_set<string> seen;
    int total = 0;
    for(auto i : lines) {
        // If already seen, skip
        if(seen.count(i.first) > 0) {
            continue;
        }

        // Mark these slopes as seen
        seen.insert(i.first);
        seen.insert(reciprocals[i.first]);

        vector<line> v1 = i.second;
        vector<line> v2 = lines[reciprocals[i.first]];

        // If either have less than two lines
        if(v1.size() < 2 || v2.size() < 2) {
            continue;
        }

        // Set up vectors of distance and intercepts
        vector<pair<int, int>> i1;
        vector<pair<int, int>> i2;
        vector<pair<int, int>> d1;
        vector<pair<int, int>> d2;

        // Order the lists correctly
        if(v1[0].top > v1[0].bot) {
            v1.swap(v2);
        }

/************* EDGE *************/
        // Edge case here where slope contains a zero
        if(v1[0].top == 0) {
            vector<int> int1;
            vector<int> int2;
            vector<int> dint1;
            vector<int> dint2;
            for(auto j : v1) {
                int1.push_back(j.y1);
            }
            for(auto j : v2) {
                int2.push_back(j.x1);
            }

            // Get all the distances
            for(int k = 0; k < int1.size(); k++) {
                for(int j = k+1; j < int1.size(); j++) {
                    dint1.push_back(abs(int1[k] - int1[j]));
                }
            }
            for(int k = 0; k < int2.size(); k++) {
                for(int j = k+1; j < int2.size(); j++) {
                    dint2.push_back(abs(int2[k] - int2[j]));
                }
            }

            map<int,int> m1;
            map<int,int> m2;

            for(auto i : dint1) {
                m1[i]++;
            }
            for(auto i : dint2) {
                m2[i]++;
            }

            for(auto i : m1) {
                total += i.second * m2[i.first];
            }

            continue;

        }

/************* ACTUAL *************/

        // Get slope
        pair<int, int> slope = {v1[0].top , v1[0].bot};
        if(v1[0].negative) {
            slope.first = -slope.first;
        }

        // Get all the intercepts
        for(int i = 0; i < v1.size(); i++) {
            pair<int,int> p = {v1[i].y1 * slope.second - slope.first * v1[i].x1, slope.second};
            p = reduce(p);
            i1.push_back(p);
        }
        swap(slope.first, slope.second);
        slope.first *= -1;
        for(int i = 0; i < v2.size(); i++) {
            pair<int,int> p = {v2[i].y1 * slope.second - slope.first * v2[i].x1, slope.second};
            p = reduce(p);
            i2.push_back(p);
        }

        // Get all the distances
        for(int k = 0; k < i1.size(); k++) {
            for(int j = k+1; j < i1.size(); j++) {
                pair<int, int> p = {abs(i1[k].first * i1[j].second - i1[k].second * i1[j].first), abs(i1[k].second * i1[j].second)};
                p = reduce(p);
                d1.push_back(p);
            }
        }
        for(int k = 0; k < i2.size(); k++) {
            for(int j = k+1; j < i2.size(); j++) {
                pair<int, int> p = {abs(i2[k].first * i2[j].second - i2[k].second * i2[j].first), abs(i2[k].second * i2[j].second)};
                p = reduce(p);
                d2.push_back(p);
            }
        }

        // Set up the modifier for weird angles
        pair<int, int> mod;
        mod = {v1[0].bot, v1[0].top};

        map<pair<int, int>, int> dist1;
        map<pair<int, int>, int> dist2;

        for(int i = 0; i < d1.size(); i++) {
            pair<int, int> key = {d1[i].first * mod.first, d1[i].second * mod.second};
            key = reduce(key);
            dist1[key]++;
        }
        for(int i = 0; i < d2.size(); i++) {
            dist2[d2[i]]++;
        }

        for(auto i : dist1) {
            total += i.second * dist2[i.first];
        }

    }

    cout << total << endl;
}
