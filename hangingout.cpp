#include <iostream>

using namespace std;

int main() {
    int total, queries;
    cin >> total >> queries;

    int rejected = 0;
    int current = 0;
    for(int i = 0; i < queries; i++) {
        string s;
        int size;

        cin >> s >> size;

        if(s == "enter") {
            if(current + size > total) {
                rejected++;
            }
            else {
                current += size;
            }
        }
        else {
            current -= size;
        }
    }

    cout << rejected << endl;
}
