#include <iostream>

using namespace std;


int s1(int n) {
    int total = 0;
    for(int i = 0; i <= n; i++) {
        total += i;
    }
    return total;
}

int s2(int n) {
    int total = 0;
    for(int i = 1; i < 2*n; i+=2) {
        total += i;
    }
    return total;
}

int s3(int n) {
    int total = 0;
    for(int i = 0; i < 2*n+1; i+=2) {
        total += i;
    }
    return total;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cin >> temp;

        cout << i+1 << " " << s1(temp) << " " << s2(temp) << " " << s3(temp) << endl;
    }
}
