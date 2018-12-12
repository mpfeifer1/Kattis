#include <bits/stdc++.h>

using namespace std;

void rot(string& s, int i) {
    if(i < 1 || i > 8) return;
    s[i]++;
    if(s[i] > 'F') s[i] = 'A';
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    s1 = ' ' + s1;
    s2 = ' ' + s2;

    if(s1 == s2) {
        cout << 0 << endl;
        return 0;
    }

    map<string,int> dist;
    queue<string> q;
    dist[s1] = 0;
    q.push(s1);

    while(!q.empty()) {
        string curr = q.front();
        q.pop();

        if(curr == s2) {
            cout << dist[s2] << endl;
            return 0;
        }

        // For each character, apply its rule
        for(int i = 1; i <= 8; i++) {
            string next = curr;

            if(curr[i] == 'A') {
                rot(next, i-1);
                rot(next, i+1);
            }

            else if(curr[i] == 'B') {
                if(1 < i && i < 8) {
                    next[i+1] = next[i-1];
                }
            }

            else if(curr[i] == 'C') {
                rot(next, 9-i);
            }

            else if(curr[i] == 'D') {
                int ci = i;
                if(i <= 4) {
                    i--;
                    while(i > 0) {
                        rot(next,i);
                        i--;
                    }
                }
                else {
                    i++;
                    while(i <= 8) {
                        rot(next,i);
                        i++;
                    }
                }
                i = ci;
            }

            else if(curr[i] == 'E') {
                if(1 < i && i < 8) {
                    int diff = min(8-i,i-1);
                    rot(next,i+diff);
                    rot(next,i-diff);
                }
            }

            else if(curr[i] == 'F') {
                if(i % 2 == 1) {
                    rot(next, (i+9)/2);
                }
                else {
                    rot(next, i/2);
                }
            }

            if(!dist.count(next)) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}
