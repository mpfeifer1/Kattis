#include <bits/stdc++.h>
using namespace std;

int main() {
    string word;
    string perm;
    cin >> word >> perm;
    int wrong = 0;
    set<char> st;
    for(char c : word) {
        st.insert(c);
    }
    for(char c : perm) {
        if(st.count(c)) {
            st.erase(c);
            if(st.empty()) {
                cout << "WIN\n";
                return 0;
            }
        } else {
            ++wrong;
            if(wrong == 10) {
                cout << "LOSE\n";
                return 0;
            }
        }
    }
    cout << "WIN\n";
}


