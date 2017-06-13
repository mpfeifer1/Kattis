#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool pairwise(string s1, string s2, string s3) {
    int same = 0;
    int diff = 0;

    for(int i = 0; i < 4; i++) {
        if(s1[i] == s2[i] && s2[i] == s3[i]) {
            same++;
        }
        if(s1[i] != s2[i] && s2[i] != s3[i] && s3[i] != s1[i]) {
            diff++;
        }
    }

    return (diff + same == 4);
}

int main() {
    vector<string> v;
    vector<string> ans;

    for(int i = 0; i < 12; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    for(int i = 0; i < 10; i++) {
        for(int j = i+1; j < 11; j++) {
            for(int k = j+1; k < 12; k++) {
                if(pairwise(v[i], v[j], v[k])) {
                    ans.push_back(to_string(i+1) + ' ' + to_string(j+1) + ' ' + to_string(k+1));
                }
            }
        }
    }

    for(auto s : ans) {
        cout << s << endl;
    }

    if(ans.size() == 0) {
        cout << "no sets" << endl;
    }
}
