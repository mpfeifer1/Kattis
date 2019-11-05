#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    string P, S;
    cin >> P >> S;
    swap(P,S);

    set<string> alls;
    alls.insert(P);

    // Prepend
    for(int i = 0; i < 10; i++) {
        char c = '0' + i;
        string t = "";
        t += c;
        t += P;
        alls.insert(t);
    }

    // Append
    for(int i = 0; i < 10; i++) {
        char c = '0' + i;
        string t = P;
        t.push_back(c);
        alls.insert(t);
    }

    // Switch case
    string g = P;
    for(auto& i : g) {
        if(islower(i)) i = toupper(i);
        else if(isupper(i)) i = tolower(i);
    }
    alls.insert(g);

    if(alls.count(S) > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
