#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll n, q;
ll v[5000005];

void update(ll* v, ll index, ll value) {
    index++;
    while(index < n+5) {
        v[index] += value;
        index += index & (-index);
    }
}

ll sum(ll* v, ll index) {
    ll total = v[0];
    while(index > 0) {
        total += v[index];
        index -= index & (-index);
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    scanf("%lld%lld\n", &n, &q);
    for(int i = 0; i < n+5; i++) {
        v[i] = 0;
    }

    ll index, value;
    for(ll i = 0; i < q; i++) {
        char op;
        scanf("%c", &op);

        if(op == '+') {
            scanf("%lld%lld\n", &index, &value);
            update(v, index, value);
        }
        if(op == '?') {
            scanf("%lld\n", &index);
            printf("%lld\n", sum(v, index));
        }
    }
}
