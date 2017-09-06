#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<int> stars, int width) {
    int skip = 0;
    int fill = 0;
    for(auto num : stars) {
        skip += num;
        for(int i = 0; i < width - skip; i++) {
            cout << ".";
        }
        for(int i = 0; i < num; i++) {
            cout << "*";
        }
        for(int i = 0; i < fill; i++) {
            cout << ".";
        }
        cout << endl;
        fill += num;
    }
    cout << endl;
}

int main() {
    string line;
    vector<int> stars;
    int width = 0;
    while(getline(cin, line)) {
        if(line == "") {
            print(stars, width);
            stars.clear();
        }
        else {
            width = line.length();
            int linestars = 0;
            for(auto c : line) {
                if(c == '*') {
                    linestars++;
                }
            }
            stars.push_back(linestars);
        }
    }
    print(stars, width);
}
