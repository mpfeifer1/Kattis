#include <bits/stdc++.h>

using namespace std;

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int t = 3*n1 + 2*n2 + 1*n3;

    vector<string> ans;

    if(t >= 8) {
        ans.push_back("Province");
    }
    else if(t >= 5) {
        ans.push_back("Duchy");
    }
    else if(t >= 2) {
        ans.push_back("Estate");
    }

    if(t >= 6) {
        ans.push_back("Gold");
    }
    else if(t >= 3) {
        ans.push_back("Silver");
    }
    else if(t >= 0) {
        ans.push_back("Copper");
    }

    if(ans.size() == 1) {
        cout << ans[0] << endl;
    }
    else {
        cout << ans[0] << " or " << ans[1] << endl;
    }
}
