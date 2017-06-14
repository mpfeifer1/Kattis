#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int getDist(char a, char b, vector<string>& keyboard) {
    int ax, ay, bx, by;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < keyboard[0].size(); j++) {
            if(keyboard[i][j] == a) {
                ax = j;
                ay = i;
            }
            if(keyboard[i][j] == b) {
                bx = j;
                by = i;
            }
        }
    }

    return abs(ax-bx) + abs(ay-by);
}

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> distances;

    vector<string> keyboard = {"qwertyuiop",
                               "asdfghjkl",
                               "zxcvbnm"};

    for(char i = 'a'; i <= 'z'; i++) {
        for(char j = 'a'; j <= 'z'; j++) {
            int dist = getDist(i, j, keyboard);
            string temp;
            temp.push_back(i);
            temp.push_back(j);

            distances[temp] = dist;
        }
    }

    for(int k = 0; k < n; k++) {
        string word;
        cin >> word;

        int num;
        cin >> num;

        vector<string> words;
        for(int i = 0; i < num; i++) {
            string temp;
            cin >> temp;

            words.push_back(temp);
        }

        vector<pair<int, string>> sortable;

        for(int i = 0; i < num; i++) {
            int dist = 0;

            for(int j = 0; j < word.length(); j++) {
                string search;
                search.push_back(word[j]);
                search.push_back(words[i][j]);

                dist += distances[search];
            }

            sortable.push_back({dist, words[i]});
        }

        sort(sortable.begin(), sortable.end());

        for(auto s : sortable) {
            cout << s.second << " " << s.first << endl;
        }
    }
}
