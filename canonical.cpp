#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    vector<int> v;
    cin >> a;
    for(int i = 0; i < a; i++) {
        cin >> b;
        v.push_back(b);
    }

    for(int i = 1; i < a; i++) {
        if(v[i] < 2 * v[i-1]){
            int t = 2 * v[i-1];
            int count = 0;
            for(int j = v.size()-1; j >= 0; j--) {
                while(t-v[j] >= 0) {
                    t -= v[j];
                    count++;
                }
            }

            if(count > 2) {
                cout << "non-canonical" << endl;
                return 0;
            }
        }
    }
    cout << "canonical" << endl;

}
