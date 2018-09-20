#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Define ant structure
struct ant {
    ll color, x;
    bool left;
};

// Sort ants by starting position
bool cmp(const ant &a, const ant &b) {
    return a.x < b.x;
}

int main() {
    // Fast IO
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Read in initial data
    ll n, k, l;
    cin >> n >> k >> l;

    // Double log length so we don't need to worry about loss of precision
    l *= 2;

    // Read in all the input
    vector<ant> arr(n);
    char dir;
    vector<ll> totalDist(k+2, 0);
    for(ll i = 0; i < n; ++i) {
        cin >> arr[i].x >> arr[i].color;
        arr[i].color %= k;
        arr[i].x *= 2;
        cin >> dir;
        arr[i].left = (dir == 'L');
    }

    // Sort the ants by start position
    sort(arr.begin(), arr.end(), cmp);

    // Calculate all ants that go right first
    for(ll i = 0; i < n; ++i) {
        if(!arr[i].left) {//right
            totalDist[arr[i].color] += (ll)(l-arr[i].x);
        }
    }

    // This array keeps track of all the values you will add as you go leftward
    deque<ll> soham(k, 0);

    // Define variables we need to keep track of as we process the ants
    ll prevLeftX = 0;
    ll sumColors = 0;
    ll firstLeft = -1;
    ll prevColor;

    // For each ant
    for(ll i = 0; i < n; ++i) {
        // If it's going right
        if(!arr[i].left) {
            // If it's the first one, set previous values, but don't process
            if(firstLeft == -1) {
                firstLeft = arr[i].x;
                prevLeftX = arr[i].x;
                prevColor = arr[i].color;
                sumColors += arr[i].color;
                sumColors %= k;
                continue;
            }

            // Rotate array equal to our color
            ll shift = arr[i].color;
            for(ll j = 0; j < shift; ++j) {
                soham.push_front(soham.back());
                soham.pop_back();
            }

            // Add the distance to this ant into our array
            soham[arr[i].color] += (arr[i].x - prevLeftX)/2;

            // Set all previous values
            prevLeftX = arr[i].x;
            prevColor = arr[i].color;
            sumColors = (sumColors+arr[i].color)%k;
        }

        // If it's going left
        else {
            // If it's the first left, add it and continue
            if(prevLeftX == 0) {
                totalDist[arr[i].color] += arr[i].x;
                continue;
            }

            // Add distance between
            totalDist[arr[i].color] += (arr[i].x - prevLeftX)/2;

            // For each color it will be, add the distance for that color
            ll currColor = arr[i].color;
            for(ll j = 0; j < k; ++j) {
                totalDist[(currColor+j)%k] += soham[j];
            }

            // Add distance for its final color
            ll middle = (firstLeft+arr[i].x)/2;
            totalDist[(currColor+sumColors)%k] += middle;
        }
    }

    // Print the answer
    for(ll j = 0; j < k; ++j) {
        if(totalDist[j]%2 == 0) {
            cout << totalDist[j]/2 << ".0\n";
        } else {
            cout << totalDist[j]/2 << ".5\n";
        }
    }

    return 0;
}




















