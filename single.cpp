#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll n, w, h;

vector<pair<pair<ll,ll>,pair<ll,ll>>> segments;
vector<pair<ll,ll>> converted;

ll conv(pair<ll,ll> p) {
    if(p.first == 0) {
        return p.second;
    }
    if(p.second == h) {
        return h + p.first;
    }
    if(p.first == w) {
        return h + w + (h-p.second);
    }
    if(p.second == 0) {
        return h + w + h + (w-p.first);
    }
}

pair<ll,ll> unconv(ll i) {
    if(i < h) {
        return {0,i};
    }
    if(i < h+w) {
        i -= h;
        return {i,h};
    }
    if(i < h+w+h) {
        i -= h;
        i -= w;
        return {w,h-i};
    }
    i -= h;
    i -= w;
    i -= h;
    return {w-i,0};
}

pair<ld,ld> push(pair<ll,ll>& p) {
    pair<ld,ld> t;
    t = {p.first,p.second};

    if(p.first == 0 && p.second == 0) return {0,.5};
    if(p.first == 0 && p.second == h) return {.5,h};
    if(p.first == w && p.second == h) return {w,h-.5};
    if(p.first == w && p.second == 0) return {w-.5,0};

    if(p.first == 0) {
        t.second += .5;
        return t;
    }
    if(p.second == h) {
        t.first += .5;
        return t;
    }
    if(p.first == w) {
        t.second -= .5;
        return t;
    }
    if(p.second == 0) {
        t.first -= .5;
        return t;
    }
}

int main() {
    cout << fixed;
    cout.precision(1);
    cin >> n >> w >> h;

    // Read in all coordinates
    segments.resize(n);
    for(auto& i : segments) {
        cin >> i.first.first >> i.first.second >>
               i.second.first >> i.second.second;
    }

    // Convert them to an integer position on a line
    for(auto i : segments) {
        converted.push_back({conv(i.first), conv(i.second)});
    }

    // Make sure their lower val is before the higher
    for(auto& i : converted) {
        if(i.second < i.first) {
            swap(i.first,i.second);
        }
    }

    // Edge case 1 segment
    if(n == 1) {
        cout << "1" << endl;
        pair<ll,ll> p1 = segments[0].first;
        pair<ll,ll> p2 = segments[0].second;

        pair<ld,ld> t1 = push(p1);
        pair<ld,ld> t2 = push(p2);

        cout << t1.first << " " << t1.second << " " << t2.first << " " << t2.second << endl;

        return 0;
    }

    bool works = false;

    // Compress all the converted vals
    vector<ll> all;
    for(auto i : converted) {
        all.push_back(i.first);
        all.push_back(i.second);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    map<ll,ll> compress;
    for(ll i = 0; i < all.size(); i++) {
        compress[all[i]] = i;
    }

    // Prepare the converted vals for a two pointer walk
    vector<set<ll>> add(compress.size()+2);
    vector<set<ll>> rem(compress.size()+2);
    for(ll i = 0; i < converted.size(); i++) {
        add[compress[converted[i].first]].insert(i);
        rem[compress[converted[i].second]].insert(i);
    }
    ll ptr1 = -1;
    ll ptr2 = -1;

    // For each segment, holds how many pointers are in its range
    vector<ll> cntseg(segments.size(),0);

    // Run two pointer walk
    ll ones = 0;
    while(ptr1 < ll(compress.size())) {

        // Advance the first pointer
        ptr1++;
        set<ll> zero;
        for(auto i : rem[ptr1]) {
            cntseg[i]--;
            if(cntseg[i] == 1) ones++;
            if(cntseg[i] != 1) ones--;

            if(cntseg[i] != 1) zero.insert(i);
        }
        for(auto i : add[ptr1]) {
            cntseg[i]++;
            if(cntseg[i] == 1) ones++;
            if(cntseg[i] != 1) ones--;
        }

        while(!zero.empty() && ptr2 < ll(converted.size())) {
            // Advance the second pointer
            ptr2++;
            for(auto i : rem[ptr2]) {
                cntseg[i]--;
                if(cntseg[i] == 1) ones++;
                if(cntseg[i] != 1) ones--;

            }
            for(auto i : add[ptr2]) {
                cntseg[i]++;
                if(cntseg[i] == 1) ones++;
                if(cntseg[i] != 1) ones--;
                zero.erase(i);
            }
        }

        if(ptr2 < ptr1 && ones == converted.size()) {
            works = true;
            break;
        }
    }

    // If we can do it with one line, use that line
    if(works) {
        cout << "1" << endl;
        // Find the answer

        ll c1 = 0;
        ll c2 = 0;

        if(ptr1 != -1) {
            c1 = all[ptr1];
        }
        if(ptr2 != -1) {
            c2 = all[ptr2];
        }

        pair<ll,ll> p1 = unconv(c1);
        pair<ll,ll> p2 = unconv(c2);

        if(p1.first == p2.first) {
            if(p1.second > p2.second) {
                swap(p1,p2);
            }

            if(p1.first == 0) {
                p2.second = h;
            }
            else {
                p1.second = 0;
            }
            
        }

        if(p1.second == p2.second) {
            if(p1.first > p2.first) {
                swap(p1,p2);
            }
            if(p1.second == 0) {
                p1.first = 0;
            }
            else {
                p2.first = w;
            }
        }

        pair<ld,ld> t1 = push(p1);
        pair<ld,ld> t2 = push(p2);

        cout << t1.first << " " << t1.second << " " << t2.first << " " << t2.second << endl;
    }

    // Otherwise, use the two "corners"
    else {
        cout << "2" << endl;
        cout << "0.5 0 " << w-0.5 << " " << h << endl;
        cout << "0.5 " << h << " " << w-0.5 << " 0" << endl;
    }
}
