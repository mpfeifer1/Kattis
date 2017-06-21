#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    v.resize(8, 0);

    vector<int> finished = {1,2,4,6,10,12,16,18};

    for(int i = 0; i < 8; i++) {
        cin >> v[i];
    }

    int steps = 0;

    while(v[7] < 18) {
        steps += 510510;
        v[7]++;
    }

    while(v != finished) {
        steps++;
        v[0]++;
        if(v[0] == 2) {
            v[0]=0;
            v[1]++;
        }
        if(v[1] == 3) {
            v[1]=0;
            v[2]++;
        }
        if(v[2] == 5) {
            v[2]=0;
            v[3]++;
        }
        if(v[3] == 7) {
            v[3]=0;
            v[4]++;
        }
        if(v[4] == 11) {
            v[4]=0;
            v[5]++;
        }
        if(v[5] == 13) {
            v[5]=0;
            v[6]++;
        }
        if(v[6] == 17) {
            v[6]=0;
            v[7]++;
        }
    }

    cout << steps << endl;
}
