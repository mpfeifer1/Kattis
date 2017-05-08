#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = max(b-a, c-b);
    ans--;

    cout << ans << endl;
}
