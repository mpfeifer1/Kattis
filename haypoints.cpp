#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    map<string, int> values;

    for(int i = 0; i < m; i++) {
        string word;
        int value;
        cin >> word;
        cin >> value;

        values[word] = value;
    }

    for(int i = 0; i < n; i++) {
        int score = 0;
        string word;
        while(cin >> word && word != ".") {
            score += values[word];
        }
        cout << score << endl;
    }
}
