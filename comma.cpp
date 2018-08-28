#include <bits/stdc++.h>

using namespace std;

int main() {
    string complete;
    getline(cin, complete);

    stringstream ss(complete);

    // Set too slow???
    int count = 0;

    // Define conversion
    map<string, int> word_int;
    map<int, string> int_word;

    // Define adjacency matrix
    map<int,set<int>> b_e;
    map<int,set<int>> e_b;

    // Define whether they begin/end in commas
    vector<bool> b_comma;
    vector<bool> e_comma;

    // Process input
    string curr = ".";
    string next = ".";
    do {
        // Check for comma + period
        bool hascomma = false;
        bool hasperiod = false;
        if(curr.back() == ',' || curr.back() == '.') {
            if(curr.back() == ',') hascomma = true;
            if(curr.back() == '.') hasperiod = true;
            curr.pop_back();
        }

        // Add word to dictionary if it doesn't exist
        if(word_int.count(curr) == 0) {
            word_int[curr] = count;
            int_word[count] = curr;
            b_comma.push_back(false);
            e_comma.push_back(false);
            count++;
        }

        // Remove extra chars
        string tempnext = next;
        if(next.back() == ',' || next.back() == '.') {
            tempnext.pop_back();
        }

        // Add word to dictionary if it doesn't exist
        if(word_int.count(tempnext) == 0) {
            word_int[tempnext] = count;
            int_word[count] = tempnext;
            b_comma.push_back(false);
            e_comma.push_back(false);
            count++;
        }

        // Figure out edges
        int curridx = word_int[curr];
        int nextidx = word_int[tempnext];

        // Add to start point of BFS
        if(hascomma) {
            b_comma[nextidx] = true;
            e_comma[curridx] = true;
        }

        // Add edges
        if(!hasperiod) {
            b_e[nextidx].insert(curridx);
            e_b[curridx].insert(nextidx);
        }

        // Slide window
        curr = next;
    } while(ss >> next);



    // Find all words beginning/ending in commas
    queue<int> b;
    queue<int> e;

    // Loop through and add anything necessary to the queue
    for(int i = 0; i < count; i++) {
        if(b_comma[i]) {
            b.push(i);
        }
        if(e_comma[i]) {
            e.push(i);
        }
    }

    // Do an alternating BFS
    while(!b.empty() || !e.empty()) {
        // BFS, add to E
        while(!b.empty()) {
            int curr = b.front();
            b.pop();

            for(auto c : b_e[curr]) {
                if(!e_comma[c]) {
                    e_comma[c] = true;
                    e.push(c);
                }
            }
        }

        // BFS, add to B
        while(!e.empty()) {
            int curr = e.front();
            e.pop();

            for(auto c : e_b[curr]) {
                if(!b_comma[c]) {
                    b_comma[c] = true;
                    b.push(c);
                }
            }
        }
    }



    // Loop through all words, adding commas where necessary
    stringstream ss2(complete);
    string print;

    // Print out all words
    bool begin = true;
    while(ss2 >> print) {
        // Print space if necessary
        if(!begin) {
            cout << " ";
        }
        begin = false;

        // Print word
        cout << print;

        // If already punctuated, done
        if(print.back() == '.' || print.back() == ',') {
            continue;
        }

        // If not punctuated, check if it needs it
        if(e_comma[word_int[print]]) {
            cout << ",";
        }
    }
    cout << endl;
}
