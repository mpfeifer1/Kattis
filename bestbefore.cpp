#include <bits/stdc++.h>

using namespace std;

vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

int isleap(int n, int m) {
    if(m != 2) {
        return false;
    }

    if(n % 400 == 0) {
        return 1;
    }
    if(n % 100 == 0) {
        return 0;
    }
    if(n % 4 == 0) {
        return 1;
    }
    return 0;
}

bool works(vector<int> v) {
    // If year too small
    if(v[0] < 2000) {
        v[0] += 2000;
    }

    // If month too large
    if(v[1] > 12) return false;

    // If day too large
    if(v[2] > days[v[1]-1] + isleap(v[0], v[1])) return false;

    return true;
}

string build(vector<int> v) {
    // Add in year
    if(v[0] < 2000) {
        v[0] += 2000;
    }
    string s = to_string(v[0]);
    s += "-";

    // Add in month
    if(v[1] < 10) {
        s += "0";
    }
    s += to_string(v[1]);
    s += "-";

    // Add in day
    if(v[2] < 10) {
        s += "0";
    }
    s += to_string(v[2]);
    return s;
}

int main() {
    // Read in input
    string s;
    cin >> s;

    // Process input
    stringstream ss(s);
    bool valid = true;
    vector<int> v(3);
    for(auto& i : v) {
        ss >> i;
        ss.ignore();
        // If any input too small
        if(i < 0) {
            valid = false;
        }
        if(i == 0) {
            i += 2000;
        }
    }
    sort(v.begin(), v.end());

    // Calculate all possible answers and sort them
    vector<string> answers;
    do {
        if(works(v)) {
            answers.push_back(build(v));
        }
        //answers.push_back(build(v));
    } while(next_permutation(v.begin(), v.end()));
    sort(answers.begin(), answers.end());

    // Print answer
    if(answers.size() == 0 || !valid) {
        cout << s << " is illegal" << endl;
    }
    else {
        cout << answers[0] << endl;
    }
}
