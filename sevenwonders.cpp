#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
    
    sort(str.begin(), str.end());
    
    int t = 0, c = 0, g = 0;
    t = count(str.begin(), str.end(), 'T');
    g = count(str.begin(), str.end(), 'G');
    c = count(str.begin(), str.end(), 'C');

    int sum = min(min(t, c), g) * 7;
    sum += pow(t, 2) + pow(g, 2) + pow(c, 2);

    cout << sum << endl;
}
