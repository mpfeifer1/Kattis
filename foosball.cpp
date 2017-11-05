#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;

struct dyn {
    string n1;
    string n2;
    int w;
};

int main() {
    int n;
    cin >> n;

    // Read in input
    queue<string> names;
    vector<string> allnames;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        names.push(temp);
        allnames.push_back(temp);
    }
    string results;
    cin >> results;

    // Setup
    string w1, w2, b1, b2;
    w1 = names.front();
    names.pop();
    b1 = names.front();
    names.pop();
    w2 = names.front();
    names.pop();
    b2 = names.front();
    names.pop();

    unordered_map<string, vector<int>> timeplaying;
    for(auto i : allnames) {
        vector<int> v = {0};
        timeplaying[i] = v;
    }

    // Store winners of each game
    vector<dyn> winners;

    char prev = 'A';

    // Simulate
    for(auto i : results) {

        // Set all winstreaks to 0
        for(auto i : allnames) {
            timeplaying[i].push_back(0);
        }

        timeplaying[w1].pop_back();
        timeplaying[w2].pop_back();
        timeplaying[b1].pop_back();
        timeplaying[b2].pop_back();
        timeplaying[w1].push_back(timeplaying[w1].back()+1);
        timeplaying[w2].push_back(timeplaying[w2].back()+1);
        timeplaying[b1].push_back(timeplaying[b1].back()+1);
        timeplaying[b2].push_back(timeplaying[b2].back()+1);

        dyn win;
        if(i == prev) {
            win.w = winners[winners.size()-1].w + 1;
        }
        else {
            win.w = 1;
        }

        if(i == 'W') {
            win.n1 = w1;
            win.n2 = w2;

            swap(w1, w2);

            names.push(b2);
            b2 = b1;
            b1 = names.front();
            names.pop();
            prev = 'W';
        }
        if(i == 'B') {
            win.n1 = b1;
            win.n2 = b2;

            swap(b1, b2);

            names.push(w2);
            w2 = w1;
            w1 = names.front();
            names.pop();
            prev = 'B';
        }

        /*
        // Set all winstreaks to 0
        for(auto i : allnames) {
            timeplaying[i].push_back(0);
        }

        timeplaying[w1].pop_back();
        timeplaying[w2].pop_back();
        timeplaying[b1].pop_back();
        timeplaying[b2].pop_back();
        timeplaying[w1].push_back(timeplaying[w1].back()+1);
        timeplaying[w2].push_back(timeplaying[w2].back()+1);
        timeplaying[b1].push_back(timeplaying[b1].back()+1);
        timeplaying[b2].push_back(timeplaying[b2].back()+1);
        */

        winners.push_back(win);
    }

    // Find max
    int best = 0;
    for(auto i : winners) {
        best = max(best, i.w);
    }

    // Print results
    for(int i = 0; i < winners.size(); i++) {
        if(winners[i].w == best) {
            string winner1 = winners[i-best+1].n1 ;
            string winner2 = winners[i-best+1].n2 ;
            int t1 = timeplaying[winner1][i];
            int t2 = timeplaying[winner2][i];
            if(t1 >= t2) {
                cout << winner1 << " " << winner2 << endl;
            }
            else {
                cout << winner2 << " " << winner1 << endl;
            }
        }
    }
}

