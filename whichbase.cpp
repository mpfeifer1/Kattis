#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    for(ll j = 0; j < n; j++) {
        ll current, query;
        cin >> current >> query;

        cout << current << " ";

        ll querycopy = query;
        int total = 0;
        int i = 0;
        while(querycopy > 0) {
            if(querycopy % 10 > 7) {
                total = 0;
                querycopy = 0;
            }
            total += pow(8, i) * (querycopy%10);
            querycopy /= 10;
            i++;
        }
        cout << total << " ";

        cout << query << " ";

        querycopy = query;
        total = 0;
        i = 0;
        while(querycopy > 0) {
            total += pow(16, i) * (querycopy%10);
            querycopy /= 10;
            i++;
        }

        cout << total << endl;
    }
}
