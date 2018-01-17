#include <bits/stdc++.h>

using namespace std;
#define umap unordered_map

bool is_bfs(vector<pair<int,string>>* adj, int start, int target) {
    umap<int, string> visited;

    queue<int> is_q;
    is_q.push(start);
    visited[start] = "is-a";

    while(!is_q.empty()) {
        int curr;
        curr = is_q.front();
        is_q.pop();

        for(auto next : adj[curr]) {
            if(visited[next.first] == "is-a") {
                continue;
            }
            if(next.second == "is-a") {
                visited[next.first] = "is-a";
                is_q.push(next.first);
            }
        }
    }

    return (visited.count(target) && visited[target] == "is-a");
}

bool has_bfs(vector<pair<int,string>>* adj, int start, int target) {
    umap<int, string> visited;

    queue<int> is_q;
    queue<int> has_q;

    has_q.push(start);

    while(!is_q.empty() || !has_q.empty()) {
        int curr;
        if(!has_q.empty()) {
            curr = has_q.front();
            has_q.pop();
        }
        else {
            curr = is_q.front();
            is_q.pop();
        }

        for(auto next : adj[curr]) {
            if(visited[next.first] == "has-a") {
                continue;
            }
            else if(visited[next.first] == "is-a") {
                if(visited[curr] == "has-a" || next.second == "has-a") {
                    visited[next.first] = "has-a";
                    has_q.push(next.first);
                }
            }
            else {
                if(visited[curr] == "has-a" || next.second == "has-a") {
                    visited[next.first] = "has-a";
                    has_q.push(next.first);
                }
                else {
                    visited[next.first] = "is-a";
                    is_q.push(next.first);
                }
            }
        }
    }

    return (visited.count(target) && visited[target] == "has-a");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, string>> adj[501];
    for(int i = 0; i < 501; i++) {
        adj[i] = {};
    }

    int unique = 0;
    unordered_map<string, int> conv;

    for(int i = 0; i < n; i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        if(conv.count(s1) == 0) {
            conv[s1] = unique;
            unique++;
        }

        if(conv.count(s3) == 0) {
            conv[s3] = unique;
            unique++;
        }

        adj[conv[s1]].push_back({conv[s3], s2});
    }

    for(int i = 1; i <= m; i++) {
        cout << "Query " << i << ": ";

        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        if(conv.count(s1) == 0) {
            conv[s1] = unique;
            unique++;
        }

        if(conv.count(s3) == 0) {
            conv[s3] = unique;
            unique++;
        }

        bool works;
        if(s2 == "is-a") {
            works = is_bfs(adj, conv[s1], conv[s3]);
        }
        else {
            works = has_bfs(adj, conv[s1], conv[s3]);
        }

        if(works) {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }

    }
}

