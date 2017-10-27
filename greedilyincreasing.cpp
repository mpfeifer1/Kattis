#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for(auto& i : v) {
        cin >> i;
    }

    vector<int> line;
    line.push_back(v[0]);

    for(int i = 1; i < v.size(); i++) {
        if(v[i] > line[line.size()-1]) {
            line.push_back(v[i]);
        }
    }

    cout << line.size() << endl;
    for(auto i : line) {
        cout << i << " ";
    }
    cout << endl;
}
