#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

ld wedge(pair<ld, ld> &i, pair<ld, ld> &j) {
    return (i.first * j.second) - (i.second * j.first);
}

ld area(vector<pair<ld,ld>>& points) {
    ld total = 0;
    for(int i = 0; i < points.size(); i++) {
        int j = (i + 1) % points.size();
        total += (points[i].first * points[j].second) - (points[i].second * points[j].first);
    }
    return total / 2.0;
}

vector<ld> fact;
ld choose(int n, int k) {
    if(n < 0 || k > n || k < 0) return 0;
    return fact[n]/fact[k]/fact[n-k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    fact.resize(n+1);
    fact[0] = 1;
    for(int i = 1; i <= n; ++i) {
        fact[i] = i*fact[i-1];
    }
    vector<pair<ld, ld>> poly(n);
    for(int i = 0; i < n; ++i) {
        ld x, y;
        cin >> x >> y;
        poly[i] = {x,y};
    }
    vector<vector<ld>> pick(n+1, vector<ld>(n+1, 1));
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            pick[i][j] = j*pick[i][j-1];
        }
    }
    //pick[i][j] = j*(j-1)*(j-2)* ... * i

    //ld answer2 = 0;

    ld answer = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < i+n; ++j) {
            const int jj = j%n;
            const int numPoints = j-i-1;
            //cout << "here: " << i << ' ' << j << ' ' << numPoints << '\n';
            ld Wedge = wedge(poly[i], poly[jj]);

            //answer2 += choose(numPoints, k-2)*Wedge/choose(n,k);


            if(numPoints >= 1 && numPoints-k+2+1 >= 1 && n-k+1 >= 1) {

                int L1 = numPoints-k+2+1;
                int R1 = numPoints;

                int L2 = n-k+1;
                int R2 = n;
                bool swapped = false;
                if(L1 > L2) {
                    swap(L1, L2);
                    swap(R1, R2);
                    swapped = true;
                }

                ld temp = (ld)k*(k-1)*Wedge;

                ld num = 1;
                ld dem = 1;

                if(L2 <= R1) {
                    if(L1 <= L2-1)
                        num *= pick[L1][L2-1];
                    if(R1+1 <= R2)
                        dem *= pick[R1+1][R2];
                } else {
                    num *= pick[L1][R1];
                    dem *= pick[L2][R2];
                }

                if(swapped) swap(num, dem);

                temp *= num/dem;



                //ld temp = (ld)k*(k-1)*pick[numPoints-k+2+1][numPoints]/pick[n-k+1][n]*Wedge;
                //cout << "here: " << i << ' ' << j << " adding: " << temp << '\n';
                answer += temp;
            }
        }
    }
    //cout << setprecision(8) << fixed << "answer2: " << answer2 << '\n';
    cout << setprecision(8) << fixed << abs(answer/2.0) << '\n';
}
