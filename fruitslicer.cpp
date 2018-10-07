#include <bits/stdc++.h>

using namespace std;
#define eps 0.00000001

typedef long double ld;

ld linePointDistSqr(ld x1, ld y1, ld dirX, ld dirY, ld x, ld y) {
    ld segLen = dirX*dirX + dirY*dirY;
    ld proj = dirX*(x-x1) + dirY*(y-y1);
    proj /= segLen;

    ld projX = dirX*proj + x1;
    ld projY = dirY*proj + y1;

    ld result = (x-projX)*(x-projX) + (y-projY)*(y-projY);

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<pair<ld, ld> > arr(n);
    map<pair<ld, ld>, int> cnts;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
        cnts[{arr[i].first, arr[i].second}]++;
    }
    vector<pair<pair<ld, ld>, int> > arr2;
    for(auto &p : cnts) {
        //cout << "pushing: " << p.first.first << ' ' << p.first.second << ' ' << p.second << '\n';
        arr2.push_back(p);
    }
    if(arr2.size() == 1) {
        cout << n << '\n';
        return 0;
    }
    int largest = 2;
    n = arr2.size();
    for(int i = 0; i < n; ++i) {
        ld x1 = arr2[i].first.first;
        ld y1 = arr2[i].first.second;
        for(int j = i+1; j < n; ++j) {
            ld x2 = arr2[j].first.first;
            ld y2 = arr2[j].first.second;

            ld offsetX = x2-x1;
            ld offsetY = y2-y1;

            swap(offsetX, offsetY);
            offsetY = -offsetY;

            //normalize offset here

            ld sqrMag = offsetX*offsetX + offsetY*offsetY;

            ld mag = sqrtl(sqrMag);

            offsetX /= mag;
            offsetY /= mag;

            ld lineX = x1+offsetX;
            ld lineY = y1+offsetY;

            ld lineDirX = x2-x1;
            ld lineDirY = y2-y1;
            //test line
            int cnt = 0;
            for(int k = 0; k < n; ++k) {
                if(linePointDistSqr(lineX, lineY, lineDirX, lineDirY, arr2[k].first.first, arr2[k].first.second) <= 1 + eps) {
                    cnt += arr2[k].second;
                }
            }
            //cout << "1: " << cnt << '\n';
            largest = max(largest, cnt);


            lineX = x1-offsetX;
            lineY = y1-offsetY;

            //test line
            cnt = 0;
            for(int k = 0; k < n; ++k) {
                if(linePointDistSqr(lineX, lineY, lineDirX, lineDirY, arr2[k].first.first, arr2[k].first.second) <= 1 + eps) {
                    cnt += arr2[k].second;
                }
            }
            //cout << "2: " << cnt << '\n';
            largest = max(largest, cnt);





            ld midX = (x1+x2)/2;
            ld midY = (y1+y2)/2;

            ld h = sqrtl((x1-midX)*(x1-midX) + (y1-midY)*(y1-midY));

            ld theta = asin(1.0/h);

            ld theta2 = atan2(y2-y1, x2-x1);

            lineDirX = cos(theta2+theta);
            lineDirY = sin(theta2+theta);

            lineX = midX;
            lineY = midY;

            //test line
            cnt = 0;
            for(int k = 0; k < n; ++k) {
                if(linePointDistSqr(lineX, lineY, lineDirX, lineDirY, arr2[k].first.first, arr2[k].first.second) <= 1 + eps) {
                    cnt += arr2[k].second;
                }
            }
            //cout << "3: " << cnt << '\n';
            largest = max(largest, cnt);


            lineDirX = cos(theta2-theta);
            lineDirY = sin(theta2-theta);


            //test line
            cnt = 0;
            for(int k = 0; k < n; ++k) {
                if(linePointDistSqr(lineX, lineY, lineDirX, lineDirY, arr2[k].first.first, arr2[k].first.second) <= 1 + eps) {
                    cnt += arr2[k].second;
                }
            }
            //cout << "4: " << cnt << '\n';
            largest = max(largest, cnt);

        }
    }
    cout << largest << '\n';
    return 0;
}

