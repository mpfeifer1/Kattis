#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct chain {
    long long gcd;
    long long length;
};

int main() {
    long long n;
    cin >> n;

    for(long long i = 0; i < n; i++) {
        long long size;
        cin >> size;

        queue<long long> q;

        for(int j = 0; j < size; j++) {
            long long temp;
            cin >> temp;
            q.push(temp);
        }

        vector<chain> ch;

        long long maximum = 0;

        while(!q.empty()) {
            long long num = q.front();
            q.pop();

            maximum = max(num, maximum);
            for(long long k = 0; k < ch.size(); k++) {
                ch[k].gcd = __gcd(ch[k].gcd, num);
                ch[k].length++;
                maximum = max(ch[k].gcd*ch[k].length, maximum);
            }

            chain temp = {num, 1};
            ch.push_back(temp);

            for(long long k = 1; k < ch.size(); k++) {
                if(ch[k-1].gcd == ch[k].gcd) {
                    ch.erase(ch.begin()+k);
                    k-=2;
                }
            }
        }

        cout << maximum << endl;
    }
}
